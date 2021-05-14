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
     
     unordered_map<int, vector<int>> edge;
     for(int i=0; i<m;i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }

     int color[n+1]={0};
     int vis[n+1]={0};
     queue<int> q;
     for(int i=1; i<=n; i++){
         if(vis[i]) continue;
         q.push(i);
         color[i]=1;
         vis[i]=1;
         while(!q.empty()){
             int x=q.front();
             q.pop();

             for(int ch:edge[x]){
                 if(!vis[ch]){
                     vis[ch]=1;
                     color[ch]=-color[x];
                     q.push(ch);
                 }
                 else{
                     if(color[ch]==color[x]) {
                         cout<<"-1\n";
                         return;
                     }
                 }
             }
         }
     }
     vector<int> one, two;

     for(int i=1; i<=n; i++){
         if(color[i]==1){
             one.pb(i);
         }
         else two.pb(i);
     }

     cout<<one.size()<<"\n";
     for(int i=0; i<one.size(); i++) cout<<one[i]<<" ";
     cout<<"\n";

     cout<<two.size()<<"\n";
     for(int i=0; i<two.size(); i++) cout<<two[i]<<" ";

}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}