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
int vis[200010];
int depth[200010];
void dfs(int src){
    vis[src]=1;

    for(int x:edge[src]){
        if(vis[x]) continue;
        depth[x]=1+depth[src];
        up[x][0]=src;
        for(int i=1; i<LOG; i++){
            up[x][i]=up[up[x][i-1]][i-1];
        }
        dfs(x);
    }
}
int get_lca(int a, int b){
    if(depth[b]>depth[a]) swap(a, b);
    
    int depth_diff=depth[a]-depth[b];
    for(int i=0; i<LOG; i++){
        if(depth_diff&(1<<i))
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
void solve(){
     int query;
     cin>>n>>query;

     for(int i=0; i<n-1; i++){
         int src, des;
         cin>>src>>des;

         edge[src].push_back(des);
         edge[des].push_back(src);
     }
     dfs(1);

     while(query--){
         int a, b;
         cin>>a>>b;

         int ans=depth[a]-depth[get_lca(a, b)]+depth[b]-depth[get_lca(a, b)];
         cout<<ans<<"\n";
     }
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