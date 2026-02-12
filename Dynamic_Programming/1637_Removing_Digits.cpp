#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" is: "<<x<<endl;
 
int cnt(int n){
    int ans = 0;
    while(n){
        ans++;
        n/=10;
    }
    return ans;
}
int fun(int n,vector<int>& dp){
    //base case
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int dg = cnt(n);
    int ans=1e9;
    int tmp = n;
    for(int i=1; i<=dg; i++){
        if((tmp%10) != 0)
            ans = min(ans,1+fun(n-tmp%10,dp));
        tmp /= 10;
    }
    return dp[n]=ans;
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fun(n,dp);
    return 0;
}
