#include<bits/stdc++.h>
using namespace std;
int a=0, b=0;
void dfs(int i, int j, vector<vector<char>>&mat){
    if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]=='#') return;
    if(mat[i][j]=='k') a++;
    if(mat[i][j]=='v') b++;
    mat[i][j]='#';

    dfs(i, j+1, mat);
    dfs(i+1, j, mat);
    dfs(i-1, j, mat);
    dfs(i, j-1, mat);
}
int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> mat(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;

            mat[i][j]=ch;
        }
    }
    int s=0, v=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]=='.' || mat[i][j]=='k' || mat[i][j]=='v') {dfs(i, j, mat);
             if(a>b) s+=a;
             else v+=b;}
             a=0;
             b=0;
        }
    }
    cout<<s<<" "<<v;
}