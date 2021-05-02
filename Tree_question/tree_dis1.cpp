#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pii pair<int, int>
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
unordered_map<int, vector<int>> edge;
int ans[200010];
int bfs(int src){
    //int vis[n+1]={0};
    int dis[n+1]={0};
    queue<pii> q;
    q.push({src, 0});
    dis[src]=0;
    int x;

    while(!q.empty()){
        auto p=q.front();
        q.pop();

        x=p.ff;
       // if(vis[x]) continue;
       // vis[x]=1;

        for(int nxnode:edge[x]){
            if(!dis[nxnode] && nxnode!=src){
            dis[nxnode]=1+dis[x];
            q.push({nxnode, dis[nxnode]});
            ans[nxnode]=max(ans[nxnode], dis[nxnode]);}
        }
    }
    return x;
}
void solve(){
     //int n;
     cin>>n;

     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }
     int diameter1=bfs(1);
    int diameter2=bfs(diameter1);
    bfs(diameter2);
    
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   //tree cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}