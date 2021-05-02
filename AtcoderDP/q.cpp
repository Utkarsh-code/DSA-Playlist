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
  int n;
  cin>>n;

  int h[n];
  for(int i=0; i<n; i++) cin>>h[i];

  int b[n];
  for(int i=0; i<n; i++) cin>>b[i];

  /*int dp[n];
  for(int i=0; i<n; i++) dp[i]=b[i];

  for(int i=0; i<n; i++){
      for(int j=0; j<i; j++){
          if(h[j]<h[i]){
              dp[i]=max(dp[i], dp[j]+b[i]);
          }
      }
  }
      int ans=*max_element(dp, dp+n);
      cout<<ans<<"\n";   */

      vector<int> ans(n+1, inf);
      ans[0]=-inf;

      for(int i=0; i<n; i++){
          int idx=upper_bound(ans.begin(), ans.end(), h[i])-ans.begin();

          if(ans[idx-1]<h[i] && ans[idx]>h[i])
          ans[idx]=h[i];

      }
      for(int i=0; i<=n; i++){
          cout<<ans[i]<<" ";
      }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
         cout<<setprecision(10);
         cout<<fixed;
        solve();
    }
    return 0;
}
