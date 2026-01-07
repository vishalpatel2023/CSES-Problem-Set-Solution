/**
 *    author:  vishal
 *    created: 12.10.2024
**/
 
#include <bits/stdc++.h>
using namespace std;
 
#define max3(a,b,c) max(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(d,c))
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(min(a,b),min(d,c))
#define MIN(arr, n) (*min_element(arr, arr + n))
#define MAX(arr, n) (*max_element(arr, arr + n))
 
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
#define matout(a,b,arr){for(int i=0; i<a; i++){for(int j=0; j<b; j++){cout<<arr[i][j]<<" ";}cout<<endl;}}
#define sum(arr, n) accumulate(arr, arr + n, 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rep2(i, j, a, b, c, d) for(int i = a; i < b; i++) for(int j = c; j < d; j++)
#define debug(x) cerr << "Debug: " << #x << " = " << (x) << endl;
#define ll long long
#define MOD ((int)(1e9 + 7))
 
void dfs(vector<int> adj[],vector<int>& vis,int x){
    //base case
 
    vis[x] = 1; //mark x as a visited
    for(int i : adj[x]){
        if(!vis[i]){
            dfs(adj,vis,i);
        }
    }
 
}
void solve(){
    int n,m;
    cin>>n>>m;
 
    vector<int> adj[n+1];
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,0);
    int ans = 0;
    vector<int> tmp;
    rep(i,1,n+1){
        if(!vis[i]){
            dfs(adj,vis,i);
            ans++;
            if(ans>1){
                tmp.push_back(i);
            }
        }
    }
    cout<<ans-1<<endl;
    for(int i=0; i<tmp.size(); i++){
        cout<<1<<" "<<tmp[i]<<endl;
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