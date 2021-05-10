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
int rec[2510];
int vis[2510];
unordered_map<int, vector<pi>> edge;
bool detect_cycle(int src){
    rec[src]=1;
    vis[src]=1;

    for(pi i:edge[src]){
        int nxnode=i.first;
        if(!vis[nxnode] && detect_cycle(nxnode)) return true;
        else if(rec[nxnode]) return true;
    }
    rec[src]=0;
    return false;
}
void solve(){
    int n , m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        edge[a].push_back({b, -w});
    
    }
   
   int dis[n+1];
   for(int i=0; i<=n; i++) dis[i]=inf;
   dis[1]=0;

   for(int ite=0; ite<n-1; ite++){
    
      int j=1;
       while(j<=n){
           for(pi i:edge[j]){
               int node=i.first;
               int d=i.second;

               if(dis[j]==inf) continue;
               dis[node]=min(dis[node], d+dis[j]);
           }
           j++;
       }
   }
  // for(int i=1; i<=n; i++) cout<<dis[i]<<" ";
   for(int ite=1; ite<n; ite++){
   int j=1;
   while(j<=n){
       for(pi i:edge[j]){
           int node=i.first;
           int d=i.second;
           
           if(dis[j]==inf) continue;
           if(dis[node]>d+dis[j]){
                dis[node]=ninf;
           }
       }
       j++;
   }
   }
  // for(int i=1; i<=n; i++) cout<<dis[i]<<" ";
   int ans=dis[n];
   if(ans==ninf) ans=1;
   cout<<(-1)*ans<<"\n";
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
