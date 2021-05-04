#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, string>>
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
int ans=inf;
string ans_st;
int n, m;
bool isvalid(int x, int y, vector<vector<char>> &grid){
       if(x<0 || y<0 || x>=n || y>=m ||  vis[x][y]==1) return false;
       return true;
}
/*void dfs(int x, int y, vector<vector<char>>& grid, string st){
    vis[x][y]=1;
    if(grid[x][y]=='B'){
        int len=st.length();

        if(ans>len){
            ans=len;
            ans_st=st;
        }
        return;
    }

    for(int i=0; i<4; i++){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(isvalid(X, Y, grid)){
             dfs(X, Y, grid, st+str[i]);
        }
    }
    vis[x][y]=0;
}*/
void solve(){
  //  int n, m;
    cin>>n>>m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;

            grid[i][j]=ch;
           if(ch=='#') vis[i][j]=1;
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
    string st="";
    //dfs(st_r, st_c, grid, st);
    queue<pii> q;
    q.push({st_r, {st_c, st}});
    int fl=0;
    vis[st_r][st_c]=1;
    while(!q.empty()){
        pii p=q.front();
        q.pop();

        int x=p.ff;
        int y=p.ss.ff;
        string s=p.ss.ss;
       // vis[x][y]=1;
    
        if(grid[x][y]=='B'){
            cout<<"YES\n";
            cout<<s.length()<<"\n";
            cout<<s<<"\n";
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
             q.push({X, {Y, {s+str[i]}}});
            }
        }
    }
    if(fl==0){
        cout<<"NO\n";
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
        solve();
    }
    return 0;
}
