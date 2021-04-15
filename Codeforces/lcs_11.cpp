#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    while (t--)
    {
        char ch;
        cin>>ch;

        string st;
        cin>>st;

        string t=st;
        reverse(t.begin(), t.end());

        int l=st.length();
        int dp[l+1][l+1][2];

        memset(dp, 0, sizeof(dp));
        for(int i=0; i<l; i++){
            if(st[i]==ch) dp[i][0][1]=1;
        }
        for(int j=0; j<l; j++){
              if(t[j]==ch) dp[0][j][1]=1;
        }

        for(int i=1; i<=l; i++){
            for(int j=1; j<=l; j++){
                if(st[i-1]==t[j-1] && st[i-1]==ch) dp[i][j][1]=1+max(dp[i-1][j-1][0], dp[i-1][j-1][1]);
                else if(st[i-1]==t[j-1] && st[i-1]!=ch){
                    dp[i][j][0]=1+dp[i-1][j-1][1];
                }
                else{
                    dp[i][j][0]=max(dp[i-1][j][0], dp[i][j-1][0]);
                    dp[i][j][1]=max(dp[i-1][j][1], dp[i][j-1][1]);
                }
            }
        }
        cout<<dp[l][l][0]<<" "<<dp[l][l][1]<<"\n";
    }
    
}