#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int ew, fw;
    cin>>ew>>fw;

    int n;
    cin>>n;

    int val[n], wt[n];
    for(int i=0; i<n; i++){
        cin>>val[i]>>wt[i];
    }

    int w=fw-ew;
    int dp[n+1][w+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=w;  j++){
            dp[i][j]=1000000009;
        }
    }
    //for(int i=0; i<=n; i++) dp[i][0]=0;
    //for(int j=0; j<=w; j++) dp[0][j]=0;
    dp[0][0]=0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=min(dp[i-1][j], dp[i][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    int ans=dp[n][w];
    if(ans==1000000009) cout<<"This is impossible.\n";
    else cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
    }
}