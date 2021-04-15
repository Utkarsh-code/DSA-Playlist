#include<bits/stdc++.h>
using namespace std;
void solve(int max_wt, int n){
    
    
    
    //if(n==0 && max_wt==0) break;
    int wt[n];
    int val[n];
    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }
    int dp[n+1][max_wt+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=max_wt; j++){
            if(j<wt[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
        }
    }
    // cout<<dp[n][max_wt]<<"\n";
      int i=n, j=max_wt;
        int req_wt=0;
        while(i>0 && j>0){
            if(j>=wt[i-1]){
                if(dp[i][j]==(dp[i-1][j-wt[i-1]]+val[i-1])) {req_wt+=wt[i-1]; j=j-wt[i-1];}
            }
            i--;
        }
        cout<<req_wt<<" "<<dp[n][max_wt]<<"\n";
}
int main(){
    while(1){
        int max_wt;
    cin>>max_wt;
    int n;
    cin>>n;
    if(n==0 && max_wt==0) break;
        solve(max_wt, n);
    }
}