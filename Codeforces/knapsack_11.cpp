#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n, w;
    cin>>n>>w;

    ll wt[n], val[n];
    ll v=0;
    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
        v+=val[i];
    }
     ll dp[n+1][v+1];
     for(int i=0; i<=v; i++){
         dp[0][i]=INT_MAX;
     }

     for(int i=0; i<=n; i++){
         dp[i][0]=0;
     }

     for(int i=1; i<=n; i++){
         for(int j=0; j<=v; j++){
             if(j<val[i-1]) dp[i][j]=dp[i-1][j];
             else dp[i][j]=min(dp[i-1][j], dp[i-1][j-val[i-1]]+wt[i-1]);
         }
     }
     ll ans=INT_MIN;
     for(ll i=0; i<=v; i++){
         if(dp[n][i]<=w) ans=max(ans, i);
     }
     cout<<ans<<"\n";
}