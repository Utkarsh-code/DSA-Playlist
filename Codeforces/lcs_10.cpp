#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    string a, b;
    cin>>a>>b;

    ll n=a.length();
    ll m=b.length();

    ll dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    ll len=INT_MIN, row, col;
    for(int i=1; i<=n; i++){
        for(int j=1; j<n; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];

            if(len<dp[i][j]){
                len=dp[i][j];
                row=i;
                col=j;
            }
        }
    }
    string ans="";
    while(dp[row][col]!=0){
        ans+=a[row-1];
        row--;
        col--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
}