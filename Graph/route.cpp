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
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        edge[a].push_back({b, w});
       // edge[b].push_back({a, w});
    }

    int dis[n+1];
    int vis[n+1]={0};
    for(int i=0; i<=n; i++) dis[i]=inf;
    dis[1]=0;

    set<pi> s;
    s.insert({0, 1});

    while(!s.empty()){
        pi p=*(s.begin());
        s.erase(s.begin());

        int node=p.second;
        if(vis[node]) continue;
        vis[node]=1;

        for(pi child:edge[node]){
            int ndis=p.first+child.second;
            if(dis[child.first]>ndis){
                s.erase({dis[child.first], child.first});
                dis[child.first]=ndis;
                s.insert({ndis, child.first});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<dis[i]<<" ";
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
