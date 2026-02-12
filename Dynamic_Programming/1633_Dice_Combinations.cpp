/**
 *    author:  vishal
 *    created: 08.03.2025 22:15
**/
 
#include <bits/stdc++.h>
using namespace std;
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
#define hello(x) cerr<<"hello"<<(x)<<endl;
#define MOD ((int)(1e9 + 7))
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}
//typedef __int128 int128;//not support cin cout
 
void solve(){
    ll n;cin>>n;
    //2 == 1+dp[1]
    //3 == 1+
    vector<ll> dp(n+1);
    for(int i=1; i<=6; i++) dp[i] = 1;
    for(int i=2; i<=6; i++){
        for(int j=i-1; j>=1; j--){
            dp[i] = (dp[i]+dp[j])%MOD;
        }
    }
    for(int i=7; i<=n; i++){
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%MOD;
    }
    cout<<dp[n];
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