#include<bits/stdc++.h>
 
using namespace std;
 
int mx = 200008;
vector<int> seg(4*mx);
 
void create(int l,int r,vector<int>& arr,int idx){
    if(l==r){
        seg[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    create(l,mid,arr,2*idx+1);
    create(mid+1,r,arr,2*idx+2);
    seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
}
int ans = -1;
void qq(int l,int r,vector<int>& arr,int idx,int room){
    //base case
 
    if(l==r){
        ans = l;
        seg[idx] -= room;
        return;
    }
    int mid = (l+r)/2;
    if(seg[2*idx+1]>=room){
        qq(l,mid,arr,2*idx+1,room);
    }else{
        qq(mid+1,r,arr,2*idx+2,room);
    }
    seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
 
}
int main(){
    int n,m;cin>>n>>m;
 
    vector<int> h(n);
    for(int i=0; i<n; i++) cin>>h[i];
 
    create(0,n-1,h,0);
    //for(int x: seg) cout<<x<<" ";cout<<endl;
    for(int i=0; i<m; i++){
        int r;cin>>r;
        if(seg[0]<r){
            cout<<0<<" ";
        }else{
            qq(0,n-1,h,0,r);
            cout<<1+ans<<" ";
        }
    }
 
    return 0;
}