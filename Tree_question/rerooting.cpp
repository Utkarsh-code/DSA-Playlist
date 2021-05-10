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
int answer[200010]={0};
int vis[200010]={0};
int subtree[200010]={0};
int subtree_sum[200010]={0};
int n;
void dfs(int src, int par){
    vis[src]=1;

    subtree[src]=1;
    subtree_sum[src]=0;

    for(int i:edge[src]){
        if(par!=i) {dfs(i, src);

        subtree[src]+=subtree[i];
        subtree_sum[src]+=(subtree[i]+subtree_sum[i]);}
    }
}

void dfs2(int src, int par){
     if(par==-1) answer[src]=subtree_sum[src];
     else{
         int x=answer[par]-(subtree[src]+subtree_sum[src]);
         int y=n-subtree[src];
         answer[src]=x+y+subtree_sum[src];
     }

     for(int i:edge[src]){
         if(par!=i) dfs2(i, src);
     }
}
void solve(){
    
     cin>>n;

     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }

     dfs(1, -1);
     dfs2(1, -1);

     for(int i=1; i<=n; i++){
         cout<<answer[i]<<" ";
     }
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