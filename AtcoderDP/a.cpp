#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    int arr[n+1];
    arr[0]=0;
    for(int i=1; i<=n; i++) cin>>arr[i];

    int dp[n+1];
    dp[0]=10000000009;
    dp[1]=0;
    for(int i=2; i<=n; i++){
        int x=dp[i-2]+abs(arr[i]-arr[i-2]);
        int y=dp[i-1]+abs(arr[i]-arr[i-1]);
        dp[i]=min(x, y);
    }
     cout<<dp[n]<<"\n";
}