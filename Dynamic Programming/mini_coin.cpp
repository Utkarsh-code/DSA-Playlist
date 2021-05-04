#include<bits/stdc++.h>
using namespace std;
#define  int long long 


int mod=1e9+7;
int inf=1e18;
int ninf=-1e18;

int pown(int x, int y){
    int res=1;

    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}

void solve(){
  int n, w;
  cin>>n>>w;

   int val[n];
   for(int i=0; i<n; i++) cin>>val[i];

   int dp[2][w+1];
    for(int i=0; i<=w; i++){
        dp[0][i]=inf;
    }
       dp[0][0]=0;
       dp[1][0]=0;
       for(int i=1; i<=n; i++){
           for(int j=1; j<=w; j++){
               if(i&1){
                   if(val[i-1]>j) dp[1][j]=dp[0][j];
                   else dp[1][j]=min(dp[0][j], dp[1][j-val[i-1]]+1);
               }
               else{
                   if(val[i-1]>j) dp[0][j]=dp[1][j];
                   else dp[0][j]=min(dp[1][j], dp[0][j-val[i-1]]+1);
               }
           }
       }   
       int ans=dp[n%2][w];
       if(ans==inf) cout<<"-1\n";
       else cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
