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
int id[200010];
int sz[200010];

int find(int x){
    while(x!=id[x]) x=id[x];
    return x;
}

void unite(int x, int y){
    x=find(x);
    y=find(y);

    if(sz[x]<sz[y]) swap(x, y);
    sz[x]+=sz[y];

    id[y]=x;
}
unordered_map<int, vector<int>> edge;
int fl=0;
int ver=0, ed=0;
void dfs(int v, int vis[], int par){
     vis[v]=1;
     ver++;
     ed+=edge[v].size();
     for(int i:edge[v]){
        // if(i==par) continue;
        // if(vis[i]) fl=1;

         if(!vis[i]) dfs(i, vis, v);
     }
}
void solve(){
     int n, m;
     cin>>n>>m;
    for (int i = 1; i <=n; i++)
    {
        /* code */
        id[i]=i;
        sz[i]=1;
    }
    
     set<int> s;
     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
         if(find(a)==find(b)) s.insert(find(a));
         else{
             unite(a, b);
         }
     }
     int cnt=0;
      fl=0;
     int vis[n+1]={0};
      for(int i=1; i<=n; i++){
          if(!vis[i]){
              fl=0;
              ver=0;
              ed=0;
              dfs(i, vis, -1);
              ed=ed/2;
              if((ver-1)==(ed)) cnt++;
          }
      }
      cout<<cnt<<"\n";
      return;
      int ans=0;
     for(int i=1; i<=n; i++){
         if(find(i)==i){
             if(s.find(i)==s.end()) ans++;
         }
     }

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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}