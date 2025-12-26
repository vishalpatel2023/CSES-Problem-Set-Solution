
/**
 *    author:  vishal
 *    created: 26.12.2025 15:06
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

//template for sum segment tree

class segmentTree{//0-base indexing follow
    private:
    vector<ll> tree;
    ll n;
    
    ll queryTree(ll node,ll start,ll end, ll l,ll r){
        if(r<start || l>end) return 0;
        if(l<=start && end<=r) return tree[node];

        ll mid = (start+end)/2;
        ll lsm = queryTree(2*node+1,start,mid,l,r);
        ll rsm = queryTree(2*node+2,mid+1,end,l,r);
        return (lsm+rsm);
    }
    void updateTree(ll node,ll start,ll end,ll idx,ll val){
        //incrment by val
        if(start==end){
            tree[node] += val;
        }else{
            ll mid = (start+end)/2;
            if(idx<=mid){
                updateTree(2*node+1,start,mid,idx,val);
            }else{
                updateTree(2*node+2,mid+1,end,idx,val);
            }
            tree[node] = (tree[2*node+1]+tree[2*node+2]);
        }
    }
    public:
    segmentTree(int sz){
        n = sz;
        tree.resize(4*n,0);
    }
    ll query(ll l,ll r){
        return queryTree(0,0,n-1,l,r);
    }
    void update(ll idx,ll val){
        updateTree(0,0,n-1,idx,val);
    }
};


ll get(vector<ll>& arr,ll val){
    return lower_bound(arr.begin(),arr.end(),val)-arr.begin();
}

void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> p(n); in(p,n);
    vector<ll> tmp = p;
    vector<pair<ll,ll>> arr(q);
    vector<char> type(q);

    for(int i=0; i<q; i++){
        char ch; ll a,b;
        cin>>ch>>a>>b;

        type[i] = ch;
        arr[i] = {a,b};

        if(ch=='!'){
            tmp.push_back(b);
            continue;
        }
        tmp.push_back(a);
        tmp.push_back(b);
    }

    sorts(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int mx = tmp.size();

    segmentTree seg(mx);
    for(int i=0; i<n; i++){
        int idx = get(tmp,p[i]);
        seg.update(idx,1);
    }

    for(int i=0; i<q; i++){
        if(type[i]=='?'){
            //query type
            int l = get(tmp,arr[i].first), r = get(tmp,arr[i].second);
            int ans = seg.query(l,r);
            cout<<ans<<endl;
        }else{
            //update
            int k = arr[i].first, x = arr[i].second;
            int old = p[k-1];
            p[k-1] = x;

            seg.update(get(tmp,old),-1);
            seg.update(get(tmp,x),1);
        }
    }
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