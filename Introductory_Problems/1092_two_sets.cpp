// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define rep(i,a,b) for(int i=a; i<b; i++)
 
void solve(){
    ll n; cin>>n;
    ll tmp = n*(n+1)/2;
    if(tmp%2 == 1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    tmp /= 2;
    vector<int> v;
    for(int i=n; i>=1; i--){
        if(tmp-i<0) break;
        v.push_back(i);
        tmp -= i;
    }
    int n1 = v.size();
    if(tmp == 0){
        cout<<n-n1<<endl;
        for(int i=1; i<=n-n1; i++){
            cout<<i<<" ";
        }cout<<endl;
        cout<<n1<<endl;
        for(int i=0; i<n1; i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }else{
        cout<<n-n1-1<<endl;
        for(int i=1; i<=(n-n1); i++){
            if(i != tmp){
                cout<<i<<" ";
            }
        }cout<<endl;
        
        cout<<n1+1<<endl;
        cout<<tmp<<" ";
        for(int i=0; i<n1; i++) cout<<v[i]<<" ";
        
        cout<<endl;
    }
}
 
int main() {
    // Write C++ code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt = 1;
    while(tt--){
        solve();
    }
 
    return 0;
}
