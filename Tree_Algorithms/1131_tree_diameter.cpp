/**
 *    author:  vishal
 *    created: 17.06.2025 00:27
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
 
ll fun(vector<vector<ll>>& adj,ll& ans,ll node,vector<bool>& vis){
    vis[node] = true;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll mx = 0;
    for(auto x: adj[node]){
        if(!vis[x]){
            ll tmp = 1+fun(adj,ans,x,vis);
            mx = max(mx,tmp);
            if(pq.size()==2){
                if(pq.top()<tmp){
                    pq.pop();
                    pq.push(tmp);
                }
            }else{
                pq.push(tmp);
            }
        }
    }
    ll sm = 0;
    while(!pq.empty()){
        sm += pq.top();
        pq.pop();
    }
    ans = max(ans,sm);
    return mx;
}
 
void solve(){
    ll n;cin>>n;
    vector<vector<ll>> adj(n+1);
    rep(i,0,n-1){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1,false);
    ll ans = 0;
    ll dj = fun(adj,ans,1,vis);
    cout<<ans;
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
    //cout << "Execution time: " << duration.count() << " ms" << endl;
 
    return 0;
}