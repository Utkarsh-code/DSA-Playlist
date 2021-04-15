#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    string s1;
    while(cin>>s1){
          string s2;
          cin>>s2;

          ll n=s1.length();
          ll m=s2.length();

          ll dp[n+1][m+1];
          memset(dp, 0, sizeof(dp));

          for(int i=1; i<=n; i++){
              for(int j=1; j<=m; j++){
                  if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                  else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
              }
          } 
          vector<char> ans;
          ll i=n, j=m;
          
          while(i>0 && j>0){
              if(s1[i-1]==s2[j-1]) {ans.push_back(s1[i-1]); i--; j--;}
              else{
                  if(dp[i-1][j]>dp[i][j-1]){
                      ans.push_back(s1[i-1]); i--;
                  }
                  else{
                      ans.push_back(s2[j-1]); j--;
                  }
              }
          }
            if(i>0){
                for(int k=i; k>0; k--){
                    ans.push_back(s1[k-1]);
                }
            }
            if(j>0){
                for(int k=j; k>0; k--){
                    ans.push_back(s2[k-1]);
                }
            }
            reverse(ans.begin(), ans.end());
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i];
            }
            cout<<"\n";
    }
}