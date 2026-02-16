/**
 *    author:  vishal
 *    created: 12.11.2025 17:08
**/
 
//#define NDEBUG //to use assert uncomment this
#include <bits/stdc++.h>
//#include "debugging.h" 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
using namespace std;
//using namespace __gnu_pbds;
using namespace chrono;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> moset;
#define MIN(arr) (*min_element(arr.begin(), arr.end()))
#define MAX(arr) (*max_element(arr.begin(), arr.end()))
#define sorts(arr) sort(arr.begin(),arr.end())
 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
 
#define set_cnt(n) __builtin_popcountll(n)
#define set_bit(x, i) ((x)|(1LL<<(i))) //ith bit of x to 1
#define clear_bit(x, i) ((x)&~(1LL<<(i))) //unset
#define toggle(x, i) ((x)^(1LL<<(i)))
#define is_set(x, i) ((x)&(1LL<<(i)))
#define is_pow2(x) ((x) && !((x)&((x)-1)))
 
#define in(arr,n) for(int i=0; i<n; i++){cin>>arr[i];}
#define out(arr,n) for(int i=0; i<n; i++){cout<<arr[i]<<" ";}
#define matout(arr){for(int i=0; i<arr.size(); i++){for(int j=0; j<arr[0].size(); j++){cout<<arr[i][j]<<" ";}cout<<endl;}}
#define SUM(arr) accumulate(arr.begin(), arr.end(), 0LL)
 
#define loop(n) for(ll i=0; i<n; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rep2(i,j,a,b,c,d) for(int i=a; i<b; i++) for(int j=c; j<d; j++)
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << "Debug: " << #x << " = " << (x) << endl;
#define debug2(x, y) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define debug3(x, y, z) cerr<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define ll long long
const ll MOD = 1e9+7;
#define print(arr,n) rep(i,0,n){cout<<arr[i]<<" ";}
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vpi = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvpi = vector<vpi>;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
 
//typedef __int128 int128;//not support cin cout
//#define endl "\n"
// ll total = 0;
 
bool caniplace(vector<string>& arr,int r,int c){
    //check in same row??
    if(arr[r][c]=='*') return false;
 
    for(int i=0; i<8; i++){
        if(arr[r][i]=='q') return false;
    }
    for(int i=0; i<8; i++){
        if(arr[i][c]=='q') return false;
    }
    //check diagonal
    int x = r,y=c;
    while(x>=0 && y>=0){
        if(arr[x][y]=='q') return false;
        x--;y--;
    }
 
    x = r,y=c;
    while(x<8 && y<8){
        if(arr[x][y]=='q') return false;
        x++; y++;
    }
 
    x = r, y = c;
    while(y<8 && x>=0){
        if(arr[x][y]=='q') return false;
        x--; y++;
    }
 
    x = r, y = c;
    while(y>=0 && x<8){
        if(arr[x][y]=='q') return false;
        x++; y--;
    }
 
    return true;
}
ll mx = 10000;
 
ll fun(vector<string>& arr,int r){
    if(r==8) return 1;

    //keep it in this row
    ll ans = 0;
    for(int i=0; i<8; i++){
        if(caniplace(arr,r,i)){
            arr[r][i] = 'q';
            ans += fun(arr,r+1);
            arr[r][i] = '.';
        }
    }
    return ans;
}
 
void solve(){
    vector<string> arr(8);
    in(arr,8);
 
    ll ans = fun(arr,0);
    cout<<ans;
    cout<<endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    auto start = high_resolution_clock::now();
    while(t--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    //cout<<"Execution time: "<<duration.count()<<" ms"<<endl;
 
    return 0;
}