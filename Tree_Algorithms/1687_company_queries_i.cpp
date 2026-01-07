/**
 *    author:  vishal
 *    created: 17.06.2025 01:36
**/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> moset;
#define MIN(arr) (*min_element(arr.begin(), arr.end()))
#define MAX(arr) (*max_element(arr.begin(), arr.end()))
#define sorts(arr) sort(arr.begin(),arr.end())
 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
 
#define set_cnt(n) __builtin_popcount(n)
#define set_bit(x, i) ((x)|(1LL<<(i))) //ith bit of x to 1
#define clear_bit(x, i) ((x)&~(1LL<<(i))) //unset
#define toggle(x, i) ((x)^(1LL<<(i)))
#define is_set(x, i) ((x)&(1LL<<(i)))
#define is_pow2(x) ((x) && !((x)&((x)-1)))
 
#define in(arr,n) for(int i=0; i<n; i++){cin>>arr[i];}
#define out(arr,n) for(int i=0; i<n; i++){cout<<arr[i]<<" ";}
#define matout(arr){for(int i=0; i<arr.size(); i++){for(int j=0; j<arr[0].size(); j++){cout<<arr[i][j]<<" ";}cout<<endl;}}
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rep2(i,j,a,b,c,d) for(int i=a; i<b; i++) for(int j=c; j<d; j++)
#define debug(x) cerr<<"Debug: "<<#x<<" = "<<(x)<< endl;
#define ll long long
#define hello(x) cerr<<"hello"<<(x)<<endl;
#define MOD ((int)(1e9+7))
#define inf (ll)(1e15)
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}
//typedef __int128 int128;//not support cin cout
//#define endl "\n"
 
ll ans(vector<vector<ll>>& bin,ll node,ll k){
    //node ka kth parent
    if(k==0 || node==-1) return node;
    ll tmp = log2(k);
    return ans(bin,bin[node][tmp],k-(1<<tmp));
}
void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> par(n+1);
    rep(i,2,n+1){
        ll a;cin>>a;
        par[i] = a;
    }
 
    ll tmp = log2(n)+2;
    vector<vector<ll>> bin(n+1,vector<ll>(tmp,-1));
    
    for(int i=0; i<=tmp; i++){
        for(int j=2; j<=n; j++){
            //j ka 2^ith parent
            if(i==0){
                bin[j][i] = par[j];
            }else{
                if(bin[j][i-1] != -1)
                    bin[j][i] = bin[bin[j][i-1]][i-1];
            }
        }
    }
    rep(i,0,q){
        ll x,k;cin>>x>>k;
        cout<<ans(bin,x,k)<<endl;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin>>t;
    auto start = high_resolution_clock::now();
    while(t--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    //cout<<"Execution time: "<<duration.count()<<" ms"<<endl;
 
    return 0;
}