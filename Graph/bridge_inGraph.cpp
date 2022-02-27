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
int ans=0;
int tim=0;

void dfs(int v, int vis[], int intime[], int low[], int par[]){
    vis[v]=1;
    low[v]=intime[v]= ++tim;

    for(int i:graph[v]){

        if(!vis[i]){
            par[i]=v;
            dfs(i, vis, intime, low, par);
            low[v]=min(low[v], low[i]);

            if(low[i]>intime[v]) ans++;
        }
        else if(par[v]!=i) low[v]=min(low[v], intime[i]);
    }
}
void solve(){
       graph.clear();
       ans=0; 
       tim=0;

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

       int intime[n], par[n], low[n];
       int vis[n]={0};

       for(int i=0; i<n; i++){
           if(!vis[i]){
               dfs(i, vis, intime, low, par);
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

/* 

Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();
*/
