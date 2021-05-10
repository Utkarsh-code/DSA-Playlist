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
int id[500010];
int sz[500010];

int find(int x){
    while(x!=id[x]){ id[x]=id[id[x]];  x=id[x];}
    return x;
}

void unite(int x, int y){
    int a=find(x);
    int b=find(y);
    if(sz[a]<sz[b]) swap(a, b);
    sz[a]+=sz[b];

    id[b]=a;
}
void solve(){
     int n,  g;
     cin>>n>>g;

     for(int i=0; i<=n; i++){
         sz[i]=1;
         id[i]=i;
     }

     for(int i=0; i<g; i++){
         int m;
         cin>>m;
         
         if(m!=0){
         int num;
         cin>>num;

         for(int i=1; i<m; i++){
             int a;
             cin>>a;

             if(find(a)!=find(num)){
                 unite(a, num);
             }
             num=a;
         }
         }
     }
     for(int i=1; i<=n; i++){
         cout<<sz[id[i]]<<" ";
     }
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