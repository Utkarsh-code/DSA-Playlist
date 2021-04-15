#include<bits/stdc++.h>
using namespace std;
bool valid(int x, int y){
    if(x<0 || x>=8 || y<0 || y>=8) return false;
    return true;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        string s, d;
        cin>>s>>d;
         int srcx=s[0]-'a';
         int srcy=s[1]-'0'; srcy--;

         int desx=d[0]-'a';
         int desy=d[1]-'0'; desy--;

         int dx[8]={2,2,-2,-2,1,1,-1,-1};
         int dy[8]={1,-1,1,-1,2,-2,-2,2};
         queue<pair<int, int>> q;
         q.push({srcx,srcy});
         vector<vector<int>> dis(8, vector<int>(8, INT_MAX));
         dis[srcx][srcy]=0;
         vector<vector<bool>> vis(8, vector<bool>(8, false));
         
         
         while(!q.empty()){
             auto p=q.front();
             q.pop();
             int x=p.first;
             int y=p.second;
             
             if(x==desx and y==desy){ cout<<dis[x][y]<<"\n"; break;}
             if(vis[x][y]) continue;
             vis[x][y]=true;
             
             for(int i=0; i<8; i++){
                 int X=x+dx[i];
                 int Y=y+dy[i];

                 if(valid(X,Y)){
                     dis[X][Y]= 1+dis[x][y];
                     q.push({X,Y});
                 }
             }
         }
    }
}