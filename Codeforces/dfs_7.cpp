#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x, y;
ll solve(ll n, ll cost){
    if(n<=1) return cost;
   // if(n==1) return cost;
    //if(n<0) return cost;
    if(n%2==0){
        return min(solve(n-1, cost+x),solve(n/2, cost+y));
    }
    else return min(solve(n-1, cost+x), solve((n+1)/2, cost+x+y));
}
int main(){
    ll n;
    cin>>n>>x>>y;

    ll ans=solve(n, 0);
    cout<<ans<<"\n";
   /* ll dp[n+1];
    dp[0]=0;
    dp[1]=x;
    for(int i=1; i<=n; i++){
        if(i%2==0) dp[i]=min(dp[i-1]+x, dp[i/2]+y);
        else dp[i]=min(dp[i-1]+x, dp[(i+1)/2]+x+y);
    }
    cout<<dp[n]<<"\n";*/
}