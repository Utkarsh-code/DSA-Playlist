#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
int main(){
    ll n, w;
    cin>>n>>w;

    ll wt[n], val[n];
    for(ll i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }
    ll dp[n+1][w+1];
    memset(dp,0, sizeof(dp));
    dp[0][0]=0;

    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=w; j++){
            if(j<wt[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
        }
    }
    ll ans=dp[n][w];
    cout<<ans<<"\n";
}