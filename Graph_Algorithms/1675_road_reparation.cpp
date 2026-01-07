/**
 *    author:  vishal
 *    created: 20.08.2025 16:38
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
 
vector<int> parent, ranks;
 
void makeSet(int n){
    parent.resize(n);
    ranks.resize(n, 0);
    for (int i=0; i<n; i++) parent[i] = i;
}
 
int findSet(int v){
    if(v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}
 
bool unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a==b) return false;
    if(a != b){
        if (ranks[a]<ranks[b]) swap(a,b);
        parent[b] = a;
        if (ranks[a]==ranks[b]) ranks[a]++;
    }
    return true;
}
 
// void dfs()
void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0; i<m; i++){
        int a,b,c;cin>>a>>b>>c;
        pq.push({-c,{a,b}});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    queue<int> q;q.push(1);
    vector<bool> vis(n+1,false);
    vis[1] = true;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        for(auto y: adj[x]){
            if(!vis[y]){
                q.push(y);
                vis[y] = true;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout<<"IMPOSSIBLE"<<endl;return;
        }
    }
    makeSet(n+1);
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
 
        int xx = x.second.first, yy = x.second.second;
        if(unionSets(xx,yy)){
            ans -= x.first;
        }
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