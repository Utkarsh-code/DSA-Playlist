#include<bits/stdc++.h>
using namespace std;
int dp[55][55];
void dfs(int i, int j, vector<vector<int>>& mat, int num){
    if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]!=num || dp[i][j]!=-1) return;
   // mat[i][j]=-1;
   dp[i][j]=1+num;
   //if(dp[i][j]!=-1) return dp[i][j];
    int arr[8], x=0;
    dfs(i+1, j, mat, num+1);
    dfs(i, j+1, mat, num+1);
    dfs(i+1, j+1, mat, num+1);
    dfs(i, j-1, mat, num+1);
    dfs(i-1, j, mat, num+1);
    dfs(i-1, j-1, mat, num+1);
    dfs(i+1, j-1, mat, num+1);
    dfs(i-1, j+1, mat, num+1);

    //return *max_element(arr, arr+x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //int t;
    //cin>>t;
    int cnt=1;
    while(1){
    int n, m;
    cin>>n>>m;
     if(n==0 && m==0) break;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;
            int x=ch-'A';
           // cout<<x<<" ";
            mat[i][j]=x;
        }
       // cout<<"\n";
    }
    
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0 && dp[i][j]==-1){
                //int num=0;
                dfs(i, j, mat, 0);

            }
       }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //cout<<dp[i][j]<<" ";
            ans=max(ans, dp[i][j]);
        }
        //cout<<"\n";
    }
    cout<<"Case "<<cnt++<<": "<<ans<<"\n";
   // cnt++;
   //cout<<ans<<"\n";
}
}