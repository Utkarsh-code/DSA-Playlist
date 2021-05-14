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
int n;
unordered_map<int, vector<pi>> edge;
void dijkstra(int src){
    int vis[n+1];
    int dis[n+1];

    for(int i=0; i<=n; i++){
        dis[i]=inf;
        vis[i]=0;
    }

    set<pi> s;
    s.insert({0, src});
    dis[src]=0;
    
    while(!s.empty()){
        pi x=*(s.begin());
        s.erase(s.begin());

        int u=x.ss;
        int d=x.ff;

        if(vis[u]) continue;
        vis[u]=1;

        for(pi v:edge[u]){
             int c=v.ss;
             int ch=v.ff;

             if(dis[ch]>c+dis[u]){
                 s.erase({dis[ch], ch});
                 dis[ch]=c+dis[u];
                 s.insert({dis[ch], ch});
             }
        }
    }
    for(int i=1; i<=n; i++)  cout<<dis[i]<<" ";
}
void solve(){
    int  m, q;
    cin>>n>>m>>q;

    int val[n+1];
    val[0]=0;
    for(int i=1; i<=n; i++) cin>>val[i];

    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        edge[a].pb({b, w});
        edge[b].pb({a, w});
    } 

    for(int i=1; i<=n; i++){
        edge[i].pb({0, val[i]});
        edge[0].pb({i, val[i]});
    }

    while(q--){
        int src;
        cin>>src;
        dijkstra(src);
       // for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
        cout<<"\n";
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