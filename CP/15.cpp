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
     int len;
     cin>>len;

     unordered_map<int, vector<int>> edge;
     int indegree[26]={0};

     string a;
     cin>>a;

     int cnt=0;
     for(int i=1; i<len; i++){
         string b;
         cin>>b;

         int n=a.length();
         int m=b.length();
         
         int x=0, y=0, fl=0;

         while(x<n && y<m){

             if(a[x]!=b[y]){
                 edge[a[x]-'a'].push_back(b[y]-'a');
                 indegree[b[y]-'a']++;
                 fl=1;
                 break;
             }

             x++;
             y++;
         }
         if(fl==0){
             if(x<n) cnt++;
         }
          a=b;
     }

     if(cnt){
         cout<<"Impossible\n";
         return;
     }

     //toposort
     string ans="";
     queue<int> q;
     for(int i=0; i<26; i++){
         if(indegree[i]==0) q.push(i);
     }

     while(!q.empty()){
         int x=q.front();
         q.pop();

         ans+=(x+'a');
         for(int i:edge[x]){
             indegree[i]--;

             if(indegree[i]==0) q.push(i);
         }
     }
     if(ans.length()!=26){
         cout<<"Impossible\n";
         return;
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}