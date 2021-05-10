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
void solve(){
     int n, t;
     cin>>n>>t;

     int a[n];
     a[0]=0;

     for(int i=1; i<n; i++) cin>>a[i];

    // if(a[1]==t){
    //     cout<<"YES\n";
    //     return;
    // }

     int num=1;

     while(num<n){
         if(num==t) {
             cout<<"YES\n";
             return;
         }
         num=num+a[num];
     }

     if(num==t){
         cout<<"YES\n";
         return;
     }

     cout<<"NO\n";
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