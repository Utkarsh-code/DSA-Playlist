#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define ff first
#define ss second
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
int n, m, c;
bool isvalid(int x, int y, vector<vector<int>>& grid, int dis, int i, int j, vector<vector<int>> &vis){
    int prev_dis=grid[i][j]+dis;
    if(prev_dis>c) prev_dis=c;
    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || vis[x][y]==1) return false;
    int nx=grid[x][y]+dis;
    if(nx>c) nx=c;
  //  if(nx!=prev_dis) return false;
    return true;
}
void solve(){
    cin>>n>>m>>c;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int num;
            cin>>num;
            grid[i][j]=num;
        }
    }
    int st=0;
    int end=c;
    int ans=inf;
    while(st<=end){
        int ite=(st+end)/2;
        int fl=0;
    int dx[4]={0, 0, 1, -1};
    int dy[4]={1, -1, 0, 0};
    vector<vector<int>> vis(n, vector<int>(m , 0));
    queue<pi> q;
    q.push({0, 0});
    vis[0][0]=1;
    while(!q.empty()){
        pi p=q.front();
        q.pop();

        int x=p.ff;
        int y=p.ss;
        int nval=ite+grid[x][y];
        if(nval>c) nval=c; 

        if(x==n-1 && y==m-1){
            
            fl=1;
            break;
        }
        for(int i=0; i<4; i++){
            int X=x+dx[i];
            int Y=y+dy[i];

            if(isvalid(X, Y, grid, ite, x, y, vis)){
                vis[X][Y]=1;
                int nxdis=ite+grid[X][Y];
                if(nxdis>c) nxdis=c;
                if(nxdis==nval){
                q.push({X, Y});}
            }
        }
    }
     if(fl){
         ans=min(ans, ite);
         end=ite-1;
     }
     else{
         st=ite+1;
     }
    }
    cout<<ans<<"\n";
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
