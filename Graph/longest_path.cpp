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
int dis[100010]={0};
unordered_map<int, vector<int>> edge;
map<int, int> par;
int vis[100010]={0};
int n;
void dfs(int src, int pa){

    vis[src]=1;
    if(src==n){
        dis[src]=0;
        return;
    }
    for(int i:edge[src]){
        
        if(!vis[i])
            dfs(i, src);
        
        if(dis[i]==-1) continue;
        if(dis[src]<1+dis[i]){
            dis[src]=1+dis[i];
            par[src]=i;
        }
    }
}
void solve(){
    int  m;
    cin>>n>>m;
    
    int indegree[n+1]={0};
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        indegree[b]++;
    }
    memset(dis, 0, sizeof(dis));
    dfs(1, -1);
    //par[1]=-1;
    /*queue<int> q;
    for(int i=1; i<=n; i++){
        dis[i]=ninf;
      //  if(indegree[i]==0){ q.push(i); dis[i]=0;}
    }
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();

        if(vis[x]) continue;
        vis[x]=1;

        for(int i:edge[x]){
           if(dis[i]<dis[x]+1){
               dis[i]=dis[x]+1;
               par[i]=x;
           
           //indegree[i]--;
           //if(indegree[i]==0)
            q.push(i);}
        }
    }*/
    if(vis[n]==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
   // cout<<dis[1]+1<<"\n";
   int x=1;
   vector<int> ans;
    while(x!=n){
        ans.push_back(x);
        x=par[x];
    }
    ans.push_back(n);
   // reverse(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i:ans){
        cout<<i<<" ";
    }
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
