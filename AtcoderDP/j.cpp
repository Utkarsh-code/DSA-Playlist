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

double dp[301][301][301];
void solve(){
   int n;
   cin>>n;

   int cnt[4]={0};
   for(int i=0; i<n; i++){
       int num;
       cin>>num;

       cnt[num]++;
   }
 //  memset(dp, 0, sizeof(dp));
   dp[0][0][0]=0;

   for(int i=0; i<=n; i++){
      for(int j=0; j<=n; j++){
          for(int k=0; k<=n; k++){
              int zero=n-i-j-k;
              if(zero==n) continue;

              if((i+j+k)>n) continue;

              double val=1;
              //pick 3's cut 
             if(i>0) val+=(1.0*i/n)*dp[i-1][j+1][k];
              //pick 2's  cut 
             if(j>0) val+=(1.0*j/n)*dp[i][j-1][k+1];
              //pick 1's cut 
             if(k>0) val+=(1.0*k/n)*dp[i][j][k-1];

             dp[i][j][k]=val/(1-1.0*zero/n);

          }
      }
   }
    cout<<setprecision(9);
         cout<<fixed;
   cout<<dp[cnt[3]][cnt[2]][cnt[1]]<<"\n";
         
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        // cout<<setprecision(10);
        // cout<<fixed;
         solve();
    }
    return 0;
}
