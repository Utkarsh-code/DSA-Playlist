#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
bool ispalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j){
    if(i>=j) return 0;
    if(ispalindrome(s, i, j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mn=INT_MAX;
    for(int k=i; k<j; k++){
        int temp=solve(s, i, k)+solve(s, k+1, j)+1;
        if(temp<mn) mn=temp;
    }
    return dp[i][j]=mn;
}
int main(){
    string s;
    cin>>s;
    
    int n=s.length();
    memset(dp, -1, sizeof(dp));
    int ans=solve(s, 0, n-1);
    cout<<ans<<"\n";
}