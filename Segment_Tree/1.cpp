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

 /* int sum=0;
  for(int i=0; i<n; i++){
      int num;
      cin>>num;
      add_self(sum, num);
  }
 int q;
 cin>>q;

 for(int i=1; i<=q; i++){
     int x;
     cin>>x;
     int ans=mul(pown(2, i), sum);
     cout<<ans<<"\n";
 }*/
 string  st;
 cin>>st;
 if(n==0) {cout<<"YES\n"; return;}
 int arr[2]={0};
 int sum=0;
 for(int i=0; i<n; i++){
     sum+=(st[i]-'0');
     if(i+1==(2*sum)) {
         cout<<"YES\n";
         return;
     }
 }
     cout<<"NO\n";    
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
