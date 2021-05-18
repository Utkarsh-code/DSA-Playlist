#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pi pair<int, int>
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
int cost[100010];
int vis[100010];
int mncost=inf;
int cnt=0;
vector<int> arr;
unordered_map<int, vector<int>> edge;
unordered_map<int, vector<int>> redge;

void dfs(int v, int vis[]){
    vis[v]=1;

    for(int i:edge[v]){
        if(!vis[i]) dfs(i, vis);
    }
     arr.pb(v);
}

void dfs2(int v, int vis[]){
    vis[v]=1;
    if(mncost>cost[v]){
        mncost=cost[v];
        cnt=1;
    }

    else if(mncost==cost[v]) cnt++;

    for(int i:redge[v]){
        if(!vis[i]) dfs2(i, vis);
    }
}
void solve(){
      int n;
      cin>>n;

      for(int i=1; i<=n; i++) cin>>cost[i];

      int m;
      cin>>m;

      for(int i=0; i<m; i++){
          int a, b;
          cin>>a>>b;

          edge[a].pb(b);
          redge[b].pb(a);
      }

      memset(vis, 0, sizeof(vis));
      for(int i=1; i<=n; i++){
          if(!vis[i]){
              dfs(i, vis);
          }
      }
      
      int ans=0;
      int mul=1;
      memset(vis, 0, sizeof(vis));
      for(int i=1; i<=n; i++){
          if(!vis[arr[n-i]]){
              mncost=inf;
              cnt=0;
              dfs2(arr[n-i], vis);
              ans+=mncost;
              mul=(mul*cnt)%mod;
          }
      }
      
      cout<<ans<<" "<<mul<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}