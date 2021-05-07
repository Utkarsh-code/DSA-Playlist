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
unordered_map<int, vector<pi>> edge;
unordered_map<int, vector<pi>> redge;
int len[200010];
int rlen[200010];
int n;
void dijsktra(int src, int des, int bit){
    if(bit==1) edge=redge;
    int dis[n+1];
    int vis[n+1];
    for(int i=0; i<=n; i++){
        dis[i]=inf;
        vis[i]=0;
    }
    set<pi> q;
    q.insert({0, src});
    dis[src]=0;
    
    while(!q.empty()){
        pi x=*(q.begin());
        q.erase(q.begin());

        if(vis[x.second]) continue;
        vis[x.second]=1;

        for(pi i:edge[x.second]){
            int nxnode=i.first;
            int d=i.second;

            if(dis[nxnode]>d+x.first){
                q.erase({dis[nxnode], nxnode});
                dis[nxnode]=d+x.first;
                q.insert({dis[nxnode],nxnode});
            }
        }
    }
    if(bit==1){
        for(int i=1; i<=n; i++) rlen[i]=dis[i];
        return;
    }
    for(int i=1; i<=n; i++) len[i]=dis[i];
    return;
}
void solve(){
    int  m;
    cin>>n>>m;
    unordered_map<int, vector<pi>> nedge;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        nedge[a].push_back({b, w});
        edge[a].push_back({b, w});
        redge[b].push_back({a, w});
    }
    dijsktra(1, n, 0);
    dijsktra(n, 1, 1);
    
    for(int i=1; i<=n; i++){
   //     cout<<len[i]<<" "<<rlen[i]<<"\n";
    }
    int j=1;
    int ans=inf;
    while(j<=n){
        for(pi i:nedge[j]){
            ans=min(ans, len[j]+rlen[i.first]+((i.second)/2));
           // cout<<ans<<" ";
        }
        j++;
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
        solve();
    }
    return 0;
}
