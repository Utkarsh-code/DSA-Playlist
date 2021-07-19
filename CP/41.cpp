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
void solve(){
     int n, t;
     cin>>n>>t;

     int a[n];

     for(int i=0; i<n; i++) cin>>a[i];

     int slowp=0;
     int sum=0;
     int ans=0;
     for(int i=0; i<n; i++){
         sum+=a[i];

         while(sum>t && slowp<n){
             sum-=a[slowp];
             slowp++;
         }

         ans=max(ans, i-slowp+1);
     }
     cout<<ans<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
  //  cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}