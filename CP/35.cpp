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
void dfs(int v, unordered_map<int, vector<int>>& edge, int vis[], int color[]){
    vis[v]=1;

    for(int i:edge[v]){
        if(!vis[i]){
            color[i]=-color[v];
            dfs(i, edge, vis, color);
        }
    }
}
void solve(){
     int n, m;
     cin>>n>>m;

      edge.clear();
     int vis[n+1]={0};
     int color[n+1]={0};
     //unordered_map<int, vector<int>> edge;
     for(int i=0; i<m; i++){
         int a,b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
     }
     color[1]=1;
     dfs(1, edge, vis, color);


     vector<int> one, x;
     for(int i=1; i<=n; i++){
         if(color[i]==1) one.pb(i);
         else x.pb(i);
     }

     int a=x.size(), b=one.size();

     if(a<b){
         cout<<a<<"\n";
         for(int i=0; i<a; i++){
             cout<<x[i]<<" ";
         }
         cout<<"\n";
     }
     else{
         cout<<b<<"\n";
         for(int i=0; i<b; i++) cout<<one[i]<<" ";
         cout<<"\n";
     }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}