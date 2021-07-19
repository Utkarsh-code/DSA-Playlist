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
int color[200010];
unordered_map<int, vector<int>> edge;
int dp[200010];
int answer[200010];
int zero=0;
void dfs(int v, const int par=-1){

    dp[v]=color[v];
    if(color[v]==0) dp[v]=-1;
    
    for(int i:edge[v]){
        if(i!=par) {
            dfs(i, v);
            dp[v]=dp[v]+ max(zero, dp[i]);
        }
        
    }
}

void dfs2(int v, const int par=-1){
    if(par!=-1){
        int x=answer[par]-max(dp[v], zero);
        answer[v]=max(zero, x)+dp[v];
    }

    for(int i:edge[v]){
        if(i==par) continue;
        dfs2(i, v);
    }
}
void solve(){
     int n;
     cin>>n;

    
     for(int i=1; i<=n; i++) cin>>color[i];

     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
     }
     dfs(1);
     answer[1]=dp[1];

     dfs2(1);

     for(int i=1; i<=n; i++) cout<<answer[i]<<" ";
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