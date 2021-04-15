#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
int main(){
    string s1, s2;
    cin>>s1>>s2;

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
    ll i=n, j=m;
    vector<char> ans;
    while (i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    //cout<<dp[n][m];
    reverse(ans.begin(), ans.end());
    for(ll i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
}