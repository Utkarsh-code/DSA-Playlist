#include<bits/stdc++.h>
using namespace std;
int main(){

    while(1){
        int n;
        cin>>n;

        if(n==0) break;

        string s, t;
        cin>>s>>t;
        int l1=s.length();
        int l2=t.length();
       int dp[l1+1][l2+1];
       
       memset(dp, 0, sizeof(dp));
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
               int c=1;

               while(i-c>=0 && j-c>=0 && s[i-c]==t[j-c]){
                   if(c>=n){
                       dp[i][j]=max(dp[i][j], dp[i-c][j-c]+c);
                   }
                   c++;
               }
               dp[i][j]=max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
       int ans=dp[l1][l2];
       cout<<ans<<"\n";
    }
}