#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define piis pair<int, pair<int, pair<int, string>>> 
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

int vis[1010][1010];
int mon[1010][1010];
char grid[1010][1010];
int n, m;
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
string str="DURL";
char dir[1010][1010];
pi from[1010][1010];
pi to={-1, -1};

bool isvalid(int x, int y){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]=='#' || vis[x][y]==1) return false;
        return true;
}
bool isvalid2(int x, int y, int dis){

    if(x<0 || x>=n || y<0 || y>=m || grid[x][y]=='#' || vis[x][y]==1 || (dis>=mon[x][y] && mon[x][y]!=-1) ) return false;
    return true;
}
bool bfs(int i, int j){
    queue<pii> q;
    q.push({0, {i, j}});

    while (!q.empty())
    {
       pii p=q.front();
       q.pop();
       
       pi node=p.ss;
       int x=p.ss.ff;
       int y=p.ss.ss;
       int d=p.ff;

       
       if(x==0 || y==0 || y==m-1 || x==n-1) {
           to=make_pair(x, y);
          return true;}

       for(int i=0; i<4; i++){
           int X=x+dx[i];
           int Y=y+dy[i];

           if(isvalid2(X, Y, d+1)){
               vis[X][Y]=1;
               dir[X][Y]=str[i];
               from[X][Y]=node;
               q.push({d+1, {X, Y}});
           }
       }
    }
    return false;
}
void solve(){
    //int n, m;
    cin>>n>>m;
    
    //char grid[n][m];
    memset(mon, -1, sizeof(mon));
    queue<pii> q;
    int sx, ex;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='M'){
                q.push({i, {j, 0}});
                vis[i][j]=1;
                mon[i][j]=0;
            }

            if(grid[i][j]=='A'){
                sx=i;
                ex=j;
            }
        }
    }

    while(!q.empty()){
        pii p=q.front();
        q.pop();

        int x=p.ff;
        int y=p.ss.ff;
        int d=p.ss.ss;

        for(int i=0; i<4; i++){
            int X=dx[i]+x;
            int Y=dy[i]+y;

            if(isvalid(X, Y)){
                vis[X][Y]=1;
                mon[X][Y]=1+d;
                q.push({X, {Y, d+1}});
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    bool ans=bfs(sx, ex);
   // if(!ans) cout<<"NO\n";
    if(ans) {cout<<"YES\n"; 
       string st="";
       while(to.ff!=sx || to.ss!=ex){
            st+=dir[to.ff][to.ss];
            to=from[to.ff][to.ss];
       }
       reverse(st.begin(), st.end());
       cout<<st.length()<<"\n";
       cout<<st<<"\n"; 
       }
    else cout<<"NO\n";
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
