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
unordered_map<int, vector<pi>> edge;
int n;
int dijstra(int src, int des){
    int dis[n+1];
    int vis[n+1];

    for(int i=1; i<=n; i++){
        vis[i]=0;
        dis[i]=inf;
    }
    set<pi> s;
    s.insert({0, src});
    dis[src]=0;

    while(!s.empty()){
        pi p=*(s.begin());
        s.erase(s.begin());

        int node=p.ss;
        if(vis[node]) continue;
        vis[node]=1;

        for(pi children:edge[node]){
            int ndis=p.ff+children.ss;
            if(dis[children.ff]>ndis){
                s.erase({dis[children.ff], children.ff});
                dis[children.ff]=ndis;
                s.insert({ndis, children.ff});
            }
        }
    }
    if(dis[des]==inf) dis[des]=-1;
    return dis[des];
}
void solve(){
    int  m, q;
    cin>>n>>m>>q;
    int dis[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dis[i][j]=inf;
        }
        dis[i][i]=0;
    }

    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        dis[a][b]=min(w, dis[a][b]);
        dis[b][a]=min(w, dis[b][a]);
    }
     for(int k=1; k<=n; k++){
         for(int i=1; i<=n;i++){
             for(int j=1; j<=n; j++){
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
             }
         }
     }
    while(q--){
        int src, des;
        cin>>src>>des;

      //  int ans=dijstra(src, des);
      int ans=dis[src][des];
      if(ans==inf) ans=-1;
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
