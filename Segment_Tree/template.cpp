#include<bits/stdc++.h>
using namespace std;
#define  int long long 

int max_n=2e5+5;
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
void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}
int mul(int a, int b) {
    return (int) a * b % mod;
}
void solve(){
  int n;
  cin>>n;

  int sum=0;
  for(int i=0; i<n; i++){
      int num;
      cin>>num;
      sum=(sum+mod+num)%mod;
  }
 int q;
 cin>>q;

 for(int i=1; i<=q; i++){
     int x;
     cin>>x;
     int ans=mul(pown(2, i), sum);
     cout<<ans<<"\n";
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
