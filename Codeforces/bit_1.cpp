#include<bits/stdc++.h>
using namespace std;
int n;
int dis[11][11];
int tsp(int mask, int curr_city, int tar){
    if(mask==tar) return dis[0][curr_city];

    int ans=INT_MAX;
    for(int city=0; city<n; city++){
        
        if((mask&(1<<city))==0){
            int newans=dis[city][curr_city]+tsp(mask|(1<<city), city, tar);
           // cout<<newans<<" ";
            ans=min(ans, newans);
        }
       // ans=min(ans, newans);
    }
    return ans;
}
int main(){
    int  m;
    cin>>n>>m;
    memset(dis, -1, sizeof(dis));
   // int dis[n][n];
    for(int i=0; i<m; i++){
        int src, des, wt;
        cin>>src>>des>>wt;

        src--; des--;
        dis[src][des]=wt;
        dis[des][src]=wt;
    }
    for(int i=0; i<n; i++){
        dis[i][i]=0;
        for(int j=0; j<n; j++){
            if(dis[i][j]==-1) dis[i][j]=100000007;
        }
    }
    int tar=(1<<n) -1;
    cout<<tsp(1, 0, tar)<<"\n";
}