#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
int mod=1e9+7;
int inf=1e18;
int ninf=-1e18;
 
int pown(int x, int y){
    int res=1;
 
    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}
void solve(){
     int n, m;
     cin>>n>>m;

     string st;
     cin>>st;

     unordered_map<int, vector<int>> edge;
     int indegree[n+1]={0};
     for(int i=0; i<m; i++){
         int src, des;
         cin>>src>>des;

         edge[src].push_back(des);
         indegree[des]++;
     }
     queue<int> q;
     int dp[n+1][26];
     memset(dp, 0, sizeof(dp));
     for(int i=1; i<=n; i++){
         if(indegree[i]==0){ dp[i][st[i-1]-'a']=1;  q.push(i);}
     }
     
     int cnt=0;
     while(!q.empty()){
         int x=q.front();
         q.pop();
         
         cnt++;
         for(int i:edge[x]){
             for(int j=0; j<26; j++){
                 if((st[i-1]-'a')==j){
                     dp[i][j]=max(dp[x][j]+1,dp[i][j]);
                 }
                 else dp[i][j]=max(dp[i][j], dp[x][j]);
             }
             indegree[i]--;
             if(indegree[i]==0) q.push(i);
         }
     }

     if(cnt!=n){
         cout<<"-1\n";
         return;
     }

     int ans=ninf;

     for(int i=1; i<=n; i++){
         ans=max(ans, *max_element(dp[i], dp[i]+26));
     }
     cout<<ans<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}