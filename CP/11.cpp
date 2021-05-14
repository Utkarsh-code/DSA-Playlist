#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pi pair<int, int>
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
int ed=0, ver=0, fl=1;
void dfs(int v, int vis[]){
    vis[v]=1;
    ver++;
    ed+=edge[v].size();
    if((edge[v].size())&1) fl=0;
    for(int i:edge[v]){
        if(!vis[i]) dfs(i, vis);
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
     int ans=0;
     for(int i=1; i<=n; i++){
         if(!vis[i]){
             ed=0;
             ver=0;
             fl=1;
             dfs(i, vis);
             ed=ed/2;
             if(fl) ans++;
         }
     }
     cout<<ans<<"\n";
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