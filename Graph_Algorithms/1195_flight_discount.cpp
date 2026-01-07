/**
 *    author:  vishal
 *    created: 30.08.2025 15:09
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
#define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rep2(i,j,a,b,c,d) for(int i=a; i<b; i++) for(int j=c; j<d; j++)
#define debug(x) cerr<<"Debug: "<<#x<<" = "<<(x)<< endl;
#define debug2(x, y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define debug3(x, y, z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define ll long long
#define MOD ((int)(1e9+7))
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
 
void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1),adj1(n+1);
    for(int i=0; i<m; i++){
        ll a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj1[b].push_back({a,c});
    }
    vector<ll> c1(n+1,1e15),c2(n+1,1e15);
    set<pair<ll,ll>> q;
    //from 1 to all node
    q.insert({0,1});//cost node
    c1[1] = 0;
    while(!q.empty()){
        auto x = *q.begin(); q.erase(x);
        for(auto y: adj[x.second]){
            if(x.first+y.second<c1[y.first]){
                q.erase({c1[y.first],y.first});
                c1[y.first] = x.first+y.second;
                q.insert({c1[y.first],y.first});
            }
        }
    }
    c2[n] = 0;
 
    //from 1 to all node
    q.insert({0,n});//cost node
    while(!q.empty()){
        auto x = *q.begin(); q.erase(x);
        for(auto y: adj1[x.second]){
            //if x.frist + y.second < c1[y.first]
            if(x.first+y.second<c2[y.first]){
                q.erase({c2[y.first],y.first});
                c2[y.first] = x.first+y.second;
                q.insert({c2[y.first],y.first});
            }
        }
    }
    //reverse all edges
 
    ll ans = 1e16;
    for(int i=1; i<=n; i++){
        for(auto x: adj[i]){
            //i to x edge
            ll tmp1 = x.second/2+c1[i]+c2[x.first];
            ans = min(ans,tmp1);
        }
    }
    cout<<ans<<endl;
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