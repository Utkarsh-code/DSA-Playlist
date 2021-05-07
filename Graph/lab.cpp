#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define  ff first
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

int st_r=-1, st_c=-1;
int end_r=-1, end_c=-1;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int vis[1010][1010];
string str="UDLR";
int n, m;
pi to;
pi from[1010][1010];
char dir[1010][1010];

bool isvalid(int x, int y, vector<vector<char>> &grid){
       if(x<0 || y<0 || x>=n || y>=m ||  grid[x][y]=='#' || vis[x][y]==1) return false;
       return true;
}

void solve(){
  //  int n, m;
    cin>>n>>m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;

            grid[i][j]=ch;
            if(ch=='A'){
                st_r=i;
                st_c=j;
            }
            if(ch=='B'){
                end_r=i;
                end_c=j;
            }
        }
    }
    //dfs(st_r, st_c, grid, st);
    queue<pii> q;
    q.push({0, {st_r, st_c}});
    int fl=0;
    vis[st_r][st_c]=1;
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        
        pi node=p.ss;
        int x=p.ss.ff;
        int y=p.ss.ss;
        int d=p.ff;
       // vis[x][y]=1;
    
        if(grid[x][y]=='B'){
           to={x, y};
            fl=1;
            break;
        }
      //  if(vis[x][y]) continue;
      //  vis[x][y]=1;

        for(int i=0; i<4; i++){
            int X=dx[i]+x;
            int Y=dy[i]+y;

            if(isvalid(X,Y, grid)){
                vis[X][Y]=1;
                dir[X][Y]=str[i];
                from[X][Y]=node;
                q.push({d+1, {X, Y}});
            }
        }
    }
    if(fl==0){
        cout<<"NO\n"; return;
    }
    cout<<"YES\n";
    string st="";
    while(to.ff!=st_r || to.ss!=st_c){
         st.push_back(dir[to.ff][to.ss]);
         to=from[to.ff][to.ss];
    }
    reverse(st.begin(), st.end());
    cout<<st.length()<<"\n";
    cout<<st<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
