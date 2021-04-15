#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;

    ll cnt=1;
    while(t--){
        ll n, w;
        cin>>n>>w;

        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        ll dp[n+1][w+1];
        memset(dp, 0, sizeof(dp));

        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }

        for(int i=a[0]; i<=w; i++){
                 dp[1][i]=a[0];
        }

        for(int i=2; i<=n; i++){
            for(int j=1; j<=w; j++){
                if(a[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j], dp[i-2][j-a[i-1]]+a[i-1]);
            }
        }
         cout<<"Scenario #"<<cnt<<": "<<dp[n][w]<<"\n";
            cnt++;
    }
}