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
int id[200010];
int sz[200010];

int find(int x){
    while(x!=id[x]) x=id[x];
    return x;
}

void unite(int a, int b){
    a=find(a);
    b=find(b);

    if(sz[a]<sz[b]) swap(a, b);
    sz[a]+=sz[b];

    id[b]=a;
}
void solve(){
     int n, m;
     cin>>n>>m;
     
     for(int i=1; i<=n; i++){
         id[i]=i;
         sz[i]=1;
     }
     int cnt=0;
     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;

         if(find(a)==find(b)) cnt++;
         else{
             unite(a,b);
         }
     }

     int x=find(1);

     for(int i=1; i<=n; i++){
         if(find(i)!=x){
             cout<<"NO\n";
             return;
         }
     }
     if(cnt==1){
         cout<<"FHTAGN!\n";
     }
     else{
         cout<<"NO\n";
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}