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
     int n, m;
     cin>>n>>m;
    int hash[m];
    memset(hash, 0, sizeof(hash));

     for(int i=0; i<n; i++){
         string s;
         cin>>s;

         for(int j=0; j<m; j++){
             hash[j]+=(s[j]-'a');
         }
     }

     for(int i=0; i<n-1; i++){
         string s;
         cin>>s;

         for(int j=0; j<m; j++){
             hash[j]-=(s[j]-'a');
         }
     }
    
    string s;
    for(int i=0; i<m; i++){
      //  s+=char(hash[i])+'a';
        s.push_back(char(hash[i])+'a');
    }
    cout<<s<<"\n";
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