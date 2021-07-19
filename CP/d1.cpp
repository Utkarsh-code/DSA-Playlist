

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
     for(int i=0; i<n; i++) cin>>a[i];

     int b[n];
     for(int j=0; j<n; j++) cin>>b[j];

    vector<int> pos, neg;
    
    int sum=0;
    for(int i=0; i<n; i++){
        int diff=b[i]-a[i];
        sum+=diff;

        if(diff>0){
            for(int j=0; j<diff; j++){
                pos.push_back(i+1);
            }
        }
        else{
            for(int j=0; j<abs(diff); j++){
                neg.pb(i+1);
            }
        }
    }
    if(sum!=0){
        cout<<"-1\n";
        return;
    }

    cout<<pos.size()<<"\n";
    for(int i=0; i<pos.size(); i++){
        cout<<neg[i]<<" "<<pos[i]<<"\n";

    }
   // cout<<"\n";
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