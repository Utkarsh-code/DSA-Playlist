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
  int n, m;
  cin>>n>>m;

  int grid[n][m];
  for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
          char ch;
          cin>>ch;
          if(ch=='#') grid[i][j]=0;
          else grid[i][j]=1;
      }
  }
     int dp[n+1][m+1];
     memset(dp, 0, sizeof(dp));
     if(grid[0][0]==1) dp[1][1]=1;
     for(int i=1; i<=n; i++){
         for(int j=1; j<=m; j++){
             if(grid[i-1][j-1]==0 || (i==1 && j==1)) continue;

             dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            // cout<<dp[i][j]<<" ";
         }
     }    
     cout<<dp[n][m]<<"\n";
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
