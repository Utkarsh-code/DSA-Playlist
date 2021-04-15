#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m;
bool valid(ll x, ll y, vector<vector<char>>&grid){
    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]=='#') return false;
    return true;
}
auto bfs(ll i, ll j, vector<vector<char>>&grid){
        queue<pair<ll,ll>> q;
        q.push(make_pair(i, j));
        ll ans=0;
        ll idx=i, idy=j;
        vector<vector<ll>> dis(n, vector<ll>(m, -1));
        dis[i][j]=0;
        ll dx[4]={1,-1, 0,0};
        ll dy[4]={0, 0, 1, -1};
        while(!q.empty()){
        
        auto p=q.front();
        q.pop();
        ll x=p.first;
        ll y=p.second;

        for(ll i=0; i<4; i++){
            ll X=x+dx[i];
            ll Y=y+dy[i];

            if(valid(X, Y, grid)){
                ll ndis=1+dis[x][y];
                if(dis[X][Y]==-1){
                    dis[X][Y]=ndis;
                    q.push(make_pair(X, Y));
                    if(dis[X][Y]>ans){
                        ans=dis[X][Y];
                        idx=X;
                        idy=Y;
                    }
                }
            }
        }

        }
        auto a=make_pair(make_pair(idx, idy), ans);
        
        return a;
}
int main(){
    ll t;
    cin>>t;

    while(t--){
      //  ll n, m;
        cin>>m>>n;

        vector<vector<char>> grid(n, vector<char>(m));
        ll x, y;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                char ch;
                cin>>ch;
                grid[i][j]=ch;
                if(ch=='.') {x=i; y=j;}
            }
        }
        auto p=bfs(x, y, grid);
        x=p.first.first;
        y=p.first.second;
        p=bfs(x, y, grid);
        ll ans=p.second;

        cout<<"Maximum rope length is "<<ans<<"."<<"\n";
    }
}