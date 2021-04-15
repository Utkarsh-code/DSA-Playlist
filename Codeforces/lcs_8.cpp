#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n, m;
        cin>>n>>m;

        ll a[m], b[m];
        for(int i=0; i<m; i++){
            cin>>a[i];
        }
        for(int i=0; i<m; i++){
            cin>>b[i];
        }

        ll dp[m+1][m+1];
        memset(dp, 0, sizeof(dp));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1]; 
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout<<dp[m][m]<<"\n";
    }
}