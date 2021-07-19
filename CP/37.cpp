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
unordered_map<int , vector<int>> edge;
int dis[200010]={0};
int p[200010]={0};
int tin[200010]={0}, tout[200010]={0};
int cnt=0;

void dfs(int v, const int par=-1, const int d=0){
    p[v]=par;
    dis[v]=d;
    tin[v]=++cnt;

    for(int i:edge[v]){
        if(i==par) continue;
        dfs(i,v, d+1);
    }
    tout[v]=++cnt;
}
void solve(){
     int n, q;
     cin>>n>>q;

     for(int i=0; i<n-1;i++){
         int a, b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
     }
     cnt=0;
     dfs(1);

     while(q--){
         int k;
         cin>>k;

         int arr[k];
         for(int i=0; i<k; i++){
             cin>>arr[i];
         }
         
        // cout<<dis[10]<<" ";
         int u=arr[0];
         for(auto i:arr){
             if(dis[i]>dis[u]) u=i;
         }
         //   cout<<u<<"\n";
         for(int i=0; i<k; i++){
             int  node=arr[i];
             if(node==u) continue;
             if(p[node]!=-1) arr[i]=p[node];
         }
//cout<<u<<"\n";
         int fl=0;
         for(int i=0; i<k; i++){
             int node=arr[i];
            //  cout<<node<<" ";
             if(tin[node]<=tin[u] && tout[u]<=tout[node]) continue;
             else {
                  fl=1;
                  break;

             }
         }
         if(fl) cout<<"NO\n";
         else cout<<"YES\n";
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}