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
int vis[100010];
vector<int> ans;
int backtrack=0, backnode=-1, cycle_mila=0;
void dfs(int src, int cnt, int par){
    vis[src]=cnt;

    for(int nbr:edge[src]){
        if(nbr==par) continue;

        if(vis[nbr]==-1) dfs(nbr, cnt+1, src);
        else{
            int cycle_size=(cnt+1)-vis[nbr];
            ans.push_back(nbr);
            ans.push_back(src);
            if(cycle_size>=2){
              cycle_mila=1;
              backnode=nbr;
              backtrack=1;
              return;
            }
        }

        if(backtrack){
            ans.push_back(src);
            if(src==backnode) backtrack=0;
        }
        if(cycle_mila) return;
    }
    //if(cycle_mila) return;
}
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    memset(vis, -1, sizeof(vis));
    for(int i=1; i<=n; i++){
        if(vis[i]==-1){
            dfs(i,0, -1);
            if(cycle_mila) break;
        }
    }
    if(cycle_mila==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<ans.size()<<"\n";
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<"\n";
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
