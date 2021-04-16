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
int n;
int arr[10010];
int dp[1050][1050];

int greedy(int st, int end, int game_number){
     if(game_number>=n) return 0;
     if(st>end) return 0;
     if(dp[st][end]!=-1) return dp[st][end];

    if(game_number&1){
        if(arr[st]<arr[end])
            return dp[st][end]=greedy(st, end-1, game_number+1);
        return dp[st][end]=greedy(st+1, end, game_number+1);
    }
    return dp[st][end]=max(greedy(st+1, end, game_number+1)+arr[st], greedy(st, end-1, game_number+1)+arr[end]);
    
}
void  solve(){

  int sum=0;
  for(int i=0; i<n; i++) {cin>>arr[i]; sum+=arr[i];}

  memset(dp, -1, sizeof(dp));
  int opt=greedy(0, n-1, 0);
  cout<<opt-(sum-opt);
          
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int game_number=1;
    while(1){
        cin>>n;

        if(n==0) break;
        cout<<"In game "<<game_number<<", the greedy strategy might lose by as many as ";
        solve();
        cout<<" points.\n";
        game_number++;
    }
    return 0;
}
