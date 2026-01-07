/**
 *    author:  vishal
 *    created: 17.06.2025 01:36
**/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> moset;
#define MIN(arr) (*min_element(arr.begin(), arr.end()))
#define MAX(arr) (*max_element(arr.begin(), arr.end()))
#define sorts(arr) sort(arr.begin(),arr.end())
 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
 
#define set_cnt(n) __builtin_popcount(n)
#define set_bit(x, i) ((x)|(1LL<<(i))) //ith bit of x to 1
#define clear_bit(x, i) ((x)&~(1LL<<(i))) //unset
#define toggle(x, i) ((x)^(1LL<<(i)))
#define is_set(x, i) ((x)&(1LL<<(i)))
#define is_pow2(x) ((x) && !((x)&((x)-1)))
 
#define in(arr,n) for(int i=0; i<n; i++){cin>>arr[i];}
#define out(arr,n) for(int i=0; i<n; i++){cout<<arr[i]<<" ";}
#define matout(arr){for(int i=0; i<arr.size(); i++){for(int j=0; j<arr[0].size(); j++){cout<<arr[i][j]<<" ";}cout<<endl;}}
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rep2(i,j,a,b,c,d) for(int i=a; i<b; i++) for(int j=c; j<d; j++)
#define debug(x) cerr<<"Debug: "<<#x<<" = "<<(x)<< endl;
#define ll long long
#define hello(x) cerr<<"hello"<<(x)<<endl;
#define MOD ((int)(1e9+7))
#define inf (ll)(1e15)
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}
//typedef __int128 int128;//not support cin cout
//#define endl "\n"
 
ll fun(vector<vector<ll>>& adj,int node,vector<ll>& tmp,vector<bool>& vis){
    vis[node] = true;
    ll ans = 1;
    for(auto x: adj[node]){
        if(!vis[x]){
            ans += fun(adj,x,tmp,vis);
        }
    }
    tmp[node] = ans;
    return ans;
}
ll compute(vector<vector<ll>>& adj,int node,vector<bool>& vis,vector<ll>& tmp){
    vis[node] = true;
    ll ans = 0;
    for(auto x: adj[node]){
        if(!vis[x]){
            ans += tmp[x]+compute(adj,x,vis,tmp);
        }
    }
    return ans;
}
 
void fun2(vector<vector<ll>>& adj,int node,vector<ll>& tmp,vector<ll>& anss,vector<bool>& vis,ll val){
    vis[node] = true;
    ll n = vis.size()-1;
    //ll ans = 1;
    for(auto x: adj[node]){
        if(!vis[x]){
            fun2(adj,x,tmp,anss,vis,val-tmp[x]+(n-tmp[x]));
        }
    }
    anss[node] = val;
}
 
void solve(){
    ll n;cin>>n;
    vector<vector<ll>> adj(n+1);
    rep(i,0,n-1){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> tmp(n+1,0);
    vector<bool> vis(n+1,false);
    fun(adj,1,tmp,vis);
    vector<ll> ans(n+1);
    //compute ans for node 1
    rep(i,1,n+1) vis[i] = false;
    ll dj = compute(adj,1,vis,tmp);
    rep(i,1,n+1) vis[i] = false;
    fun2(adj,1,tmp,ans,vis,dj);
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin>>t;
    auto start = high_resolution_clock::now();
    while(t--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    //cout<<"Execution time: "<<duration.count()<<" ms"<<endl;
 
    return 0;
}