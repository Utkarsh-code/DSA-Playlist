#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[2001][2001];
bool ispalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    ll n=s.length();

    for(int i=0; i<n; i++) dp[i][i]=0;

    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            if(ispalindrome(s, i, j)) dp[i][j]=0;
            else{
            for(int k=i; k<j; k++){
                 ll temp=dp[i][k]+dp[k+1][j]+1;
                 dp[i][j]=min(dp[i][j], temp);
            }}
        }
    }
    cout<<dp[0][n-1]<<"\n";
}