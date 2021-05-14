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
double ans[100010];
unordered_map<int, vector<int>> edge;

void dfs(int x, int par){
    
    int ch=0;
    double sum=0;
    ans[x]=0.00000000;
    for(int i:edge[x]){
        if(i!=par){
        dfs(i, x);
        ch+=1;
        sum+=ans[i];}
    }

    if(ch!=0){
        ans[x]+=(1.0*sum/ch)+1;
    }
}
void solve(){
     int n;
     cin>>n;
     if(n==1){
         cout<<"0.000000000000\n";
         return;
     }
     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].push_back(b);
         edge[b].push_back(a);

     }
    
     dfs(1, -1);

     cout<<ans[1]<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(15)<<fixed;
        solve();
    }
    return 0;
}