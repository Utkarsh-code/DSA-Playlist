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
int val[100010];
int vis[100010];
int mxcoin[100010];
unordered_map<int, vector<int>> edge;
unordered_map<int, vector<int>> g;
unordered_map<int, vector<int>> con_g;
vector<int> arr;
int comp[100010];
int comp_sum[100010];
int cnt=0;
void dfs2(int src){
    vis[src]=1;
    comp[src]=cnt;
    comp_sum[cnt]+=val[src];
    for(int i: g[src]){
        if(!vis[i]) dfs(i);
    }
}

void dfs(int src){
    vis[src]=1;

    for(int i: edge[src]){
        if(!vis[i]) dfs2(i);
    }
    arr.push_back(src);
}

void solve(int src){
    vis[src]=1;

    for(int i:con_g[src]){
        if(!vis[i]) solve(i);

        mxcoin[src]=max(mxcoin[src], mxcoin[i]+comp_sum[src]);
    }
}
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) {cin>>val[i]; }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    memset(vis, 0, sizeof(vis));
    cnt=0;
    for(int i=1; i<=n; i++){
        if(!vis[arr[n-i]]){ cnt++; dfs2(arr[n-i]);}
    }
    
    for(int i=1; i<=n; i++){
        for(int j:edge[i]){
            if(comp[i]==comp[j]) continue;
            con_g[comp[i]].push_back(comp[j]);
        }
    }

    for(int i=1; i<=cnt; i++) { mxcoin[i]=comp_sum[i];}

    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=cnt; i++){
        if(!vis[i]){
            solve(i);
        }
    }

    int ans=*max_element(mxcoin, mxcoin+n+1);
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
