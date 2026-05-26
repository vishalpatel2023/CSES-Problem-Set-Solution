
/**
 *    author:  vishal
 *    created: 26.05.2026 11:06
**/

//#define NDEBUG //to use assert uncomment this
#include <bits/stdc++.h>
//#include "debugging.h" 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
using namespace std;
//using namespace __gnu_pbds;
using namespace chrono;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> moset;
#define MIN(arr) (*min_element(arr.begin(), arr.end()))
#define MAX(arr) (*max_element(arr.begin(), arr.end()))
#define sorts(arr) sort(arr.begin(),arr.end())

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))

#define set_cnt(n) __builtin_popcountll(n)
#define set_bit(x, i) ((x)|(1LL<<(i))) //ith bit of x to 1
#define clear_bit(x, i) ((x)&~(1LL<<(i))) //unset
#define toggle(x, i) ((x)^(1LL<<(i)))
#define is_set(x, i) ((x)&(1LL<<(i)))
#define is_pow2(x) ((x) && !((x)&((x)-1)))

#define in(arr,n) for(int i=0; i<n; i++){cin>>arr[i];}
#define out(arr,n) for(int i=0; i<n; i++){cout<<arr[i]<<" ";}
#define matout(arr){for(int i=0; i<arr.size(); i++){for(int j=0; j<arr[0].size(); j++){cout<<arr[i][j]<<" ";}cout<<endl;}}
#define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)

#define loop(n) for(ll i=0; i<n; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rep2(i,j,a,b,c,d) for(int i=a; i<b; i++) for(int j=c; j<d; j++)
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << "Debug: " << #x << " = " << (x) << endl;
#define debug2(x, y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define debug3(x, y, z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define ll long long
const ll MOD = 1e9+7;
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vpi = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvpi = vector<vpi>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second

//typedef __int128 int128;//not support cin cout
//#define endl "\n"

class segmentTree {
    vector<ll> t, lz;
    ll n;
    void push(ll node, ll s, ll e) {
        if(lz[node]==0) return;
        t[node]+=(e-s+1)*lz[node];
        if(s!=e) {
            lz[2*node+1]+=lz[node];
            lz[2*node+2]+=lz[node];
        }
        lz[node]=0;
    }
    void build(vector<ll>& arr, ll node, ll s, ll e) {
        if(s==e) {
            t[node]=arr[s];
            return;
        }
        ll mid=s+(e-s)/2;
        build(arr, 2*node+1, s, mid);
        build(arr, 2*node+2, mid+1, e);
        t[node]=t[2*node+1]+t[2*node+2];
    }
    void update(ll node, ll s, ll e, ll l, ll r, ll val) {
        push(node, s, e);
        if(s>r || e<l) return;
        if(s>=l && e<=r) {
            lz[node]+=val;
            push(node, s, e);
            return;
        }
        ll mid=s+(e-s)/2;
        update(2*node+1, s, mid, l, r, val);
        update(2*node+2, mid+1, e, l, r, val);
        t[node]=t[2*node+1]+t[2*node+2];
    }
    void pUpdate(ll node, ll s, ll e, ll idx, ll val) {
        push(node, s, e);
        if(s==e) {
            t[node]=val;
            return;
        }
        ll mid=s+(e-s)/2;
        if(idx<=mid) pUpdate(2*node+1, s, mid, idx, val);
        else pUpdate(2*node+2, mid+1, e, idx, val);
        push(2*node+1, s, mid);
        push(2*node+2, mid+1, e);
        t[node]=t[2*node+1]+t[2*node+2];
    }
    ll query(ll node, ll s, ll e, ll l, ll r) {
        push(node, s, e);
        if(s>r || e<l) return 0;
        if(s>=l && e<=r) return t[node];
        ll mid=s+(e-s)/2;
        return query(2*node+1, s, mid, l, r)+query(2*node+2, mid+1, e, l, r);
    }
public:
    segmentTree(vector<ll>& arr) {
        n=arr.size();
        t.assign(4*n, 0);
        lz.assign(4*n, 0);
        build(arr, 0, 0, n-1);
    }
    void update(ll l, ll r, ll val) { update(0, 0, n-1, l, r, val); }
    void pointUpdate(ll idx, ll val) { pUpdate(0, 0, n-1, idx, val); }
    ll query(ll l, ll r) { return query(0, 0, n-1, l, r); }
};

void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> x(n); in(x,n);

    vector<ll> vals = x;
    sorts(vals);

    vals.erase(unique(vals.begin(),vals.end()),vals.end());

    vector<ll> freq(n+2); //stores frequency
    segmentTree seg(freq);

    vector<ll> ans;
    ll inv = 0;

    for(int i=0; i<k; i++){
        //insert x[i]
        ll val = lower_bound(vals.begin(),vals.end(),x[i])-vals.begin();
        freq[val]++;
        seg.pointUpdate(val,freq[val]);

        ll contri = seg.query(val+1,n+1);
        inv += contri;
    }
    ans.push_back(inv);

    for(int i=k; i<n; i++){
        //delete last and insert current
        //delete i-k
        //how much it contributed? remove it's contribution

        ll val = lower_bound(vals.begin(),vals.end(),x[i-k])-vals.begin();
        freq[val]--;
        seg.pointUpdate(val,freq[val]);

        inv -= seg.query(0,val-1);


        //inset curr
        val = lower_bound(vals.begin(),vals.end(),x[i])-vals.begin();
        freq[val]++;

        seg.pointUpdate(val,freq[val]);

        ll contri = seg.query(val+1,n+1);
        inv += contri;
        ans.push_back(inv);
    }

    // print(contribute,n);cout<<endl;

    print(ans,ans.size());

    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin>>t;
    auto start = high_resolution_clock::now();
    while(t--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    //cout<<"Execution time: "<<duration.count()<<" ms"<<endl;

    return 0;
}