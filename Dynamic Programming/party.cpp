#include<bits/stdc++.h>
using namespace std;
#define  pi pair<int, int>
#define ll long long int
int dp[1010][1010];
int t_cost;
int party(int sum, int fun, int idx, vector<pi>&arr){
    
    if(idx==arr.size()) return 0;
    if(sum<=0) return 0;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    int cost=arr[idx].first;
    int new_fun=arr[idx].second;

    if(sum<cost)  return dp[idx][sum]=party(sum, fun, idx+1, arr);
    //return dp[idx][sum];}
    return dp[idx][sum]=max(party(sum-cost, fun+new_fun, idx+1, arr)+new_fun, party(sum, fun, idx+1, arr));

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){

        int  n;
        cin>>t_cost>>n;

        if(t_cost==0 && n==0) break;
        vector<pi> arr;
        for(int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            arr.push_back(make_pair(a, b));
        }
       memset(dp, 0, sizeof(dp));
      
      // int  ans=party(t_cost, 0, 0, arr);
       // for(int i=0; i<n; i++){
       //    cout<<dp[i].first<<" "<<dp[i].second<<" ";
       //}
       //cout<<t_cost-ans.second<<" "<<ans.first<<" \n";

       int ans2=0;
       for(int i=1; i<=n; i++){
           int cost=arr[i-1].first;
           int fun=arr[i-1].second;
           for(int j=0; j<=t_cost; j++){
           if(cost>j) dp[i][j]=dp[i-1][j];
           else dp[i][j]=max(dp[i-1][j], dp[i-1][j-cost]+fun);}
       }
       
       //int ans2=0;
       int ans=dp[n][t_cost];
       for(int i=0; i<=t_cost; i++){
           if(dp[n][i]==ans){
               ans2=i;
               break;
           }
       }
       //cout<<"\n";
      // ans2=dp[0][49];
      cout<<ans2<<" "<<ans<<"\n";
    }
}