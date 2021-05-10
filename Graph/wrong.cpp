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
vector<vector<int>> dis;
int n, k;
void dijkstra(int src, int des){
    priority_queue<pi, vector<pi>, greater<pi>> s;
    s.push({0, 1});

   // for(int i=0; i<k; i++){
   //     dis[src][i]=0;
   // }
    dis[1][0]=0;
    while(!s.empty()){
        pi p=s.top();
        s.pop();

        int d=p.ff;
        int node=p.ss;
        if(dis[node][k-1]<d) continue;
        //if(vis[node]) continue;
        //vis[node]=1;

        for(pi nbr:edge[node]){
            int nxnode=nbr.ff;
            int c=nbr.ss;
            //if(dis[node][k-1]<d) continue;
            if(dis[nxnode][k-1]>c+d){
                
                dis[nxnode][k-1]=c+d;
                s.push({dis[nxnode][k-1], nxnode});
                sort(dis[nxnode].begin(), dis[nxnode].end());
            }
        }
    }
}
void solve(){
    int  m;
    cin>>n>>m>>k;
    
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        edge[a].push_back({b, w});
    }
    dis.resize(n+1);
    for(int i=1; i<=n; i++){
        dis[i].resize(k);
        for(int j=0; j<k; j++){
            dis[i][j]=inf;
        }
    }
    dijkstra(1, n);

    for(int i=0; i<k; i++){
        cout<<dis[n][i]<<" ";
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
