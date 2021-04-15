#include<bits/stdc++.h>
using namespace std;
//int n, m;
vector<vector<char>> grid(1009, vector<char>(1009));
bool valid(int x, int y, int n, int m){
    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]=='X') return false;
    return true;
}
int main(){

    while(1){
    int n, m;
    cin>>m>>n;

    if(m==0 && n==0) break;
    //char grid[n][m];
    int a=0, b=0, src=0, des;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;
            grid[i][j]=ch;
            if(ch=='S'){a=i; b=j;}
            if(ch=='D'){src=i; des=j;}
        }
    }
    grid[src][des]='0';
    vector<vector<int>> dis(n, vector<int>(m, 100009));
    vector<vector<int>> vis(n , vector<int>(m, 0));
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;
    pq.push(make_pair(0, make_pair(a, b)));
    dis[a][b]=0;
    int dx[4]={0,0, 1, -1};
    int dy[4]={1, -1, 0, 0};
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        
        int wt=p.first;
        int x=p.second.first;
        int y=p.second.second;

        if(vis[x][y]) continue;
        vis[x][y]=1;

        for(int i=0; i<4; i++){
            int X=x+dx[i];
            int Y=y+dy[i];

            if(valid(X, Y, n, m)){
                int ndis=wt+(grid[X][Y]-'0');
                if(dis[X][Y]>ndis){
                    dis[X][Y]=ndis;
                    pq.push(make_pair(dis[X][Y], make_pair(X, Y)));
                }
            }
        } 
    }
    int ans=dis[src][des];
    cout<<ans<<"\n";}
}