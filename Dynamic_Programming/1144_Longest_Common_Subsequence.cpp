/**
 *    author:  vishal
 *    created: 25.05.2025 14:05
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
    vector<ll> arr(n), brr(m);
    in(arr,n);in(brr,m);
    vector<vector<ll>> dp(n,vector<ll>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //(1 to i) and (1 to j)
            //dp[i][j] = 1+dp[i-1][j-1],dp[i][j-1],dp[i-1][j]
            ll tmp1 = 0,tmp2=0,tmp3=0;
            if(arr[i]==brr[j]){
                tmp1 = 1;
                if(i>=1 && j>=1){
                    tmp1 += dp[i-1][j-1];
                }
            }
            if(i>=1) tmp2 = dp[i-1][j];
            if(j>=1) tmp3 = dp[i][j-1];
            dp[i][j] = max(tmp2,tmp1);
            dp[i][j] = max(dp[i][j],tmp3);
        }
    }
    vector<int> ans;
   
    int x=n-1,y=m-1;
 
    while(x>=0 && y>=0){
        if(arr[x]==brr[y]){
            ans.push_back(arr[x]);
            x--;y--;
        }else{           
            if(x==0) y--;
            else if(y==0) x--;
            else if(dp[x-1][y]>dp[x][y-1]) x--;
            else y--;
        }
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    print(ans,ans.size());
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