/**
 *    author:  vishal
 *    created: 23.02.2025 03:34
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
#define p(x) cout<<x<<endl;
 
void solve(){
    ll n,m;cin>>n>>m;
    vector<ll> arr(n);in(arr,n);
 
    vector<vector<ll>> dp(n,vector<ll>(m+1,0));//index, the value kept
 
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            ll v1 = 0,v2=0,v3=0;
            if(i>=1){
                v1 = dp[i-1][arr[i]];
                if(arr[i]-1>=0) v2 = dp[i-1][arr[i]-1];
                if(arr[i]+1<=m) v3 = dp[i-1][arr[i]+1];
            }else{
                v1 = 1;
            }   
            dp[i][arr[i]] = (v1+v2+v3)%MOD;
        }else{
            for(int j=1; j<=m; j++){
                //dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
                ll v1=0,v2=0,v3=0;
                if(i>=1){
                    v1 = dp[i-1][j];
                    v2 = dp[i-1][j-1];
                    if(j+1<=m) v3 = dp[i-1][j+1];
                    dp[i][j] = (v1+v2+v3)%MOD;
                }else{
                    dp[i][j] = 1;
                }
            }
        }
        
    }
    ll ans = accumulate(dp[n-1].begin(),dp[n-1].end(),0LL);
    ans = ans%MOD;
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