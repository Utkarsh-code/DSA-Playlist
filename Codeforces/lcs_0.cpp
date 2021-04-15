#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[1001][1001];
ll lcs(string s1, string s2, ll n, ll m){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];

    if(s1[n-1]==s2[m-1])
       return dp[n][m]=1+lcs(s1,s2, n-1, m-1);

    else return dp[n][m]=max(lcs(s1,s2,n-1, m), lcs(s1,s2,n,m-1));
}
int main(){
     string s1, s2;
     cin>>s1>>s2;

     ll n=s1.length();
     ll m=s2.length();
 
     //ll dp[n+1][m+1];
     memset(dp, -1,sizeof(dp));
     cout<<lcs(s1,s2,n, m)<<"\n";

}