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
int route[100010];
int min_r[100010];
int max_r[100010];
int dis[100010];
int vis[100010];
int n;
void dijsktra(int src, int des){
    for(int i=1; i<=n; i++){
        dis[i]=inf;
        min_r[i]=inf;
        max_r[i]=ninf;
        vis[i]=0;
        route[i]=1;
    }
    set<pi> s;
    s.insert({0, src});
    dis[src]=0;
    min_r[src]=0;
    max_r[src]=0;
    while(!s.empty()){
        pi p=*(s.begin());
        s.erase(s.begin());

        int d=p.ff;
        int node=p.ss;

       // if(vis[node]) continue;
       // vis[node]=1;

        for(pi nbr:edge[node]){
            int nxnode=nbr.ff;
            int c=nbr.ss;

            if(dis[nxnode]<d+c) continue;
            else if(dis[nxnode]==d+c){
                route[nxnode]=(route[nxnode]+route[node]+mod)%mod;
                min_r[nxnode]=min(min_r[nxnode], min_r[node]+1);
                max_r[nxnode]=max(max_r[nxnode], max_r[node]+1);
            }
            else if(dis[nxnode]>c+d){
                s.erase({dis[nxnode], nxnode});
                dis[nxnode]=c+d;
                s.insert({dis[nxnode], nxnode});
                route[nxnode]=route[node];
                min_r[nxnode]=1+min_r[node];
                max_r[nxnode]=1+max_r[node];
            }
        }
    }
}
void solve(){
    int  m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        edge[a].push_back({b, w});
    }
    dijsktra(1, n);
    cout<<dis[n]<<" "<<route[n]<<" "<<min_r[n]<<" "<<max_r[n]<<"\n";
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
