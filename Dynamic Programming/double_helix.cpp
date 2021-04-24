#include<bits/stdc++.h>
using namespace std;
int a[10010];
int b[10010];
int n, m;
map<int, vector<int>> arr;
map<int, int> arr1;
map<int, int> arr2;
int dp[2][1000010];
int helix(int x, int idx){
    
      if(idx>=arr[x].size()) return 0;
      if(dp[x][idx]!=-1) return dp[x][idx];
      int curnum=arr[x][idx];
      int ans=helix(x, idx+1)+curnum;
      
      
      if(x==0){
          if(arr2.find(curnum)!=arr2.end())
         ans=max(ans, helix(1-x, arr2[curnum]+1)+curnum);}
        else{
            if(arr1.find(curnum)!=arr1.end()){
                ans=max(ans, helix(1-x, arr1[curnum]+1)+curnum);
            }
        }
      return dp[x][idx]=ans;
}
int main(){

    while(1){
        //int n;
        arr.clear();
        arr1.clear();
        arr2.clear();
        cin>>n;
        if(n==0) break;
        //int a[n];
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            arr[0].push_back(num);
            arr1.insert({num, i});
        }

      //  int m;
        cin>>m;
       // int b[m];
        for(int i=0; i<m; i++) {
            int num;
            cin>>num;
            arr[1].push_back(num);
            arr2.insert({num, i});
        }
        
        memset(dp, -1, sizeof(dp));
        int ans=(helix(0, 0));
        memset(dp, -1, sizeof(dp));
        ans=max(ans, helix(1, 0));

       cout<<ans<<"\n";
    }
}