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
     int n;
     cin>>n;

     int a[n], b[n];

     for(int i=0; i<n; i++) cin>>a[i];
     for(int i=0; i<n; i++) cin>>b[i];
     
     int cnt=0;
     int zero=0;
     for(int i=0; i<n; i++){
         a[i]-=b[i];

         if(a[i]>0) cnt++;
         else if(a[i]==0) zero++;
     }
     sort(a, a+n);
     int ans=((cnt)*(cnt-1))/2;
     ans+=cnt*zero;
     int mx=a[n-1], mn=a[0];
    // cout<<ans<<"\n";
     if(mx<=0){
         cout<<"0\n";
         return;
     }

     if(mn>=0){
         cout<<ans<<"\n";
         return;
     }

     int l=0, r=n-1;
     int cn=0;
     while(l<r){

         if(a[l]>=0 && a[r]>=0) break;
         
         if((a[l]+a[r])>0) {
             cn++;
             r--;
         }
         else{
            ans+=cn;
            l++;
         }

     }
    // for(int i=0; i<n; i++) ans+=dp[i];
    // ans+=cnt;
    if(a[l]<0) ans+=cn;
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}