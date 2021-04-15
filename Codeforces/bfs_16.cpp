#include<bits/stdc++.h>
using namespace std;
int n, m;
bool valid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}
int main(){
    int t;
    cin>>t;

    while(t--){
       // int n, m;
        cin>>n>>m;

        int grid[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        int hx, hy, t;
        cin>>hx>>hy>>t;
        hx--;
        hy--;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dis(n , vector<int>(m, 10000009));
        dis[0][0]=grid[0][0];
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push(make_pair(grid[0][0],make_pair(0, 0)));
        int dx[4]={0, 0, -1, 1};
        int dy[4]={1, -1, 0,0};

        while(!q.empty()){
            auto p=q.top();
            q.pop();

            int wt=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(vis[x][y]) continue;
            vis[x][y]=true;
            for(int i=0; i<4; i++){
                int X=x+dx[i];
                int Y=y+dy[i];

                if(valid(X, Y)){
                    int ndis=wt+grid[X][Y];

                    if(dis[X][Y]>ndis){
                        dis[X][Y]=ndis;
                        q.push(make_pair(dis[X][Y],make_pair(X, Y)));
                    }
                }
            }
        }
        if(dis[hx][hy]<=t) {
            cout<<"YES\n";
            cout<<t-dis[hx][hy]<<"\n";
        }
        else cout<<"NO\n";
    }
}