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
unordered_map<int, vector<int>> edge;
unordered_map<int, set<int>> s;
int color[200010];
int ans[200010];
void dfs(int src, int par){
    
    s[src].insert(color[src]);
    for(int x:edge[src]){
        if(par==x) continue;
        dfs(x, src);
        
        if(s[x].size()>s.[src].size()) swap(s[x], s[src]);
        for(int i:s[x]){
            s[src].insert(i);
        }
    }
    ans[src]=s[src].size();
}
void solve(){
     int n;
     cin>>n;

     color[0]=-1;
     for(int i=1; i<=n; i++) cin>>color[i];

     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }
     dfs(1,-1);
     for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
     cout<<"\n";
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