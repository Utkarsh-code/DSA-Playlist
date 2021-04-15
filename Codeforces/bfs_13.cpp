#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m;
queue<pair<int, int>> q;
bool valid(ll x, ll y){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}
void bfs(vector<vector<ll>>& dp, vector<vector<ll>>& grid){
    vector<vector<int>> vis(n, vector<int>(m, 0));
   // queue<pair<ll, ll>> q;
    //q.push(make_pair(x, y));
    ll dx[4]={1, -1, 0, 0};
    ll dy[4]={0, 0, 1, -1};

    while(!q.empty()){
        auto p=q.front();
        q.pop();
        ll i=p.first;
        ll j=p.second;
        if(vis[i][j]) continue;
        vis[i][j]=1;
        for(ll k=0; k<4; k++){
         ll X=i+dx[k];
         ll Y=j+dy[k];

         if(valid(X, Y)==true && grid[X][Y]==0){
             //cout<<X<<Y<<" "<<dp[X][Y]<<"\n";
             //if(vis[X][Y]==0){
                // vis[X][Y]=1;
             q.push(make_pair(X, Y));
             dp[X][Y]=min(dp[X][Y], dp[i][j]+1);
         }
        }
    }
}
int main(){
    ll t;
    cin>>t;

    while(t--){
        //ll n, m;
        cin>>n>>m;

        vector<vector<ll>> grid(n , vector<ll>(m, 0));
        for(ll i=0; i<n; i++){
            string st;
            cin>>st;
            for(ll j=0; j<m; j++){
                grid[i][j]=st[j]-'0';
            }
        }
        ll INF=1e18+7;
        vector<vector<ll>> dp(n, vector<ll>(m, INF));
       // memset(dp, 0, sizeof(dp));
       // vector<vector<ll>> vis(n, vector<ll>(m, 0));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i, j));
                    dp[i][j]=0;
                }
            }
        }
        bfs(dp, grid);
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}