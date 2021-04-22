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

  string a, b, c;
  cin>>a>>b>>c;

  int i=0, j=0, k=0;
  string ans="";
  while(i!=2*n && j!=2*n && k!=2*n){

      if(a[i]==b[j] && b[j]==c[k]){
          ans+=a[i];
          i++;
          j++;
          k++;
      }

      else if(a[i]==b[j]){
          ans+=a[i];
          i++; 
          j++;
      }

      else if(a[i]==c[k]){
          ans+=a[i];
          i++;
          k++;
      }
      else if(b[j]==c[k]){
          ans+=b[j];
          j++;
          k++;
      }
  }
       if(i!=2*n && 2*n-i<=3*n-ans.length()){
           ans+=a.substr(i);
       }  

       if(j!=2*n && 2*n-j<=3*n-ans.length()) ans+=b.substr(j);
       if(k!=2*n && 2*n-k<=3*n-ans.length()) ans+=c.substr(k);

       cout<<ans<<"\n";
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
