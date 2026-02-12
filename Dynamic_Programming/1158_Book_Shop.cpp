/**
 *    author:  vishal
 *    created: 08.03.2025 23:17
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
#define matout(arr){for(int i=0; i<arr.size(); i++){for(int j=1; j<arr[0].size(); j++){cout<<arr[i][j]<<" ";}cout<<endl;}}
#define sum(arr, n) accumulate(arr, arr + n, 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rep2(i, a, b, j, c, d) for(int i = a; i < b; i++) for(int j = c; j < d; j++)
#define debug(x) cerr << "Debug: " << #x << " = " << (x) << endl;
#define ll long long
#define hello(x) cerr<<"hello"<<(x)<<endl;
#define MOD ((int)(1e9 + 7))
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}
//typedef __int128 int128;//not support cin cout
 
void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> h(n),s(n);
    in(h,n);in(s,n);
    //vector<vector<ll>> dp(n,vector<ll>(x+1,0));//book taken, price
    vector<ll> prev(x+1,0);
    if(h[0]<=x){
        prev[h[0]] = s[0]; 
    }
    for(int i=1; i<n; i++){
        vector<ll> curr(x+1,0);
        for(int j=1; j<=x; j++){
            //dp[i][j] = dp[i-1][j];//0,1...,i price = 
            //dp[i][j] = dp[i][x-h[j]]
            if(j>=h[i]){
                curr[j] = max(prev[j],s[i]+prev[j-h[i]]);
            }else curr[j] = prev[j];
        }
        prev = curr;
    }
    cout<<*max_element(prev.begin(),prev.end());
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