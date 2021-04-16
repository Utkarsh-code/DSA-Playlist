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

void solve(){
  int n;
  cin>>n;

  string st;
  cin>>st;
  
  int f=0;
  int t=0, m=0;
  for(int i=0; i<n; i++){
      if(st[i]=='T') t++;
      else m++;

      if(st[i]=='M'){
          if(t<m) f=1;
      }
  }
     if((2*m)!=t || f==1){cout<<"NO\n"; return;}      
    t=0;
    m=0;
     for(int i=n-1; i>=0; i--){
         if(st[i]=='T') t++;
         else m++;

         if(st[i]=='M'){
             if(t<m){
                 cout<<"NO\n";
                 return;
             }
         }
     }
     cout<<"YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
