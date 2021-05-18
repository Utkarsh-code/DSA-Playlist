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
int color[100010];
int vis[100010];
unordered_map<int, set<int>> col;
unordered_map<int, vector<int>> edge;
int mx=ninf;
int ans=inf;

void dfs(int v, int vis[]){
     vis[v]=1;
     int x=color[v];
     for(int i:edge[v]){
            if(color[i]!=x) col[x].insert(color[i]);

            if(!vis[i]) dfs(i, vis);
     }

     if(col[x].size()>mx){
         mx=col[x].size();
         ans=x;
     }

     else if(col[x].size()==mx  && x<ans){
         ans=x;
     }
}
void solve(){
     int n, m;
     cin>>n>>m;

     for(int i=1; i<=n; i++) cin>>color[i];

     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
     }
     memset(vis, 0, sizeof(vis));
     for(int i=1; i<=n; i++){
         if(!vis[i]) dfs(i, vis);
     }
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}