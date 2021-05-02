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
unordered_map<int, vector<int>> edge;
int dp[100010][2];

int dfs(int node, int color, int par){
    if(dp[node][color]!=-1) return dp[node][color];

    int total=1;
    for(int nxnode:edge[node]){
        if(nxnode!=par){
             if(color==1) total=(total*((dfs(nxnode, 1, node)+dfs(nxnode, 0, node))))%mod;
             else total=(total*(dfs(nxnode,1, node)))%mod;
        }
    }
    return dp[node][color]=total;
}
void solve(){
  int n;
  cin>>n;

  for(int i=0; i<n-1; i++){
      int a, b;
      cin>>a>>b;

      edge[a].push_back(b);
      edge[b].push_back(a);
  }     
         memset(dp,-1, sizeof(dp));
         int ans=dfs(1, 0, -1);
         ans=(ans+dfs(1,1, -1))%mod;
         cout<<ans<<"\n";
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
