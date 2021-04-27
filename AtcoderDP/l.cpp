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
int n;
int a[3010];
int dp[3010][3010][2];
int deq(int x, int l, int r){
   
   if(l>r) return 0;
   if(dp[l][r][x]!=-1) return dp[l][r][x];
    if(x==1){
        return dp[l][r][x]=max(a[l]+ deq(1-x, l+1, r), a[r]+deq(1-x,l, r-1));
    }
    else{
        return dp[l][r][x]=min(deq(1-x, l+1, r),deq(1-x,l, r-1));
    }
}
void solve(){
  /* x+y=total_sum
     x-y=k;
      2*x-total_sum=k
       so we have to maximize or minize x */

  cin>>n;
  int sum=0;
  for(int i=0; i<n; i++) {cin>>a[i]; sum+=a[i];}
  
   //recursive dp
  /*memset(dp, -1, sizeof(dp));
  int ans=deq(1,0, n-1);
  ans=2*ans-sum;*/
  
  //iterative dp
  for(int i=0; i<n; i++){
      dp[i][i][0]=a[i];
      dp[i][i][1]=0;
  }
  
  for(int len=1; len<n; len++){
      for(int left=0; left+len<n; left++){
          int right=left+len;

          dp[left][right][0]=max(a[left]+dp[left+1][right][1], a[right]+dp[left][right-1][1]);
          dp[left][right][1]=min(dp[left+1][right][0], dp[left][right-1][0]);
      }
  }
  int ans=dp[0][n-1][0];
  ans=2*ans-sum;
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
         cout<<setprecision(10);
         cout<<fixed;
        solve();
    }
    return 0;
}
