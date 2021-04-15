#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int pre_sum[n];
        pre_sum[0]=a[0];
        for(int i=1; i<n; i++){
            pre_sum[i]=a[i]+pre_sum[i-1];
        }
        int dp[n][n];
        for(int i=0; i<n; i++) dp[i][i]=0;

        for(int l=2; l<=n; l++){
            for(int i=0; i<n-l+1; i++){
                int j=i+l-1;
                 dp[i][j]=INT_MAX;
                for(int k=i; k<j; k++){
                    int temp=dp[i][k]+dp[k+1][j];
                   // cout<<temp<<" ";
                    int x=(pre_sum[k]-(i-1>=0 ? pre_sum[i-1] : 0))%100;
                   // cout<<x<<" ";
                    int y=(pre_sum[j]-(k>=0 ? pre_sum[k] :0))%100;
                    temp+=(x*y);
                   // cout<<temp<<" ";
                    dp[i][j]=min(dp[i][j], temp);
                }
            }
        }
        cout<<dp[0][n-1]<<"\n";
    }
}