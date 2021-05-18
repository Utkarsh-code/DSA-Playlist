
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> grid(1000, vector<int>(1000, 0));
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j])
            cout<<"Q ";
            else cout<<"_ ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
bool valid(int row, int col){
    for(int i=0; i<=row; i++){
        if(grid[i][col]) return false;
    }
    int y=col;
    for(int i=row; i>=0 && y<n; i--){
          if(grid[i][y]) return false;
          y++;
    }
    y=col;
    for(int i=row; i>=0 && y>=0; i--){
        if(grid[i][y]) return false;
        y--;
    }
    return true;
}
bool solve_nqueen(int row){
    if(row==n) {print(); return false;}
    
    for(int col=0; col<n; col++){
            if(valid(row,col)){
             grid[row][col]=1;

             if(solve_nqueen(row+1)) return true;
             grid[row][col]=0;
            }
    }
    return false;
}

int main(){
    cin>>n;

    if(solve_nqueen(0)){
       // cout<<"Queen can be placed at safe position\n";
      //  print();
    }
    else{
       // cout<<"Queen can't be placed at safe position\n";
    }
}