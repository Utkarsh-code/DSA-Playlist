//c++ template for competitive programming
#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

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
int dp[10010][2];
int mx_perimeter(int perimeter, int prev, int idx, vector<pi>& arr){
     
     if(idx>=arr.size()) return perimeter;
     int l=arr[idx].first;
     int w=arr[idx].second;
     if(idx==0)
    return max(mx_perimeter(l+perimeter, w, idx+1, arr), mx_perimeter(perimeter+w, l, idx+1,arr));

    return max(mx_perimeter(l+perimeter+ abs(w-prev), w, idx+1, arr), mx_perimeter(perimeter+w+abs(l-prev), l, idx+1, arr));
}
void solve(){
      int n;
      cin>>n;
       vector<pi> arr;

       for(int idx=0; idx<n; idx++){
           int a, b;
           cin>>a>>b;

           arr.push_back(make_pair(a,b));
       }
       memset(dp, 0, sizeof(dp));
       //int ans=mx_perimeter(0, 0, 0, arr) TC=O(2^n)   give TLE
       dp[0][0]=arr[0].first;
       dp[0][1]=arr[0].second;

       for(int i=1; i<n; i++){
           dp[i][0]=max(dp[i-1][0]+arr[i].first + abs(arr[i-1].second-arr[i].second), dp[i-1][1]+arr[i].first+abs(arr[i-1].first-arr[i].second));
           dp[i][1]=max(dp[i-1][0]+arr[i].second+abs(arr[i].first-arr[i-1].second), dp[i-1][1]+arr[i].second +abs(arr[i].first-arr[i-1].first));
       }
       int ans=max(dp[n-1][0], dp[n-1][1]);
      cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int idx=1; idx<=tc; idx++){
        //cout << "Case #" << idx  << ": ";
        solve();
    }
    return 0;
}
