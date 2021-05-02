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
#define LOG 18
int n;
unordered_map<int, vector<int>> edge;
int up[200010][LOG];
int dis[200010];
int prefix[200010]={0};
int vis[200010];
void dfs(int src){
   vis[src]=1;

   for(int x:edge[src]){
       if(vis[x]) continue;
       dis[x]=1+dis[src];
       up[x][0]=src;

       for(int i=1; i<LOG; i++){
           up[x][i]=up[up[x][i-1]][i-1];
       }
       dfs(x);
   }
}
int get_lca(int a, int b){
    if(dis[b]>dis[a]) swap(a, b);

    int dis_diff=dis[a]-dis[b];
    for(int i=0; i<LOG; i++){
        if(dis_diff&(1<<i))
        a=up[a][i];
    }

    if(a==b) return a;

    for(int i=LOG-1; i>=0; i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
void dfs_prefixsum(int src){
    vis[src]=1;

    for(int x:edge[src]){
        if(!vis[x]){ 
        dfs_prefixsum(x);
        prefix[src]+=prefix[x];}
    }
}
void solve(){
     int m;
     cin>>n>>m;

     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }

         dfs(1);

         while(m--){
         int a, b;
         cin>>a>>b;

         prefix[a]++;
         prefix[b]++;

         int lca=get_lca(a, b);
         prefix[lca]--;
         prefix[up[lca][0]]--;
     }
     memset(vis, 0, sizeof(vis));
    // for(int i=1; i<=n; i++) cout<<prefix[i]<<" ";
     dfs_prefixsum(1);

     for(int i=1; i<=n; i++) cout<<prefix[i]<<" ";
     cout<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}