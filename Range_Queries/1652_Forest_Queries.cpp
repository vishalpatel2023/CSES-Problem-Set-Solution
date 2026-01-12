/**
 *    author:  vishal
 *    created: 10.02.2025 09:26
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
    ll n,q;cin>>n>>q;
    vector<vector<int>> dp(n,vector<int>(n));
    vector<string> ans(n);
    rep(i,0,n) cin>>ans[i];
    rep(i,0,n){
        rep(j,0,n){
            if(ans[i][j]=='.') dp[i][j]=0;
            else dp[i][j] = 1;
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            ll tmp1 = 0,tmp2=0,tmp3=0;
            if(i>=1) tmp1 = dp[i-1][j];
            if(j>=1) tmp2 = dp[i][j-1];
            if(i>=1 && j>=1) tmp3 = dp[i-1][j-1];
            dp[i][j] = dp[i][j]+tmp1+tmp2-tmp3;
        }
    }
    while(q--){
        ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        x1--;y2--;y1--;x2--;
        ll tmp1=0,tmp2=0,tmp3=0;
        if(y1>=1) tmp1 = dp[x2][y1-1];
        if(x1>=1) tmp2 = dp[x1-1][y2];
        if(x1>=1 && y1>=1) tmp3 = dp[x1-1][y1-1];
        ll ans = dp[x2][y2]-tmp1-tmp2+tmp3;
        cout<<ans<<endl;
    }
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