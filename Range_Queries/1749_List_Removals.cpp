/**
 *    author:  vishal
 *    created: 20.06.2025 18:30
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
ll mx = 200005;
vector<ll> seg(4*mx);
 
void create(int l,int r,int idx,vector<ll>& arr){
    if(l==r){
        seg[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    create(l,mid,2*idx+1,arr);
    create(mid+1,r,2*idx+2,arr);
    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}
int ans = -1;
int query(int l,int r,int idx,int left,int right){
    if(r<left || l>right) return 0;
 
    if(left<=l && r<=right) return seg[idx];
    int mid =(l+r)/2;
 
    int lt = query(l,mid,2*idx+1,left,right);
    int rt = query(mid+1,r,2*idx+2,left,right);
    return lt+rt;
}
void update(int l,int r,int idx,int ind){
    if(l==r){
        seg[idx] = 0;
        return;
    }
    int mid = (l+r)/2;
    if(ind<=mid){
        update(l,mid,2*idx+1,ind);
    }else{
        update(mid+1,r,2*idx+2,ind);
    }
    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}
void solve(){
    ll n;cin>>n;
    vector<ll> x(n); in(x,n);
    vector<ll> tmp(n,1);
    create(0,n-1,0,tmp);
    rep(i,0,n){
        ll p;cin>>p;
        ll lo = 0, hi = n-1;
        ll mid;
        //int cnt = 20;
        while(lo<hi){
            mid = (lo+hi)/2;
            //debug(lo) debug(mid) debug(hi)
            //find lowest index such that sum from ind 0 to i==>p
            ll sm = query(0,n-1,0,0,mid);
            // debug(mid)
            // debug(sm)
            if(sm<p){
                lo = mid+1;
            }else{
                hi = mid;
            }
        }
        //debug(lo+1)
        cout<<x[lo]<<" ";
        update(0,n-1,0,lo);
    }
    cout<<endl;
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