#include<bits/stdc++.h>
using namespace std;
bool isvalid(int row, int col,int n, vector<vector<int>>& grid){
    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==0) return true;
    return false;
}
bool knight_move(vector<vector<int>> &grid, int n, int move_no, int curRow, int curCol){
    if(move_no==n*n) return true;

    int dx[8]={ 2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8]={1, 2, 2, 1, -1, -2, -2, -1};
  // cout<<"ut ";
    for(int curDir=0; curDir<8; curDir++){
        int nextrow=dx[curDir]+curRow;
        int nextcol=dy[curDir]+curCol;

        if(isvalid(nextrow, nextcol, n, grid)==true){
            grid[nextrow][nextcol]=move_no+1;

            bool ans=knight_move(grid, n, move_no+1, nextrow, nextcol);
            if(ans==true) return true;
            grid[nextrow][nextcol]=0;
        }
    }
    return false;
}
void print(vector<vector<int>> &grid, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<grid[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
int main(){
    
    int n;
    cin>>n;
   // cout<<"ut ";
    vector<vector<int>> grid(8, vector<int>(8, 0));
    grid[0][0]=1;
   bool ans=knight_move(grid, n, 1, 0, 0);
   if(ans==true){
       //cout<<"Knight can move to all square\n";
       print(grid, n);
   }
   else{
       cout<<"Knight can't move to all square\n";
   }
}
