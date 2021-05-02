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
/*int n;
int man[1000], woman[1000];
int grid[1000][1000];
int ans=0;
bool check(){
    for(int i=0; i<n; i++){
        if(man[i]==0 || woman[i]==0) return false;
    }
    return true;
}
void cnt_pair(int x, int y){
    if(x>=n){
     if(check()) {  ans=(ans+1)%mod;}
        return;
    }
    for(int i=0; i<n; i++)
    if(grid[x][i]==1 && man[x]==0 && woman[i]==0){
          man[x]=1;
          woman[i]=1;
          cnt_pair(x+1, 0);
          man[x]=0;
          woman[i]=0;
    }
}*/
/*void add(int& a, int b){
    a+=b;
    if(a>=mod)
    a-=mod;
}*/
int n;
int grid[23][23];
int dp[(1<<23)];
int bitmaskdp(int mask){
    int cnt=__builtin_popcount(mask);
    if(cnt==n) return dp[mask]=1;
    if(dp[mask]!=-1) return dp[mask];
    int ans=0;
    for(int i=0; i<n; i++){
        if(mask&(1<<i)==0 && grid[cnt][i]){
            ans+=bitmaskdp(mask|(1<<i));
        }
    }
    return dp[mask]=ans;
}
void solve(){
   cin>>n;

  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cin>>grid[i][j];
      }
  } 
   // recursive dp
   memset(dp, -1, sizeof(dp));
  // dp[0]=1;
   int ans=bitmaskdp(0);  // not correct 
   //ans=dp[(1<<n)-1];
   cout<<ans<<"\n";

   //iterative dp
   /*int dp[1<<n]={0};
   dp[0]=1;

   for(int mask=0; mask<(1<<n)-1; mask++){
       int a=__builtin_popcount(mask);
      // a=n-a;
       for(int b=0; b<n; b++){
           if(grid[a][b] && (mask&(1<<b))==0){
               int new_mask=(mask)|(1<<b);
               dp[new_mask]=(dp[mask]+dp[new_mask])%mod;
           }
       }

   } 
   cout<<dp[(1<<n) -1]<<"\n";*/
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
