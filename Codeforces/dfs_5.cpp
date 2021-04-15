#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &mat, int x, int y){
    if(x<0  || x>=mat.size() || y<0 || y>=mat[0].size() || mat[x][y]=='#') return;
    mat[x][y]='#';
    dfs(mat, x+1, y);
    dfs(mat, x, y-1);
    dfs(mat, x, y+1);
    dfs(mat, x-1, y);
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> mat(n, vector<char>(m));
    vector<int> idx;
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;
            mat[i][j]=ch;
            if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]=='.'){
                cnt++;
                idx.push_back(i);
                idx.push_back(j);
            }
        }
    }
    if(cnt==2){
        dfs(mat, idx[0], idx[1]);
        if(mat[idx[2]][idx[3]]=='#') cout<<"valid\n";
        else cout<<"invalid\n";
    }
    else cout<<"invalid\n";
    }
}