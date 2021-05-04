#include<bits/stdc++.h>
using namespace std;
//#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

int mod=1e9+7;
//int inf=1e18;
//int ninf=-1e18;

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
void dfs(int row, int col, vector<vector<int>> &grid){
        
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0) return;
        grid[row][col]=0;

        dfs(row+1, col, grid);
        dfs(row, col+1, grid);
        dfs(row-1, col, grid);
        dfs(row, col-1, grid);
}
void solve(){
   // int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;

            if(ch=='#') grid[i][j]=0;
            else grid[i][j]=1;
        }
    }
     
     int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                ans++;
                dfs(i, j, grid);
            }
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
