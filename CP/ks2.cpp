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
     int n, c;
     cin>>n>>c;
     
     map<int, int> mp;
     int t=n;
     while(t--){
         int l, r;
         cin>>l>>r;

         for(int i=l+1; i<r; i++){
             mp[i]++;
         }
     }
     
     vector<int> arr;
     for(auto i:mp){
         arr.push_back(i.second);
     }
     sort(arr.begin(), arr.end());
     reverse(arr.begin(), arr.end());


     int ans=n;
     for(int i=0; i<arr.size(); i++){
         ans+=arr[i];
         c--;

        if(c==0) break;
     }
     cout<<ans<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}