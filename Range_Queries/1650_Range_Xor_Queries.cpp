#include<bits/stdc++.h>
using namespace std;
int mx = (int)(200009);
vector<int> arr(4*mx);
void seg(int l,int r,vector<int>& x,int idx){
    if(l==r){
        arr[idx] = x[l];
        return;
    }
    int mid = (l+r)/2;
    seg(l,mid,x,2*idx+1);
    seg(mid+1,r,x,2*idx+2);
    arr[idx] = (arr[2*idx+1]^arr[2*idx+2]);
}
int qq(int l,int r,vector<int>& x,int idx,int left,int right){
    //base case
    if(r<left || l>right) return 0;
 
    if(l>=left && r<=right) return arr[idx];
    int mid = (l+r)/2;
    int tmp1 = qq(l,mid,x,2*idx+1,left,right);
    int tmp2 = qq(mid+1,r,x,2*idx+2,left,right);
    return (tmp1^tmp2);
}
int main(){
    int n,q;cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    seg(0,n-1,arr,0);
    for(int i=0; i<q; i++){
        int a,b;cin>>a>>b;
        cout<<qq(0,n-1,arr,0,a-1,b-1)<<endl;
    }
    
}