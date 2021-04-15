#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, nax;
queue<pair<ll, ll>> q;
bool valid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}
void bfs(vector<vector<ll>>& dp, vector<vector<ll>>& grid){
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    ll dx[8]={1, -1, 0, 0, -1, 1, 1, -1};
    ll dy[8]={1, -1, 1, -1, 1, -1, 0, 0};
    while(!q.empty()){
        auto p=q.front();
        q.pop();

        ll x=p.first;
        ll y=p.second;

        if(vis[x][y]) continue;
        vis[x][y]=1;

        for(ll i=0; i<8; i++){
            ll X=x+dx[i];
            ll Y=y+dy[i];

            if(valid(X, Y)){
                q.push(make_pair(X,Y));
                dp[X][Y]=min(dp[X][Y], dp[x][y]+1);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
       // ll n, m;
        cin>>n>>m;

        //ll nax=INT_MIN;
        vector<vector<ll>> grid(n, vector<ll>(m,0));
         nax=0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                ll num;
                cin>>num;
                nax=max(nax,num);
                grid[i][j]=num;
            }
        }
        ll INF=(1e8+7);
        vector<vector<ll>> dp(n, vector<ll>(m , 1000000009));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(grid[i][j]==nax){
                    q.push(make_pair(i, j));
                    dp[i][j]=0;
                }
            }
        }
        bfs(dp, grid);
        ll ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans=max(ans, dp[i][j]);
            }
        }
        cout<<ans<<"\n";
    }
}