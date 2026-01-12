#include<bits/stdc++.h>
using namespace std;
#define int long long
int mx = (int)(200009);
vector<int> arr(4*mx,0);
void seg(int l,int r,vector<int>& x,int idx){
    if(l==r){
        arr[idx] = x[l];
        return;
    }
    int mid = (l+r)/2;
    seg(l,mid,x,2*idx+1);
    seg(mid+1,r,x,2*idx+2);
    //arr[idx] = min(arr[2*idx+1],arr[2*idx+2]);
}
int qq(int l,int r,vector<int>& x,int idx,int ind){
    //base case
    //if(r<left || l>right) return INT_MAX;
 
    if(l==r) return arr[idx];
 
    arr[2*idx+1] += arr[idx];
    arr[2*idx+2] += arr[idx];
    arr[idx] = 0;
    //if(l>=left && r<=right) return arr[idx];
    //if(r<ind || l>ind) return;
    int mid = (l+r)/2;
    if(ind<=mid){
        return qq(l,mid,x,2*idx+1,ind);
    }else{
        return qq(mid+1,r,x,2*idx+2,ind);
    }
    //return min(tmp1,tmp2);
}
void update(int l,int r,vector<int>& x,int idx,int left,int right,int u){
    //base case
    
    if(r<left || l>right){
        return;
    }
    if(left<=l && r<=right){
        arr[idx] += u;
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,x,2*idx+1,left,right,u);
    update(mid+1,r,x,2*idx+2,left,right,u);
    //arr[idx] = min(arr[2*idx+1],arr[2*idx+2]);
}
signed main(){
    int n,q;cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    seg(0,n-1,arr,0);
    for(int i=0; i<q; i++){
        int tmp;cin>>tmp;
        if(tmp==2){
            int k;cin>>k;
            cout<<qq(0,n-1,arr,0,k-1)<<endl;
        }else{
            int a,b,u;cin>>a>>b>>u;
            update(0,n-1,arr,0,a-1,b-1,u);
        }
        
    }
    
}