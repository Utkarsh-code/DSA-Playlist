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

void solve(){
     int n, m, k;
     cin>>n>>m>>k;

     vector<int> a(n+1, 0);

     for(int i=1; i<=n; i++){
         int type;
         cin>>type;

         while(type--){
             int x;
             cin>>x;

             a[i]=a[i]|((1<<(x-1)));
         }
     }
     
     vector<pi> g[n+1];
     for(int i=0; i<m; i++){
         int src, des, w;
         cin>>src>>des>>w;

         g[src].pb({des, w});
         g[des].pb({src, w});
     }

     int dis[n+1][(1<<k)];
     int vis[n+1][(1<<k)];

     for(int i=0; i<=n; i++){
         for(int j=0; j<(1<<k); j++){
             dis[i][j]=inf;
             vis[i][j]=0;
         }
     }

     set<pair<int, pi>> s;
     s.insert({0, {1, a[1]}});
     dis[1][a[1]]=0;


     while(s.size()>0){
         pair<int, pi> p=*(s.begin());
         s.erase(s.begin());

         int node=p.second.first;
         int val=p.second.second;

         if(vis[node][val]) continue;
         vis[node][val]=1;

         for(pi i:g[node]){
             int ch=i.first;
             int w=i.second;

             if(dis[ch][ val|a[ch] ] > dis[node][val]+w){
                // s.erase({dis[ch][ val|a[ch] ],{ch, val|a[ch] }});
                 dis[ch][ val|a[ch] ]=dis[node][val]+w;
                 s.insert({dis[node][val]+w, {ch, val|a[ch] }});
             }
         }
     }
     
     int ans=inf;
     for(int i=0; i<(1<<k); i++){
         for(int j=0; j<(1<<k); j++){

             if((i|j) ==((1<<k)-1)){
                 ans=min(ans, max(dis[n][i], dis[n][j]));
             }
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}