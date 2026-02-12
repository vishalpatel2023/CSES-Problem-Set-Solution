/**
 *    author:  vishal
 *    created: 10.03.2025 18:43
**/
 
#include <bits/stdc++.h>
using namespace std;
#define MIN(arr, n) (*min_element(arr.begin(), arr.end()))
#define MAX(arr, n) (*max_element(arr.begin(), arr.end()))
 
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
#define sum(arr, n) accumulate(arr.begin(), arr.end(), 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rep2(i, j, a, b, c, d) for(int i = a; i < b; i++) for(int j = c; j < d; j++)
#define debug(x) cerr << "Debug: " << #x << " = " << (x) << endl;
#define ll long long
#define hello(x) cerr<<"hello"<<(x)<<endl;
#define MOD ((int)(1e9 + 7))
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}
//typedef __int128 int128;//not support cin cout
 
void solve(){
    ll n;cin>>n;
    vector<ll> arr(n);in(arr,n);
    ll sm = sum(arr,n);
    vector<vector<bool>> dp(n,vector<bool>(sm+1));
    dp[0][arr[0]] = true;
    for(int i=0; i<n; i++) dp[i][0] = true;
    for(int i=1; i<n; i++){
        for(int j=1; j<=sm; j++){
            //you have 0 to i coins
            //use previoua row
            bool tmp = false;
            if(arr[i]<=j){
                tmp = dp[i-1][j-arr[i]];
            }
            dp[i][j] = (tmp || dp[i-1][j]); //dp[i-1][j];
        }
    }
    int sz=0;
    for(int i=1; i<=sm; i++){
        if(dp[n-1][i]){
            sz++;
        }
    }
    cout<<sz<<endl;
    for(int i=1; i<=sm; i++){
        if(dp[n-1][i]){
            cout<<i<<" ";
        }
    }
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