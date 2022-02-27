#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define ff first
#define ss second
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
map<int, vector<int>> graph;
int tim=0, ans=0;

void dfs(int v, int par, int vis[], int intime[], int low[]){

    int child=0;
    vis[v]=1;
    low[v]=intime[v]=++tim;
    int ok=0;

    for(int i:graph[v]){

        if(!vis[i]){
            child++;
            dfs(i, v, vis, intime, low);

            low[v]=min(low[v], low[i]);

            if(par!=-1  && low[i]>=intime[v]) ok=1;
        }
        else if(par!=i){
            low[v]=min(low[v], intime[i]);
        }
    }

    if((par==-1 && child>1) || ok==1) ans++;
}
void solve(){
    graph.clear();
    tim=0;
    ans=0;

     int n;
     cin>>n;

     int m;
     cin>>m;

     for(int i=0; i<m; i++){
         int u, v;
         cin>>u>>v;

         graph[u].push_back(v);
         graph[v].push_back(u);
     }

     int vis[n]={0}, intime[n], low[n];

     for(int i=0; i<n; i++){
         if(!vis[i]){
             dfs(i, -1, vis, intime, low);
         }
     }
     
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
