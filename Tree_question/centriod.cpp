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
int n;
unordered_map<int, vector<int>> edge;
int sz[200010];
vector<int> ans;
void dfs(int src, int par){
    
    sz[src]=1;
    int f=1;
    for(int x:edge[src]){
        if(x==par) continue;
        dfs(x, src);
        sz[src]+=sz[x];
        if((sz[x])>n/2) f=0;
    }
    if((n-sz[src])>n/2) f=0;
    if(f) ans.push_back(src);
}
void solve(){
     
     cin>>n;
     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }
    
    dfs(1, 0);
    cout<<ans[0]<<"\n";
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