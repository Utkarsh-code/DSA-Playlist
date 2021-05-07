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
unordered_map<int, vector<int>> edge;
int dis[100010];
int vis[100010];
int n;
void dfs(int src){
    
    vis[src]=1;
    if(src==n){
        dis[src]=1;
        return;
    }
    int ans=0;
    for(int i:edge[src]){
        if(!vis[i]) dfs(i);

        if(dis[i]==-1) continue;
        ans=(ans+mod+ dis[i])%mod;
    }
    if(ans!=0) dis[src]=ans;
}
void solve(){
    int  m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
    }
    memset(dis, -1, sizeof(dis));
    dfs(1);
    if(dis[1]==-1) dis[1]=0;
    cout<<dis[1]<<"\n";
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
