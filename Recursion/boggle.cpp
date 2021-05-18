#include<bits/stdc++.h>
using namespace std;
int dx[9]={0, +1,+1,-1,-1,-1,+1, 0, 0};
int dy[9]={0, 0, 1, 1, 0, -1, -1, 1, -1};
int n, row, col;
set<string> arr;
int vis[1000][1000]={0};
vector<vector<char>> grid(1000, vector<char>(1000));
bool issafe(int i, int j){
    if(i<0 || i>=row || j<0 || j>=col || vis[i][j]==1) return false;
    return true;
}
bool fun(string st, int x, int y){
    //vis[x][y]=1;
    //st+=grid[x][y];
   if(arr.find(st)!=arr.end()){
        cout<<st<<"\n";
        return true;
    }
    for(int i=0; i<=8; i++){
        int X=x+dx[i];
        int Y=y+dy[i];

        if(issafe(X, Y)){
            vis[X][Y]=1;
            st+=grid[X][Y];
            if(fun(st, X, Y)) return true;

            st.erase(st.length()-1);
            vis[X][Y]=0;
        }
    }
   // st.erase(st.length()-1);
   // vis[x][y]=0;
    return false;
}
int main(){

    cin>>n;


    for(int i=0; i<n; i++){
        string s;
        cin>>s;
       arr.insert(s);

    }

    cin>>row>>col;

    

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            char ch;
            cin>>ch;

            grid[i][j]=ch;
        }
    }
    string st="";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(!vis[i][j]){
              bool  ans=fun(st, i, j);
            }
        }
    }
    
}