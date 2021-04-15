#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
         int nums[n];
         for(int i=0; i<n; i++) {cin>>nums[i]; sum+=nums[i];}

         if(sum%2!=0) cout<<"NO\n";
         else{
             sum=sum/2;
             int dp[n+1][sum+1];
             memset(dp, 0, sizeof(dp));
             dp[0][0]=1;

             for(int i=1; i<=n; i++){
                 for(int j=0; j<=sum; j++){
                     if(nums[i-1]>j) dp[i][j]=dp[i-1][j];
                     else dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
                 }
             }
             if(dp[n][sum]==0) cout<<"NO\n";
             else cout<<"YES\n";
         }
    }
}