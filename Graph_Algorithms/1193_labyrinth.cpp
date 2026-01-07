/**
 *    author:  vishal
 *    created: 10.05.2025 23:06
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
 
void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m)),dir(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    map<pair<int,int>,pair<int,int>> par;//i will store parent of each coord
    int dx,dy,stx,sty;
    rep(i,0,n){
        rep(j,0,m){
            cin>>arr[i][j];
            if(arr[i][j]=='A'){
                q.push({i,j});
                par[{i,j}] = {-1,-1};
                vis[i][j] = true;
                stx=i;
                sty=j;
            }else if(arr[i][j]=='B'){
                dx=i;
                dy = j;
            }else if(arr[i][j]=='#'){
                vis[i][j] = true;
            }
        }
    }
    bool path = false;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        //debug(x.first) debug(x.second)
        if(x.first+1<n){
            //means mmove D
            if(!vis[x.first+1][x.second]){
                q.push({x.first+1,x.second});
                par[{x.first+1,x.second}] = {x.first,x.second};
                vis[x.first+1][x.second] = true;
                dir[x.first+1][x.second] = 'D';
 
                if(arr[x.first+1][x.second]=='B'){
                    path = true;
                    break;
                }
            }
        }
        if(x.first-1>=0){
            //means mmove U
            if(!vis[x.first-1][x.second]){
                q.push({x.first-1,x.second});
                par[{x.first-1,x.second}] = {x.first,x.second};
                vis[x.first-1][x.second] = true;
                dir[x.first-1][x.second] = 'U';
 
                if(arr[x.first-1][x.second]=='B'){
                    path = true;
                    break;
                }
            }
        }
        if(x.second+1<m){
            //means mmove R
            if(!vis[x.first][x.second+1]){
                q.push({x.first,x.second+1});
                par[{x.first,x.second+1}] = {x.first,x.second};
                vis[x.first][x.second+1] = true;
                dir[x.first][x.second+1] = 'R';
 
                if(arr[x.first][1+x.second]=='B'){
                    path = true;
                    break;
                }
            }
        }
        if(x.second-1>=0){
            //means mmove L
            if(!vis[x.first][x.second-1]){
                q.push({x.first,x.second-1});
                par[{x.first,x.second-1}] = {x.first,x.second};
                vis[x.first][x.second-1] = true;
                dir[x.first][x.second-1] = 'L';
 
                if(arr[x.first][x.second-1]=='B'){
                    path = true;
                    break;
                }
            }
        }
        // debug("gap1")
        // for(auto x: par){
        //     cout<<x.first.first<<" "<<x.first.second<<"-->"<<x.second.first<<" "<<x.second.second<<endl;
        // }
        // debug("gap2")
        
    }
    //debug("hello")
    if(!path){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    string ans;
    // for(auto x: par){
    //     cout<<x.first.first<<" "<<x.first.second<<"-->"<<x.second.first<<" "<<x.second.second<<endl;
    // }
    pair<int,int> curr = {dx,dy};
    while((curr.first != stx) || (curr.second != sty)){
        ans += dir[curr.first][curr.second];
        curr = par[curr];
        //cout<<curr.first<<" "<<curr.second<<endl;
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    
    //cout<<endl;
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