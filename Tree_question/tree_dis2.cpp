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
int vis[200010];
int in[200010];
int ans[200010];
int sub[200010];
void dfs_in(int node){
    vis[node]=1;
    
    sub[node]=1;
    in[node]=0;
    for(int x:edge[node]){
        if(!vis[x]) {dfs_in(x);
        sub[node]+=sub[x];
        in[node]+=(sub[x]+in[x]);}
    }
    
}
void dfs_ans(int src, int par_val){
    vis[src]=1;
    ans[src]=in[src]+par_val+n-sub[src];

    for(int x:edge[src]){
        if(!vis[x])
        dfs_ans(x, ans[src]-(in[x]+sub[x]));
    }
}
void solve(){
    
     cin>>n;
     
     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }
    
    dfs_in(1);
    memset(vis, 0, sizeof(vis));
    dfs_ans(1, 0);
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
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