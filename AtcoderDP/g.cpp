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
int dis[100010]={0};
int vis[100010];
map<int, vector<int>> edge;
void dfs(int i){
   
   vis[i]=1;

    for(auto nxnode:edge[i]){
      if(vis[nxnode]==0) dfs(nxnode);
      dis[i]=max(dis[i], 1+dis[nxnode]);
    }
}
void solve(){
  int n, m;
  cin>>n>>m;
  int indegree[n+1]={0};
  for(int i=0; i<m; i++){
      int a, b;
      cin>>a>>b;

      edge[a].push_back(b);
      indegree[b]++;
  }
  /*memset(vis, 0, sizeof(vis));
  for(int i=1; i<=n; i++){
      if(vis[i]==0)
      dfs(i);
  }
    int ans=*max_element(dis, dis+n+1);
    cout<<ans<<"\n";  */
    
    queue<int>q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) {q.push(i); dis[i]=0;}
    } 

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto i:edge[x]){
           indegree[i]--;
           if(dis[i]<1+dis[x])
           dis[i]=1+dis[x];
           if(indegree[i]==0) q.push(i);
        }
    }
    int ans=*max_element(dis, dis+n+2);
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
