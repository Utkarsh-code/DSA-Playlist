#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll inf=1e18;
int main(){
    ll n, k;
    cin>>n>>k;

    ll arr[n+1];
    for(ll  i=1; i<=n; i++) cin>>arr[i];
    arr[0]=0;

    ll dp[n+1];
    dp[0]=inf;
    dp[1]=0;
    for(ll i=2; i<=n; i++){
        ll ans=inf;
        for(ll j=i-1; j>=0 && j>=i-k; j--){
            ans=min(ans, dp[j]+abs(arr[i]-arr[j]));
           // cout<<ans<<" ";
        }
        dp[i]=ans;
    }
   // for(ll i=1; i<=n; i++) cout<<dp[i]<<" ";
    cout<<dp[n]<<"\n";
}