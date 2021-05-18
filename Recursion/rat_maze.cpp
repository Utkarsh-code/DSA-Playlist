#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> grid(1000, vector<int>(1000));
vector<vector<int>> ans(1000, vector<int>(1000, 0));
bool valid(int row, int col){
    if(row<0 || row>=n || col<0 || col>=n || grid[row][col]==0) return false;
    return true;
}
bool solve_ratmaze(int row, int col){
    
     if(row==n-1 && col==n-1) return true;

     int dx[4]={0, 1, -1, 0};
     int dy[4]={1, 0, 0, -1};

     for(int i=0; i<4; i++){
         int nrow=dx[i]+row;
         int ncol=dy[i]+col;

         if(valid(nrow, ncol)){
             ans[nrow][ncol]=1;

             if(solve_ratmaze(nrow, ncol)) return true;
             ans[nrow][ncol]=0;
         }
     }
    return false;
}
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
 //   int n;
    cin>>n;

  //  vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num;
            cin>>num;
            grid[i][j]=num;
        }
    }
    
    ans[0][0]=1;
    if(solve_ratmaze(0, 0) && grid[0][0]!=0){
        cout<<"Rat can reach to his destination\n";
        print();
    }
    else{
        cout<<"Rat can't reach to his destination\n";
    }
}