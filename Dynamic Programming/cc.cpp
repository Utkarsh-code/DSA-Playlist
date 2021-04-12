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

void solve(){
    
    int row, col, k;
    cin>>row>>col>>k;

    int grid[row][col];
    int cnt=0, r=0, c=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
             cin>>grid[i][j];
             if(grid[i][j]>=k && cnt==0){r=i; c=j; cnt=1;}
        }
    }
         int ans=0;
         for(int i=1; i<=min(row, col); i++){
             if((row-r-(i-1)<=0) || (col-c-(i-1)<=0)) break;
             ans+=(row-r-(i-1))*(col-c-(i-1));
         }
       //  cout<<ans<<" ";
          int dp[row+1][col+1];
             memset(dp, 0, sizeof(dp));

             for(int i=1; i<=row; i++){
                 for(int j=1; j<=col; j++){
                   dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i-1][j-1];
                 }
             }


         for(int sz=1; sz<=min(row, col); sz++){
             int f=0;
            
             for( int i=1; i<=row; i++){
               int fl=0;
                 for( int j=1; j<=col; j++){
                     if(grid[i-1][j-1]>=k){
                         fl=1;
                         break;
                     }
                      int sum=0;
                     if(i-sz>=0 && j-sz>=0){
                         sum+=dp[i][j]-dp[i-sz][j]-dp[i][j-sz]+dp[i-sz][j-sz];
                         if(sum/(sz*sz)>=k) ans++;
                     }
                 }
                 if(fl==1) { f=1;break;}
             }
             if(f==1) break;
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
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
