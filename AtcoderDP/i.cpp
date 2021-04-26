#include<bits/stdc++.h>
using namespace std;
#define  int long long
double dp[3000][3000];

double mod=1e9+7;
double inf=1e18;
double ninf=-1e18;

/*double pown(double x, double y){
    double res=1;

    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}*/

void solve(){
  int n;
  cin>>n;

  double p[n];
  for(int i=0; i<n; i++) cin>>p[i];
 // double dp[n][n+10];
 //  memset(dp, 0, sizeof(dp));
  dp[0][0]=1-p[0];
  dp[0][1]=p[0];

  for(int i=1; i<n; i++){
      for(int j=0; j<i+2; j++){
          dp[i][j]+=(1-p[i])*dp[i-1][j];
          if(j>0){
              dp[i][j]+=p[i]*dp[i-1][j-1];
          }
      }
  }
     double ans=0;
     for(int i=0; i<n+1; i++){
        // double j=n-i;
        if(i>n-i)
         ans+=dp[n-1][i];
     }  
     cout<<setprecision(10);
     cout<<fixed;
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
