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
vector<int> g[100010][2];
vector<int> arr;
int vis[100010];
int ans[100010];
int cnt=0;
void dfs(int src, int x){
    vis[src]=1;

    for(int i:g[src][x]){
        if(!vis[i]) dfs(i, x);
    }

    if(x==0) arr.push_back(src);
    else{
         ans[src]=cnt;
    }
}
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        g[a][0].push_back(b);
        g[b][1].push_back(a);
    }
    
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    
    memset(vis, 0, sizeof(vis));
    cnt=0;
    for(int i=1; i<=n; i++){
        if(!vis[arr[n-i]]){
            cnt++;
            dfs(arr[n-i], 1);
        }
    }
    cout<<cnt<<"\n";
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
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
