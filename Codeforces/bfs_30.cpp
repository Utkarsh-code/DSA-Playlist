#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> ans;
void dfs(int i, int j, vector<vector<char>> &grid, string ser, int st){
  //  if(st==ser) return true;

    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='#' || grid[i][j]!=ser[st]) return ;
    if(st==9) { ans.push_back(st); return;}
    char ch=grid[i][j];
    grid[i][j]='#';

     dfs(i+1, j, grid, ser, st+1); dfs(i-1, j, grid, ser, st+1); dfs(i, j+1, grid, ser, st+1); dfs(i, j-1, grid, ser, st+1);
           dfs(i+1, j+1, grid, ser, st+1); dfs(i+1,j-1, grid, ser, st+1); dfs(i-1, j+1, grid, ser, st+1);
         dfs(i-1, j-1, grid, ser, st+1) ;

           grid[i][j]=ch;
}
int main(){
    int t;
    cin>>t;

    while (t--)
    {
        ans.clear();
        /* code */
        int n, m;
        cin>>n>>m;

        vector<vector<char>> grid(n, vector<char>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char c;
                cin>>c;

                grid[i][j]=c;
            }
        }
        int cnt=0;
        string ser="ALLIZZWELL";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='A'){
                    int st=0;
                    dfs(i, j, grid, ser, st);
                }
            }
        }
        if(ans.size()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}