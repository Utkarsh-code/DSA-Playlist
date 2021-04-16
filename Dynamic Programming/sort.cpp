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

 vector<int> even;
 vector<int> odd;

 for(int i=0; i<n; i++){
     int num;
     cin>>num;

     if(num&1) odd.push_back(num);
     else even.push_back(num);
 }
 for(int i=0; i<odd.size(); i++) cout<<odd[i]<<" ";
 for(int j=0; j<even.size(); j++) cout<<even[j]<<" ";
 cout<<"\n";
          
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
