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

  int wt[n], val[n];

  for(int i=0; i<n; i++){
      cin>>wt[i]>>val[i];
  }

  int dp[n+1][w+1];
  memset(dp, 0, sizeof(dp));

  for(int i=1; i<=n; i++){
      for(int j=1; j<=w; j++){
          if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
          else dp[i][j]=max(dp[i-1][j], dp[i-1][j-wt[i-1]]+val[i-1]);
      }
  }  
  cout<<dp[n][w]<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
