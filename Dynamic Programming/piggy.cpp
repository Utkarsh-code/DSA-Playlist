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
int dp[510][10010];
int mn_amount(int idx, int wt, vector<pi>& arr){

    if(wt==0) return 0;
    if(wt<0) return inf;
    if(idx==arr.size()) return inf;
    if(dp[idx][wt]!=-1) return dp[idx][wt];
    int val=arr[idx].first;
    int w=arr[idx].second;

    if(wt<w) return dp[idx][wt]=mn_amount(idx+1, wt, arr);
    return dp[idx][wt]=min(mn_amount(idx+1, wt, arr), mn_amount(idx, wt-w, arr)+val);
}
void solve(){
    int p_wt, t_wt;
    cin>>p_wt>>t_wt;

    int wt=t_wt-p_wt;

    int n;
    cin>>n;
    
    vector<pi> arr;
    for(int i=0; i<n; i++){
        int p, w;
        cin>>p>>w;

        arr.push_back(make_pair(p, w));
    }
    memset(dp, -1, sizeof(dp));
    int ans=mn_amount(0, wt, arr);  
    if(ans==inf){
        cout<<"This is impossible.\n";
    }
    else{
        cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
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
        solve();
    }
    return 0;
}
