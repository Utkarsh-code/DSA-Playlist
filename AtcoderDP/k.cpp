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
int dp[100010];
void solve(){
  int n, k;
  cin>>n>>k;

  vector<int> a(n);
  for(int i=0; i<n; i++){
      int num;
      cin>>num;

      a[i]=num;
  }
     dp[0]=0;
     for(int i=1; i<=k; i++){
         for(int x:a){
             if(i>=x && dp[i-x]==0){
                 dp[i]=1;
             }
         }
     }  
     if(dp[k]==1) cout<<"First\n";
     else cout<<"Second\n";  
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
