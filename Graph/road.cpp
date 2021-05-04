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
void dfs(int src, int vis[]){
    vis[src]=1;

    for(int x:edge[src]){
        if(!vis[x]) dfs(x, vis);
    }
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
    int vis[n+1]={0};
    vector<int> ans;
    for(int i=1;i<=n; i++){
        if(!vis[i]){
            dfs(i, vis);
            ans.push_back(i);
        }
    }
    int p=ans.size()-1;
    cout<<p<<"\n";
    if(p!=0){
        for(int i=0; i<p; i++){
            cout<<ans[i]<<" "<<ans[i+1]<<"\n";
        }
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
