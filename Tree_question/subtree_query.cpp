#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
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
unordered_map<int, vector<int>> edge;
vector<int> s;
int val[200005];
int segtree[5*(200005)];
void build_segtree(int node, int st, int end){
      if(st==end){
          segtree[node]=val[s[st]];
          return;
      }

      int mid=(st+end)/2;
      build_segtree(2*node, st, mid);
      build_segtree(2*node+1,mid+1, end);
      segtree[node]=segtree[2*node]+segtree[2*node+1];
}
void update(int node, int st, int end, int idx, int num){
      if(st==end){
          val[s[idx]]=num;
          segtree[node]=num;
          return;
      }
      else{
          int mid=(st+end)/2;
          if(st<=idx && idx<=mid){
             update(2*node,st, mid, idx, num);
          }
          else {
              update(2*node+1, mid+1, end, idx, num);
          }

          segtree[node]=segtree[2*node]+segtree[2*node+1];
      }
}
int query(int node, int st, int end, int l, int r){
    if(st>r || end<l) return 0;
    if(l<=st && end<=r) return (segtree[node]);

    int mid=(st+end)/2;
    int x=query(2*node, st, mid, l, r);
    int y=query(2*node+1, mid+1, end, l, r);

    return (x+y);
}
void dfs(int src, int par){
     s.push_back(src);

     for(int x:edge[src]){
         if(x==par) continue;
         dfs(x, src);
     }
     s.push_back(src);
}
void solve(){
     int n, q;
     cin>>n>>q;

    // int val[n];
    val[0]=0;
     for(int i=1; i<=n; i++) cin>>val[i];

     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);
     }
     dfs(1, -1);
     vector<int> range[n+1];
     for(int i=0; i<s.size(); i++){                   //range[x][0]----> intime of node x;   &&  range[x][1]-----> outtime of node x;
         range[s[i]].push_back(i+1);
     }

     build_segtree(1, 0, s.size()-1);
     while(q--){
         int type;
         cin>>type;

         if(type==1){
             int node, num;
             cin>>node>>num;
             int st=range[node][0];
             int end=range[node][1];
             st--;
             end--;
             update(1, 0, s.size()-1, st, num);
             update(1, 0, s.size()-1, end, num );
         }
         else{
             int node;
             cin>>node;

             int l=range[node][0];
             int r=range[node][1];
             l--;
             r--;

             int ans=query(1, 0, s.size()-1, l, r);
             cout<<ans/2<<"\n";
         }
     }
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