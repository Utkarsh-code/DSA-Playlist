#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    string t=s;
    reverse(t.begin(), t.end());
   // cout<<t;

    ll dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<n-dp[n][n]<<"\n";
}