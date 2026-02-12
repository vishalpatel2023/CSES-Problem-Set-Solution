/**
 *    author:  vishal
 *    created: 06.01.2026 10:44
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
 
ll get(vector<ll>& arr,ll val){
    return lower_bound(arr.begin(),arr.end(),val)-arr.begin();
}
vector<ll> seg;
 
void update(int l,int r,int idx,int ind,int val){
    if(l==r){
        seg[idx] = val;
        seg[idx] %= MOD;
        return;
    }
    int mid = (l+r)/2;
    if(ind<=mid){
        update(l,mid,2*idx+1,ind,val);
    }else{
        update(mid+1,r,2*idx+2,ind,val);
    }
    seg[idx] = (seg[2*idx+1]+seg[2*idx+2])%MOD;
}
 
ll sm(int l,int r,int idx,int ind){
    //sum from 0 to ind
    if(l>ind) return 0;
    if(r<=ind) return seg[idx];
 
    int mid = (l+r)/2;
    ll ans = sm(l,mid,2*idx+1,ind)+sm(mid+1,r,2*idx+2,ind);
    ans %= MOD;
    return ans;
    
}
void solve(){
    ll n;cin>>n;
    vector<ll> x(n); in(x,n);
    ll ans = 0;
 
    vector<ll> tmp = x;
    sorts(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    ll sz = tmp.size();
    vector<ll> dp(sz);
    seg.resize(4*sz);
 
    for(int i=0; i<n; i++){
        ll val = get(tmp,x[i]);
        //sum from 0 to val-1
        ll sum = sm(0,sz-1,0,val-1);
        dp[val] += sum+1;
        dp[val] %= MOD;
 
        //update at index val--> dp[val]
        update(0,sz-1,0,val,dp[val]);
    }
 
    for(ll x: dp){
        ans = (ans+x)%MOD;
    }
    cout<<ans;
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