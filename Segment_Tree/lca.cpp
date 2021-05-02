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
int depth[200010];
int f[200010];
int la[200010];
int has[200010];
int near[200010];
void dfs(int src, int par){
        
        has[src]|=f[src];
        int sp=0;
    for(int x:edge[src]){
        if(par==x) continue;
        depth[x]=1+depth[src];
        up[x][0]=src;

        for(int i=1; i<LOG; i++){
            up[x][i]=up[up[x][i-1]][i-1];
        }
        dfs(x, src);
        has[src]|=has[x];
        if(has[x]==1) sp=la[x];
    }
    if(f[src]==1) la[src]=src;
    else la[src]=sp;

}
int get_lca(int a, int b){
    if(depth[b]>depth[a]) swap(a, b);
    
    int depth_diff=depth[a]-depth[b];
    for(int i=0; i<LOG; i++){
        if(depth_diff&(1<<i))
        a=up[a][i];
    }

    if(a==b) return a;

   /* while(a!=b){           
       a=up[a][0];
       b=up[b][0];
    }*/
    
    for(int i=LOG-1; i>=0; i--){
         if(up[a][i]!=up[b][i]){
         a=up[a][i];
         b=up[b][i];}
    }
    return up[a][0];
}
void dfs2(int src, int par){
    if(has[src]==1) near[src]=src;
    else near[src]=near[par];

    for(auto i:edge[src]){
        if(i==par) continue;
        dfs2(i, src);
    }
}
void solve(){
     int k, a;
     cin>>n>>k>>a;
      
     // int f[n+1];
      for(int i=0; i<=n; i++){
          edge[i].clear();
          has[i]=0;
          near[i]=0;
          la[i]=0;
          f[i]=0;
      }
     for(int i=0; i<k; i++){
         int num;
         cin>>num;
         //edge[num].push_back(i);
         f[num]=1;
     }
     edge.clear();
     for(int i=0; i<n-1; i++){
         int x, b;
         cin>>x>>b;

         edge[x].push_back(b);
         edge[b].push_back(x);
     }
     depth[a]=0;
     dfs(a, 0);
     dfs2(a, 0);
     int dis[n+1];
     int  node[n+1];
     for(int i=1; i<=n; i++){
        
         int ans=2*depth[near[i]]-depth[i];
         dis[i]=ans;
         node[i]=la[near[i]];
     }
     /*for(int i=1; i<=n; i++){
           int ans=ninf, sp=-1;
           for(int u:f){
               int distance=depth[a]-2*depth[get_lca(a, u)] -(depth[i]-2*depth[get_lca(i, u)]);

               if(ans<distance){
                   ans=distance;
                   sp=u;
               }
           }
           dis[i]=ans;
           node[i]=sp;
     }*/
     for(int i=1; i<=n; i++) cout<<dis[i]<<" ";
     cout<<"\n";
     for(int i=1; i<=n; i++) cout<<node[i]<<" ";
     cout<<"\n";
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