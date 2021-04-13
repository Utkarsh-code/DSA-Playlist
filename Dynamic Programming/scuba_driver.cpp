#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

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
int dp[1010][51][91];
int driver(int idx, vector<vector<int>>&arr, int ox, int ni){
     // if(idx>=arr.size()) return 0;
      if(ox<=0 && ni<=0) return 0;
      if(idx<0) return inf;
      if(ox<=0) return inf;
      if(ni<=0) return inf;
     // if(dp[idx][ox][ni]!=-1) return dp[idx][ox][ni];

    int w=arr[idx][2];
    int o=arr[idx][0];
    int n=arr[idx][1];
    return min(driver(idx-1, arr, ox, ni), driver(idx-1, arr, ox-o, ni-n)+w);
}
void solve(){

        int ox, ni;
        cin>>ox>>ni;

        int n;
        cin>>n;

        vector<vector<int>> arr(n, vector<int>(3, 0));
        for(int i=0; i<n; i++){
            int o, n, w;
            cin>>o>>n>>w;

            arr[i][0]=o;
            arr[i][1]=n;
            arr[i][2]=w;
        }
        memset(dp, 63, sizeof(dp));
        int ze=0;
        dp[0][0][0]=0;
       // int ans=driver(n-1, arr, ox, ni);
       for(int i=1; i<=n; i++){
           for(int j=0; j<=ox; j++){
               for(int k=0; k<=ni; k++){
                   dp[i][j][k]=min(dp[i-1][j][k], arr[i-1][2]+dp[i-1][max(ze, j-arr[i-1][0])][max(ze, k-arr[i-1][1])]);
               }
           }
       }
       // cout<<ans<<"\n";
       cout<<dp[n][ox][ni]<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
