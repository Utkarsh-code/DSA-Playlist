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
vector<int> adj[100010][2];
int vis[100010];

void dfs(int node, int x){
    vis[node]=1;

    for(int i:adj[node][x]){
        if(!vis[i]) dfs(i, x);
    }
}
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, 0);
    
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(cnt==0) {cout<<"NO\n"; cnt++;}
            cout<<1<<" "<<i<<"\n";
        }
    }

    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(cnt==0){ cout<<"NO\n"; cnt++;}
            cout<<i<<" "<<1<<"\n";
        }
    }

    if(cnt==0) cout<<"YES\n";
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
