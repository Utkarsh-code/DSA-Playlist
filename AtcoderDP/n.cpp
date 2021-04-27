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
int a[405];
int dp[405][405];
int mcm(int l, int r){
    
    if(l==r) return dp[l][r]=0;
    if(dp[l][r]!=-1) return dp[l][r];

    int sum=0;
    for(int i=l; i<=r; i++) sum+=a[i];
    
    int ans=inf;
    for(int x=l; x<r; x++){
          ans=min(ans, mcm(l, x)+mcm(x+1, r)+sum);
    }
    return dp[l][r]=ans;
}
void solve(){
  int n;
  cin>>n;

  for(int i=0; i<n; i++) cin>>a[i];

   //recursive dp
   memset(dp, -1, sizeof(dp));
   int ans=mcm(0, n-1);
   cout<<ans<<"\n";

   // iterative dp      
  /*for(int wid=2; wid<=n; wid++){
      for(int l=0; l<=n-wid; l++){
          int r=l+wid-1;
          int sum=0;
          for(int i=l; i<=r; i++) sum+=a[i];
          
          int ans=inf;
          for(int x=l; x<r; x++)
          ans=min(ans, dp[l][x]+dp[x+1][r]+sum);

          dp[l][r]=ans;
      }
  }
   cout<<dp[0][n-1]<<"\n";*/
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
         cout<<setprecision(10);
         cout<<fixed;
        solve();
    }
    return 0;
}
