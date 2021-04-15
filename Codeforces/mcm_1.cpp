#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    ll dp[n][n];
    for(int i=0; i<n; i++) dp[i][i]=0;

    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i; k<j; k++){
                int temp=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(temp<dp[i][j]) dp[i][j]=temp;
            }
        }
    }
    cout<<dp[1][n-1];
}