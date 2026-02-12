/**
 *    author:  vishal
 *    created: 2024.11.27 15:33
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
#define hello(x) cerr<<"hello"<<(x)<<endl;
#define MOD ((int)(1e9 + 7))
 
ll fun(ll n,ll trg,vector<vector<ll>>& dp){
    //base case
    if(trg == 0) return 1;
    if(trg<0) return 0;
    if(n<=0) return 0;
    if(dp[n][trg] != -1) return dp[n][trg];
    ll take = fun(n-1,trg-n,dp);
    ll no = fun(n-1,trg,dp);
 
    return dp[n][trg]=(take+no)%MOD;
}
ll bin(ll a,ll b,ll val){ //a^b
    if(b == 0) return 1;
    ll tmp = bin(a,b/2,val);
    if(b%2 == 0){
        return (tmp*tmp)%val;
    }else return (a*tmp*tmp)%val;
}
ll val = 1000000007;
ll modInv(ll x){
    ll tmp = bin(2,val-2,val);
    return tmp%val;
}
 
void solve(){
    ll n;
    cin>>n;
    ll sm = n*(n+1)/2;
    ll trg = sm/2;
    if(sm%2 == 1){
        cout<<0<<endl;
        return;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(trg+1,-1));
    ll tmp = (fun(n,trg,dp)*modInv(2))%MOD;
    cout<<tmp<<endl;
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