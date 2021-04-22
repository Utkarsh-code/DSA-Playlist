#include<bits/stdc++.h>
using namespace std;
int arr[210];
int n;
int dp[210][210][210];
int lis(int mn, int mx, int idx){
    if(idx>n) return 0;
    if(dp[idx][mn][mx]!=-1) return dp[idx][mn][mx];


    int a=1+lis(mn, mx, idx+1);

    int b=1000000007, c=1000000007;
    {
    int prev_val=arr[mn];
    if(prev_val<arr[idx]){
        b=lis(idx, mx, idx+1);
    }
    }

    {
    int prev_val=arr[mx];
    if(prev_val>arr[idx] || prev_val==0){
        c=lis(mn, idx, idx+1);
    }
    }
    
    return dp[idx][mn][mx]=min(a, min(b, c));

}
int main(){

    while(1){
       // int n;
        cin>>n;

        if(n==-1) break;
        for(int i=1; i<=n; i++) cin>>arr[i];
        arr[0]=0;
        memset(dp, -1, sizeof(dp));
        int ans=lis(0, 0, 1);
        cout<<ans<<"\n";
    }
}