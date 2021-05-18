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
int n, m;
int ans=0;
char grid[1010][1010];
int comp[1010][1010];
int vis[1010][1010];
int answer[1000010];
int cnt=0;
void dfs(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y]) return;
    if(grid[x][y]=='*'){
        ans++;
        return;
    }

    vis[x][y]=cnt;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

void dfs2(int x, int y, int val){
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y] || grid[x][y]=='*') return;

    vis[x][y]=1;
    comp[x][y]=val;

    dfs2(x+1, y, val);
    dfs2(x-1, y, val);
    dfs2(x, y+1, val);
    dfs2(x, y-1, val);
}
void solve(){
     
     int q;
     cin>>n>>m>>q;
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             cin>>grid[i][j];
         }
     }
     
     memset(comp, -1, sizeof(comp));
     memset(vis, 0, sizeof(vis));
     cnt=0;
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(grid[i][j]=='.' && !vis[i][j]){
                 cnt++;
                 ans=0;
                 dfs(i, j);
                 answer[cnt]=ans;
                 //cout<<cnt<<" ";
             }
         }
     }
     
    // memset(vis, 0, sizeof(vis));
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
        //     if(comp[i][j]==-1) continue;
        //     if(!vis[i][j])
         //    dfs2(i, j, comp[i][j]);
         }
     }

    

     while ((q--))
     {
         int a, b;
         cin>>a>>b;
         a--;
         b--;
         cout<<answer[vis[a][b]]<<"\n";
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