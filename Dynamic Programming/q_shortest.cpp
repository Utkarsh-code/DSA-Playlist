#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  pi pair<int,int>

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
unordered_map<int, vector<pi>> adj;
void solve(){
   int n, m;
   cin>>n>>m;

   for(int i=0; i<m; i++){
             int src, des, wt;
             cin>>src>>des>>wt;

             adj[src].push_back(make_pair(des, wt));
             adj[des].push_back(make_pair(src, wt));
   }
       int q;
       cin>>q;

       while(q--){
           int src, des;
           cin>>src>>des;

           int vis[n+1];
           int dis[n+1];

           for(int i=0; i<=n; i++){
               vis[i]=0;
               dis[i]=inf;
           }
         //  priority_queue<pi, vector<pi>, greater<pi>> pq;
          //queue<pi> pq;
          set<pi> pq;
           pq.insert(make_pair(0, src));
           dis[src]=0;

           while(!pq.empty()){
               auto p=*(pq.begin());
               pq.erase(pq.begin());

               int node=p.second;
               if(vis[node]) continue;
               vis[node]=1;

               for(auto i:adj[node]){
                   int ndis=i.second+dis[node];
                   if(dis[i.first]>ndis){
                      // dis[i.first]=ndis;
                       pq.erase(make_pair(dis[i.first], i.first));
                       dis[i.first]=ndis;
                       pq.insert(make_pair(ndis, i.first));
                   }
               }
           }
           cout<<dis[des]<<"\n";
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
