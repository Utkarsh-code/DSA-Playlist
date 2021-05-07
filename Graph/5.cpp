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
void dfs(int src, int par){

    for(int x:edge[src]){
        if(x==par) continue;
        dis[x]=1+dis[src];
        dfs(x, src);
    }
}
void solve(){
    int n, k;
    cin>>n>>k;
    edge.clear();
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int a[k];
    for(int i=0; i<k; i++){
        cin>>a[i];
    }
    memset(dis, 0, sizeof(dis));
    dfs(a[0], -1);
    //for(int i=1; i<=n; i++) cout<<dis[i]<<" ";
    set<int> s;
    for(int i=0; i<k; i++){
        s.insert(dis[a[i]]%2);
    }
    if(s.size()!=1){
        cout<<"-1\n";
        return;
    }
   // memset(dis, 0, sizeof(dis));
   // dfs(a[0], -1);
    //for(int i=1; i<=n; i++) cout<<dis[i]<<" ";
    int mx=ninf;
    int node=1;
    for(int i=0; i<k; i++){
        if(dis[a[i]]>mx){
            mx=dis[a[i]];
            node=a[i];
        }
    }
    memset(dis, 0, sizeof(dis));
    dfs(node, -1);
   // for(int i=1; i<=n; i++) cout<<dis[i]<<" ";
   int ans=ninf;
    for(int i=0; i<k; i++){
        ans=max(ans, dis[a[i]]);
    }
    cout<<ans/2<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
