#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

     ll w, n;
     cin>>w>>n;

     ll val[n], wt[n];

     for(ll i=0; i<n; i++){
         cin>>val[i]>>wt[i];
     }
     ll dp[n+1][w+1];
     memset(dp, 0, sizeof(dp));
     dp[0][0]=0;

     for(ll i=1; i<=n; i++){
         for(ll j=0; j<=w; j++){
             if(j<wt[i-1]) dp[i][j]=dp[i-1][j];
             else dp[i][j]=max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
         }
     }
     cout<<dp[n][w]<<"\n";
}