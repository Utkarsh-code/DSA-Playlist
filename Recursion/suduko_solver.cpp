#include<bits/stdc++.h>
using namespace std;
bool isvalid(int row, int col, int grid[9][9], int n, int num){
    if(grid[row][col]!=0) return false;

    for(int i=0; i<n; i++){
        if(grid[i][col]==num) return false;
        if(grid[row][i]==num) return false;
    }
    int k=sqrt(n);
    int strow=row-row%(k);
    int stcol=col-col%(k);

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(grid[i+strow][j+stcol]==num) return false;
        }
    }
   return true;
}
bool sudo_solver(int currow, int curcol, int grid[9][9], int n){
        
        if(currow==n) return true;
        else if(curcol==n){
            return sudo_solver(currow+1, 0, grid, n);
        }

        if(grid[currow][curcol]>0){
           return sudo_solver(currow, curcol+1, grid,n);
        }
        for(int i=1; i<=n; i++){
           if(isvalid(currow, curcol, grid, n, i)){
            grid[currow][curcol]=i;

            bool ans=sudo_solver(currow, curcol+1, grid, n);
            if(ans) return true;
            grid[currow][curcol]=0;
            }
        }
    return false;
}
void print(int n, int grid[9][9]){
         
         for(int i=0; i<n; i++){
             for(int j=0; j<n; j++){
                 cout<<grid[i][j]<<" ";
             }
             cout<<"\n";
         }
}
int main(){
         int n;
         cin>>n;

        int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
         bool ans=sudo_solver(0, 0, grid, n);
         if(ans){
             cout<<"sudoko is solvable\n";
             print(n, grid);
         }
         else {
             cout<<"Do it urself I am unable to solve the problem\n";
         }
}