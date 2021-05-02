#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pii pair<int, int>
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
unordered_map<int, vector<int>> edge;
auto bfs(int src){
    //int vis[n+1];
    int dis[n+1];
    for(int i=1; i<=n; i++) {
        dis[i]=0;
     //   vis[i]=0;
    }
    queue<pii> q;
    q.push({src, 0});
    dis[src]=0;
    pii x;

    while(!q.empty()){
        x=q.front();
        q.pop();
        int node=x.ff;
      //  vis[node]=1;
        for(int y:edge[node]){
            if(dis[y]==0 && y!=src){ 
            dis[y]=1+dis[node];
            q.push({y, dis[y]});}
        }
    }
    return x;
}
void solve(){
      //int n;
      cin>>n;
 
      for(int i=0; i<n-1; i++){
          int a, b;
          cin>>a>>b;
 
          edge[a].push_back(b);
          edge[b].push_back(a);
      }
      auto x=bfs(1);
      auto ans=bfs(x.ff);
      cout<<ans.ss<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   //tree cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}