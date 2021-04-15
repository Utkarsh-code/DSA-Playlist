#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, m;
int cnt=0;
void dfs(int i, int j,  vector<vector<int>>& grid){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return;
    cnt++;
    grid[i][j]=0;

    dfs(i+1, j,  grid);
    dfs(i-1, j,  grid);
    dfs(i, j+1,  grid);
    dfs(i, j-1,  grid);
}
int main(){
    //int n, m;
    while(1){
    cin>>n>>m;
    if(n==0 && m==0) break;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin>>a;
            grid[i][j]=a;
        }
    }

    map<int, int> mp;
    int sz=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                sz++;
                cnt=0;
                dfs(i, j, grid);
                mp[cnt]++;
            }
        }
    }
    cout<<sz<<"\n";
    for(auto i:mp){
          cout<<i.first<<" "<<i.second<<"\n";
    }
    }
}