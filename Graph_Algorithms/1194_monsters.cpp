/**
 *    author:  vishal
 *    created: 11.05.2025 20:06
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
 
 
bool safe(vector<vector<char>>& arr,int x,int y,vector<vector<bool>>& vis){
    if(x<0 || y<0 || x>=arr.size() || y>=arr[0].size() || vis[x][y]==true || arr[x][y]=='#') return false;
    return true;
}
void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    vector<vector<char>> dir(n,vector<char>(m));//for dir
    //push all M in queue
    //store the locations of A
    //create a 2d array distance and update the distance according to msbfs
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int>(m,1e9));//dist matrix
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int xx,yy;//pos of A
    rep(i,0,n){
        rep(j,0,m){
            cin>>arr[i][j];
            if(arr[i][j]=='M'){
                q.push({i,j});
                vis[i][j] = true;
                dist[i][j]=0;
            }else if(arr[i][j]=='A'){
                xx=i;
                yy=j;
            }
        }
    }
    
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    char direct[] = {'D','L','U','R'};
    //int curr = 0;
    
    if(xx==0 || yy==0 || xx==n-1 || yy==m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;return;
    }
    
    while(!q.empty()){
        auto x = q.front();
        q.pop();
 
        //explore adjacent
        for(int i=0; i<4; i++){
            int ux = x.first+dx[i],uy=x.second+dy[i];
            if(safe(arr,ux,uy,vis)){
                dist[ux][uy] = dist[x.first][x.second]+1;
                vis[ux][uy] = true;
                q.push({ux,uy});
            }
        }
    }
    queue<tuple<int,int,int>> qq;
    qq.push({xx,yy,0});
    rep(i,0,n){
        rep(j,0,m){
            vis[i][j] = false;
        }
    }
    vis[xx][yy] = true;
    int ex=-1,ey=-1;
    bool check = false;
    while(!qq.empty()){
        auto x = qq.front();
        qq.pop();
    
        //explore adjacent
        for(int i=0; i<4; i++){
            int ux = get<0>(x)+dx[i],uy=get<1>(x)+dy[i];
            
            if(safe(arr,ux,uy,vis) && dist[ux][uy]>(get<2>(x)+1)){
                vis[ux][uy] = true;
                qq.push({ux,uy,get<2>(x)+1});
                dir[ux][uy]=direct[i];
                if(ux==0 || ux==n-1 || uy==0 || uy==m-1){
                    check = true;
                    ex = ux;
                    ey = uy;
                    break;
                }
            }
        }
        if(check) break;
    }   
    if(ex==-1 || ey==-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    string ans;
    
    while((ex != xx || ey != yy)){
        char c = dir[ex][ey];
        ans += c;
        if(c=='D'){
            ex--;
        }else if(c=='U'){
            ex++;
        }else if(c=='L'){
            ey++;
        }else if(c=='R'){
            ey--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    cout<<ans;
    cout<<endl;
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