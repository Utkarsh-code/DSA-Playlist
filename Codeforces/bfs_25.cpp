#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m;
bool valid(ll x, ll y){
    if(x<0 || y<0 || x>=n || y>=m)  return false;
    return true;
}
ll bfs(ll i, ll j, vector<vector<ll>>& vis, vector<vector<ll>>& grid){
    vis[i][j]=1;
    ll cnt=0;
    ll dx[8]={1, 1, 0, 0, -1, -1,1,-1};
    ll dy[8]={1, -1, 1, -1, -1,1, 0, 0};
    queue<pair<ll, ll>> q;
    q.push(make_pair(i, j));

    while(!q.empty()){
        ll sz=q.size();

        for(ll i=0; i<sz; i++){
            auto p=q.front();
            q.pop();

            ll x=p.first;
            ll y=p.second;

            for(ll i=0; i<8; i++){
                ll X=x+dx[i];
                ll Y=y+dy[i];

                if(valid(X, Y)){
                    if(grid[x][y]+1==grid[X][Y] && vis[X][Y]==0){
                        vis[X][Y]=1;
                        q.push(make_pair(X, Y));
                    }
                }
            }
        }
        cnt++;
    }
    return cnt;
}
int main(){
     ll t=0;
    while(1){
       // ll n, m;
        cin>>n>>m;

        if(n==0 && m==0) break;

        vector<vector<ll>> grid(n, vector<ll>(m));

        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                char ch;
                cin>>ch;

                grid[i][j]=ch-'A';
            }
        }
        ll ans=0;
        vector<vector<ll>> vis(n, vector<ll>(m, 0));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                   ans=max(ans, bfs(i, j, vis, grid));
                }
            }
        }
        cout<<"Case "<<++t<<": "<<ans<<"\n";
    }
}