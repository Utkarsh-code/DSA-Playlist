//oj.com/problems/PARTYhttp://www.sp/
#include<bits/stdc++.h>
using namespace std; 
int main(){

    while(1){
        int max_wt, n;
        cin>>max_wt>>n;
         if(n==0 && max_wt==0) break;

         int wt[n];
         int val[n];
         int w=max_wt;
         max_wt=0;
         for(int i=0; i<n; i++){
             cin>>wt[i]>>val[i];
             max_wt+=wt[i];
         }

         int dp[n+1][max_wt+1];
         memset(dp, 0, sizeof(dp));

         for(int i=1; i<=n; i++){
             for(int j=0; j<=max_wt; j++){
                 if(j<wt[i-1]) dp[i][j]=dp[i-1][j];
                 else dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
             }
         }
         int ans=INT_MIN,  sum=0;
          for(int i=0; i<=w; i++){
              if(ans<dp[n][i]){
                  ans=dp[n][i];
                  sum=i;
              }
          }
        
        
        cout<<sum<<" "<<ans<<"\n";
    }
}
/*
input :
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0

output:
49 26
48 32*/