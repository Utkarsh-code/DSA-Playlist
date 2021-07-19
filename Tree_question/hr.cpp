#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pii pair<int, int>
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
map<int, set<pair<int, int>>> g;
int st[100010];
int sum=0;
pair<int, int> bfs(int v, int n){
     
     queue<pair<int, int>> q;
     q.push({v, 0});
     vector<int> vis(n, 0), dis(n, -1);
     
     vis[v]=1;
     dis[v]=0;
     pair<int, int> p;
     while(!q.empty()){
         p=q.front();
         q.pop();
         
         int node=p.first;
         int d=p.second;
         
         for(auto i:g[node]){
             int x=i.first;
             int w=i.second;
           //  if(st.find({node, x})!=st.end() || st.find({x, node})!=st.end()) continue;

             if(!vis[x] && st[x]==0){
                 vis[x]=1;
                 dis[x]=w+dis[node];
                 sum+=w;
                 q.push({x, w+d});
             }
         }
     }
     int inf=1e9+7;
     int node=-1, d=-inf;

    for(int i=1; i<=n; i++){
        if(dis[i]>d){
            d=dis[i];
            node=i;
        }
    }
     return {node, d};
 }

void solve(){
    //cout<<"utk ";
     int n, k;
     cin>>n>>k;
    //   cout<<"utk ";
     set<int> s;
     for(int i=0; i<k; i++){
         int a;
         cin>>a;
        // a--;
         s.insert(a);
     }

     g.clear();
    // cout<<"utk ";
     vector<int> degree(n+1, 0);
    // int sum=0;
    // memset(degree, 0, sizeof(degree));
    for(int i=1; i<=n; i++) st[i]=0;

     for(int i=0; i<n-1; i++){
         int src, des, w;
         cin>>src>>des>>w;
        //src--;
       // des--;

         
         g[src].insert({des, w});
         g[des].insert({src, w});
         degree[src]++;
         degree[des]++;
       //  sum+=w;
     }
    // cout<<sum<<" ";
     queue<int> q;
    // cout<<degree[4]<<" ";
     for(int i=1; i<=n; i++){
       //  cout<<degree[i]<<" ";
         if(degree[i]==1 && s.find(i)==s.end()) q.push(i);
     }
    // cout<<q.size()<<" ";
   // st.clear();
     while(!q.empty()){
         int p=q.front();
         q.pop();
         
         st[p]=1;
         for(auto i:g[p]){
             int w=i.second;
             int node=i.first;
             
             degree[node]--;
            // g[p].erase({node, w});
            // g[node].erase({p, w});
           // g[p].erase(make_pair(node, w));
           // g[node].erase(make_pair(p, w));
            //st.insert({p, node});
            //st.insert({node, p});

             //sum-=w;
             if(degree[node]==1 && s.find(node)==s.end() && st[node]==0){
                 q.push(node);
             }
         }
     }
     
    // sum=2*sum;
    // cout<<sum<<" ";
    sum=0;
     pair<int, int> x=bfs(1, n+1);
    /* for(int i=0; i<n; i++){
         if(g[i].size()!=0) {
            x=bfs(i, n+1);
             break;
         }
     }*/
     sum=0;
     x=bfs(x.first, n+1);
     int res=2*sum-(x.second);
     cout<<res<<"\n";
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