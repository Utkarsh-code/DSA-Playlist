#include<bits/stdc++.h>
using namespace std;
#define  int long long 


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
int n;
int man[1000], woman[1000];
int grid[1000][1000];
int ans=0;
bool check(){
    for(int i=0; i<n; i++){
        if(man[i]==0 || woman[i]==0) return false;
    }
    return true;
}
void cnt_pair(int x, int y){
    if(x>=n){
     if(check()) {  ans=(ans+1)%mod;}
        return;
    }
    for(int i=0; i<n; i++)
    if(grid[x][i]==1 && man[x]==0 && woman[i]==0){
          man[x]=1;
          woman[i]=1;
          cnt_pair(x+1, 0);
          man[x]=0;
          woman[i]=0;
    }
}
void solve(){
  cin>>n;

  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cin>>grid[i][j];
      }
  } 
  cnt_pair(0, 0);
    for(int i=0; i<n; i++){
        memset(man, 0, sizeof(man));
        memset(woman, 0, sizeof(woman));
      //  if(grid[0][i]==1) {cout<<"utk "; cnt_pair(0, i);}
    }    
    cout<<ans<<"\n"; 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
         cout<<setprecision(10);
         cout<<fixed;
        solve();
    }
    return 0;
}
