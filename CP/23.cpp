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
int id[10010];
int sz[10010];

int find(int x){
    while(x!=id[x]) x=id[x];
    return x;
}

void unite(int x, int y){
    x=find(x);
    y=find(y);

    if(sz[x]<sz[y]) swap(x, y);

   // sz[x]+=sz[y];
    id[y]=x;
}
void solve(){
     int n;
     cin>>n;
     
     for(int i=1; i<=n; i++){ id[i]=i; sz[i]=1; }

     int a[n+1], pos[n+1];
     a[0]=0;
     for(int i=1; i<=n; i++) {cin>>a[i]; pos[a[i]]=i;}

     

     for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
             char ch;
            cin>>ch;

            if(ch=='1'){
                if(find(i)!=find(j)){
                    unite(i, j);
                }
            }
         }
     }
     
     unordered_map<int, set<int>> mp;
     for(int i=1; i<=n; i++){
         int par=find(i);
         mp[par].insert(a[i]);
     }
      
      for(int i=1; i<=n; i++){
          int par=find(i);
          a[i]=*(mp[par].begin());
          mp[par].erase(mp[par].begin());
      }
     for(int i=1; i<=n; i++) cout<<a[i]<<" ";
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