/**
 *    author:  vishal
 *    created: 30.05.2025 15:55
**/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> moset;
#define MIN(arr) (*min_element(arr.begin(), arr.end()))
#define MAX(arr) (*max_element(arr.begin(), arr.end()))
#define sorts(arr) sort(arr.begin(),arr.end())
 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a * (b / gcd(a,b)))
 
#define set_cnt(n) __builtin_popcount(n)
#define set_bit(x, i) ((x) | (1LL << (i))) //ith bit of x to 1
#define clear_bit(x, i) ((x) & ~(1LL << (i))) //unset
#define toggle(x, i) ((x) ^ (1LL << (i)))
#define is_set(x, i) ((x) & (1LL << (i)))
#define is_pow2(x) ((x) && !((x) & ((x) - 1)))
 
#define in(arr,n) for(int i=0; i<n; i++){cin>>arr[i];}
#define out(arr,n) for(int i=0; i<n; i++){cout<<arr[i]<<" ";}
#define matout(arr){for(int i=0; i<arr.size(); i++){for(int j=0; j<arr[0].size(); j++){cout<<arr[i][j]<<" ";}cout<<endl;}}
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rep2(i, j, a, b, c, d) for(int i = a; i < b; i++) for(int j = c; j < d; j++)
#define debug(x) cerr << "Debug: " << #x << " = " << (x) << endl;
#define ll long long
#define hello(x) cerr<<"hello"<<(x)<<endl;
#define MOD ((int)(1e9 + 7))
#define inf (ll)(1e15)
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}
//typedef __int128 int128;//not support cin cout
//#define endl "\n"
vector<ll> par;
vector<ll> sz;
multiset<int> mst;
 
ll parent(ll a){
    while(par[a]!=a){
        a = par[a];
    }
    return a;
}
 
bool unionn(ll a,ll b){
    ll p1 = parent(a),p2=parent(b);
    if(p1 != p2){
        if(sz[p1]<sz[p2]){
            par[p1] = p2; 
            mst.erase(mst.find(sz[p2]));
            sz[p2] += sz[p1];
            mst.erase(mst.find(sz[p1]));
            mst.insert(sz[p2]);
        }else{
            mst.erase(mst.find(sz[p1]));
            par[p2] = p1;
            sz[p1] += sz[p2];
            mst.erase(mst.find(sz[p2]));
            mst.insert(sz[p1]);
        }
        return true;
    }
    return false;
}
 
 
void solve(){
    ll n,m;cin>>n>>m;
    par.resize(n+1);
    sz.resize(n+1,1);
    ll compo = n;
    rep(i,0,n) mst.insert(1);
    rep(i,0,n+1) par[i] = i;
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        bool check = unionn(a,b);
        if(check) compo--;
 
        cout<<compo<<" "<<*(--mst.end())<<endl;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
 
    return 0;
}