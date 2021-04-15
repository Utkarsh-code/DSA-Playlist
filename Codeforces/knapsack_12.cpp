#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 int main(){
     ll n, sum;
     cin>>n>>sum;

     ll a[n];
     for(ll i=0; i<n; i++){
         cin>>a[i];
     }

     ll dp[n+1][sum+1];
     memset(dp, 0, sizeof(dp));
     dp[0][0]=1;

     for(ll i=1; i<=n; i++){
         for(ll j=0; j<=sum; j++){
             if(a[i-1]>j) dp[i][j]=dp[i-1][j];
             else dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
         }
     }
     cout<<dp[n][sum]<<"\n";
 }