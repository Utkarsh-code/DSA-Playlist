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
     int n, a, b;
     cin>>n>>a>>b;

     string s;
     cin>>s;

     if(b>=0){
         cout<<a*n+b*n<<"\n";
         return;
     }

     else{
         int cnt=1;
         char prev=s[0];
         for(int i=1; i<n; i++){
             if(s[i-1]==s[i]) continue;
             else{
                 cnt++;
                 prev=s[i];
             }
         }

         if(cnt&1){
             cout<<b*((cnt+1)/2)+a*n<<"\n";
         }
         else{
             cout<<b*(cnt/2 +1)+a*n<<"\n";
         }
     }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}