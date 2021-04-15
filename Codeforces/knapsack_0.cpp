#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int max_sum;
        cin>>max_sum;

        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        } 

        int dp[n+1][max_sum+1];
        memset(dp, 0, sizeof(dp));

        dp[0][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=max_sum; j++){
                if(j<arr[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        int ans=0;
        for(int i=max_sum; i>=0; i--){
            if(dp[n][i]){ ans=i; break;}
        }
        int i=n, j=ans;
        
        vector<int> res;
        while(i>=0 && j>=0){
            if(j>=arr[i-1]){
                if(dp[i-1][j-arr[i-1]])  {res.push_back(arr[i-1]);  j=j-arr[i-1];}
            }
             i=i-1;
        }
        reverse(res.begin(), res.end());
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<"sum:"<<ans<<"\n";
    }
}