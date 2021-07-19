#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pi pair<int, int>
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
     int n;
     cin>>n;
     
     int dp[n+1];
     int indegree[n+1]={0};
     unordered_map<int, vector<int>> edge;
     for(int i=1; i<=n; i++){
         int a;
         cin>>a;

         dp[i]=a;
     }

     for(int i=1; i<=n; i++){
         int a;
         cin>>a;
         
         if(a!=-1){
         edge[i].pb(a);
         indegree[a]++;}
     }
     
     queue<int> q;
     for(int i=1; i<=n; i++){
         if(indegree[i]==0) q.push(i);
     }

     vector<int> ans[2];

     while (!q.empty())
     {
         /* code */
         int x=q.front();
         q.pop();

         if(dp[x]<0) ans[1].pb(x);
         else ans[0].pb(x);

         for(int i:edge[x]){
             indegree[i]--;

            dp[i]=max(dp[i], dp[i]+dp[x]);
            if(indegree[i]==0) q.push(i);

         }
     }
     int sum=0;
     for(int i=1; i<=n; i++){
         sum+=dp[i];
     }
     cout<<sum<<"\n";

     reverse(ans[1].begin(), ans[1].end());
     for(int i=0; i<ans[0].size(); i++) cout<<ans[0][i]<<" ";
     for(int i=0; i<ans[1].size(); i++) cout<<ans[1][i]<<" ";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}