#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

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

void solve(){
    int k,n,m;
    cin>>k>>n>>m;

    unordered_map<int, vector<pii>> adj;
    for(int i=0; i<m; i++){
        int src, des, len, cost;
        cin>>src>>des>>len>>cost;

        adj[src].push_back(make_pair(des, make_pair(len ,cost)));
    }
       int vis[n+1][k+1];
       memset(vis, 0, sizeof(vis));
        int dis[n+1][k+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=k; j++){
                dis[i][j]=inf;
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, make_pair(1, k)));
        dis[1][k]=0;
        while(!pq.empty()){
            auto p=pq.top();
             pq.pop();

             int node=p.second.first;
             int len=p.first;
             int cost=p.second.second;

             if(vis[node][cost]) continue;
             vis[node][cost]=1;

             for(auto i:adj[node]){
                 int nlen=len+i.second.first;
                 int ncost=i.second.second;
                 int nxnode=i.first;

                 if(ncost<=cost && dis[nxnode][cost-ncost]>nlen){
                     dis[nxnode][cost-ncost]=nlen;
                     pq.push(make_pair(nlen, make_pair(nxnode, cost-ncost)));
                 }
             }
             //vis[node]=0;
        }
        //for(int i=0; i<=n; i++) cout<<dis[i]<<" ";
        int ans=inf;
        for(int i=0; i<=k; i++){
            if(dis[n][i]<ans) {ans=dis[n][i];}
        }
        //int ans=dis[n][0];
        if(ans==inf) ans=-1;

        cout<<ans<<"\n";
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
