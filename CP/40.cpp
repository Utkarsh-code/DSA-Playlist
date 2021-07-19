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

     int a[n];
     int sum=0;
     for(int i=0; i<n; i++) {cin>>a[i];  sum+=a[i];}

     if(sum%3!=0){
         cout<<"0\n";
         return;
     }
    
     sum=sum/3;
     int dp[n]={0};

     if(a[n-1]==sum) dp[n-1]=1;
     int tar=a[n-1];
     for(int i=n-2; i>=0; i--){
         tar+=a[i];
         if(tar==sum) dp[i]=1+dp[i+1];
         else dp[i]=dp[i+1];
     }
     int s=0;
     int ans=0;
     for(int i=0; i<n && i+2<n; i++){
         s+=a[i];
         if(s==sum) ans+=dp[i+2];
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}