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
    int freq[1010];
    memset(freq, 0, sizeof(freq));
     int n, m;
     cin>>n>>m;

     for(int i=0; i<n; i++){
         int l, r;
         cin>>l>>r;

       freq[l]++;
       freq[r+1]--;
     }
     
     for(int i=1; i<1010; i++){
         freq[i]+=freq[i]+freq[i-1];
     }
     
     vector<int> arr;

     for(int i=0; i<1010; i++){
         if(freq[i]!=0) arr.push_back(i);
     }
     
     int ans[m];
     set<int> st;

     for(int i=0; i<m; i++){
             int s;
             cin>>s;

        int diff=mod;
        for(int j=0; j<arr.size(); j++){
            if(abs(s-arr[j])<diff && st.find(arr[j])==st.end()){
                diff=abs(s-arr[j]);
                ans[i]=arr[j];
            }
        }
        st.insert(ans[i]);
     }
    for(int i=0; i<m; i++) cout<<ans[i]<<" ";
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