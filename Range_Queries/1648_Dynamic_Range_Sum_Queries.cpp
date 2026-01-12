/**
 *    author:  vishal
 *    created: 09.02.2025 01:15
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
 
//template for min segment tree
 
class segmentTree{//0-base indexing follow
    private:
    vector<ll> tree;
    ll n;
    //build seg tree
    void buildTree(vector<ll>& arr,ll node,ll start,ll end){
        if(start==end){
            tree[node] = arr[start];
        }else{
            ll mid = (start+end)/2;
            buildTree(arr,2*node+1,start,mid);
            buildTree(arr,2*node+2,mid+1,end);
            tree[node] = tree[2*node+1]+tree[2*node+2];
        }
    }
    ll queryTree(ll node,ll start,ll end, ll l,ll r){
        if(r<start || l>end) return 0;
        if(l<=start && end<=r) return tree[node];
 
        ll mid = (start+end)/2;
        ll leftMin = queryTree(2*node+1,start,mid,l,r);
        ll rightMin = queryTree(2*node+2,mid+1,end,l,r);
        return (leftMin+rightMin);
    }
    void updateTree(ll node,ll start,ll end,ll idx,ll val){
        if(start==end){
            tree[node] = val;
        }else{
            ll mid = (start+end)/2;
            if(idx<=mid){
                updateTree(2*node+1,start,mid,idx,val);
            }else{
                updateTree(2*node+2,mid+1,end,idx,val);
            }
            tree[node] = (tree[2*node+1]+tree[2*node+2]);
        }
    }
    public:
    segmentTree(vector<ll>& arr){
        n = arr.size();
        tree.resize(4*n,INT_MAX);
        buildTree(arr,0,0,n-1);
    }
    ll query(ll l,ll r){
        return queryTree(0,0,n-1,l,r);
    }
    void update(ll idx,ll val){
        updateTree(0,0,n-1,idx,val);
    }
};
 
void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> x(n);in(x,n);
    segmentTree seg = segmentTree(x);
    while(q--){
        ll a,b,c;cin>>a>>b>>c;
        if(a==1){
            seg.update(b-1,c);
        }else{
            cout<<seg.query(b-1,c-1)<<endl;
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