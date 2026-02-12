/**
 *    author:  vishal
 *    created: 24.04.2025 10:11
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
 
int fun(string& s,string& t,int x,int y,vector<vector<int>>& dp){
    //base case
    if(x<0 && y<0) return 0;
    if(x<0) return y+1;
    if(y<0) return x+1;
 
    if(dp[x][y] != -1) return dp[x][y];
    int ans = 1e9;
    if(s[x]==t[y]){
        ans = fun(s,t,x-1,y-1,dp);
    }else{
        //replace
        ans = min(ans,1+fun(s,t,x-1,y-1,dp));
        //delete
        ans = min(ans,1+fun(s,t,x-1,y,dp));
        //insert
        ans = min(ans,1+fun(s,t,x,y-1,dp));
    }
    return dp[x][y]=ans;
}
void solve(){
    string s,t;cin>>s>>t;
    int n1 = s.length(),n2=t.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    int ans = fun(s,t,n1-1,n2-1,dp);
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