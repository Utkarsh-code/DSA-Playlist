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
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
vector<vector<char>> grid(55, vector<char>(55));
int vis[55][55];
set<pi> s;
bool isvalid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}
void bfs(int i, int j){
    memset(vis, 0, sizeof(vis));
    queue<pi> q;
    q.push({i, j});
    vis[i][j]=1;
    s.insert({i, j});
    while(!q.empty()){
        pi p=q.front();
        q.pop();

        int x=p.ff;
        int y=p.ss;

        //if(x==n-1 && y==m-1) return true;

        for(int i=0; i<4; i++){
            int X=x+dx[i];
            int Y=y+dy[i];

            if(isvalid(X, Y)){
                if(!vis[X][Y] && (grid[X][Y]=='.' || grid[X][Y]=='G')){
                   // s.insert({X, Y});
                    vis[X][Y]=1;
                    q.push({X, Y});
                }
            }
        }
    }
   // return false;
}
bool dfs(int x, int y){

     if(x<0 || y<0 || x>=n || y>=m || grid[x][y]=='#' || vis[x][y]==1) return false;
     if(x==n-1 && y==m-1) return true;
     vis[x][y]=1;
     s.insert({x, y});
    bool ans=false;
     ans|=dfs(x, y-1);
     ans|=dfs(x, y+1);
     ans|=dfs(x-1, y);
     ans|=dfs(x+1, y);

     return ans;
}
void solve(){
     cin>>n>>m;
     s.clear();
     memset(vis, 0, sizeof(vis));

     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            char ch;
            cin>>ch;

            grid[i][j]=ch;
         }
     }

    

     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(grid[i][j]=='B'){
                 for(int d=0; d<4; d++){
                     int x=i+dx[d];
                     int y=j+dy[d];

                     if(isvalid(x, y)){
                         if(grid[x][y]=='#' || grid[x][y]=='B') continue;
                         if(grid[x][y]=='G'){
                             cout<<"No\n";
                             return;
                         }
                         grid[x][y]='#';
                     }
                 }
             }
         }
     }
     if(grid[n-1][m-1]=='.'){
         bfs(n-1, m-1);
     }
     bool ans=true;
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            // memset(vis, 0, sizeof(vis));
             if(grid[i][j]=='G' && vis[i][j]==0){
                 cout<<"No\n";
                 return;
                 //ans=(ans)&(dfs(i, j));
             }
         }
     }

      cout<<"Yes\n";
     //else cout<<"No\n";
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