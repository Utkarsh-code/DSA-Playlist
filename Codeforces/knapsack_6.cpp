#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int w, n;
        cin>>w>>n;

        int wt[n], val[n];
        for(int i=0; i<n; i++){
            cin>>wt[i]>>val[i];
        }
         int dp[n+1][w+1];
         memset(dp, 0, sizeof(dp));

         for(int i=1; i<=n; i++){
             for(int j=0; j<=w; j++){
                 if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
                 else dp[i][j]=max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
             }
         }
         cout<<"Hey stupid robber, you can get "<<dp[n][w]<<".\n";
    }
}