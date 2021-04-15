#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m;
bool isvalid(ll x, ll y){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}
int main(){
    //ll n, m;
    ll t;
    cin>>t;
    ll cnt=0;
    while(t--){
    cin>>n>>m;
    
    ll mat[n][m];
    for(ll i=0; i<n; i++){
        string s;
        cin>>s;
        for(ll j=0; j<m; j++){
            mat[i][j]=s[j]-'0';
        }
    }
    //ll dp[n][m];
    ll INF=1e18;
    vector<vector<ll>> dp(n, vector<ll>(m, INF));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    dp[0][0]=0;
    ll dx[4]={1, -1, 0, 0};
    ll dy[4]={0, 0,1, -1};
    vis[0][0]=true;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        ll x=p.first;
        ll y=p.second;

        for(ll i=0; i<4; i++){
            ll X=x+dx[i];
            ll Y=y+dy[i];

            if(isvalid(X, Y)==true && vis[X][Y]==false){
                vis[X][Y]=true;
               // dp[X][Y]=((mat[x][y]!=mat[X][Y]) ? 1+dp[x][y] : dp[x][y]);
                q.push({X, Y});
                if(mat[x][y]!=mat[X][Y]){
                    dp[X][Y]=min(dp[X][Y], 1+dp[x][y]);
                }
                else dp[X][Y]=min(dp[X][Y], dp[x][y]);
            }
        }
    }
    cnt++;
    cout<<"Case "<<cnt<<": "<<dp[n-1][m-1]<<"\n";}
}