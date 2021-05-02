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
int vis[200010];
unordered_map<int, vector<int>> edge;
int dp[200010];
void dfs(int node){
    vis[node]=1;
    
    dp[node]=0;
    int ans=0;
    for(int x:edge[node]){
        if(!vis[x]) dfs(x);
        ans+=dp[x];
    }
    ans++;
    dp[node]=ans;
}
void solve(){
      int n;
      cin>>n;

      for(int i=2; i<=n; i++){
          int num;
          cin>>num;

          edge[num].push_back(i);
      }
      dfs(1);
      for(int i=1; i<=n; i++) cout<<dp[i]-1<<" ";
      cout<<"\n";
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
