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
int fun(int n, int p){
    if(n==0) return 0;

    int ans=0;
    while(n%p==0){
        ans++;
        n=n/p;
    }

    return ans;
}
void solve(){
     int n, q, p;


     cin>>n>>q>>p;

     int arr[n];
     for(int i=0; i<n; i++) cin>>arr[i];

     while(q--){
         int type;
         cin>>type;

         if(type==1){
             int pos, val;
             cin>>pos>>val;
             pos--;
             arr[pos]=val;
         }
         else{
             int s, l, r;
             cin>>s>>l>>r;

             l--;
             r--;
              
              int ans=0;
             for(int i=l; i<=r; i++){
                 int val=arr[i];
                 int a=pown(val,s);
                // cout<<a<<" ";
                 int b=val%p;
                 b=pown(b, s);

                 int x=a-b;
               //  cout<<x<<" ";
                 ans+=fun(x, p);
             }
             cout<<ans<<" ";
         }
     }
     cout<<"\n";
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