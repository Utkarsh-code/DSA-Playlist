#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int n, m;
int dp[2][1000010];
int helix(int flag, int idx, int arr[]){
    
    if(flag==0 && idx==n) return 0;
    if(flag==1 && idx==m) return 0;
    if(dp[flag][idx]!=-1) return dp[flag][idx];
    int num=0;
    int len=0;
    if(flag==0) {len=m; num=arr[idx];}
    else {len=n; num=arr[idx];}
    
    int f=0;
    int prev=0;
    for(int i=0; i<len; i++){
       if(len==m){ if(b[i]==num){
            prev=i;
            f=1;
            break;
        }}
        else{
            if(a[i]==num){
                prev=i;
                f=1;
                break;
            }
        }
    }
    int x=-1000000009;
    if(f) { if(flag==0) x=num+helix((!flag), prev+1,b);
            else x=num+helix((!flag), prev+1, a);}
    return dp[flag][idx]=max(x, num+helix(flag,idx+1, arr));
}
int main(){

    while(1){
        //int n;
        cin>>n;
        if(n==0) break;
        //int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

      //  int m;
        cin>>m;
       // int b[m];
        for(int i=0; i<m; i++) cin>>b[i];
        
        memset(dp, -1, sizeof(dp));
        int ans=helix(0, 0,a);
        memset(dp, -1, sizeof(dp));
        ans=max(ans, helix(1, 0, b));

       cout<<ans<<"\n";
    }
}