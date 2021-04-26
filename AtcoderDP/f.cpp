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
  string s, t;
  cin>>s>>t;

  int n=s.length();
  int m=t.length();

  int dp[n+1][m+1];
  memset(dp, 0,sizeof(dp));

  for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
      }
  }
 // cout<<dp[n][m]<<" ";
  int i=n, j=m;
  string ans="";
  while(i>0 && j>0){
      if(s[i-1]==t[j-1]){
          ans+=s[i-1];
          i--; j--;
      }
      else{
          if(dp[i-1][j]>dp[i][j-1]) i--;
          else j--;
      }
  }
  reverse(ans.begin(), ans.end());
  cout<<ans<<"\n";
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
