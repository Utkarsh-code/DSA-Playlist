//unbounded knapsack
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int ew, fw;
        cin>>ew>>fw;

        int n;
        cin>>n;

        int val[n], wt[n];
        for(int i=0; i<n; i++){
            cin>>val[i]>>wt[i];
        }

        int req_wt=fw-ew;
        int min_val[n+1][req_wt+1];
         memset(min_val, 0, sizeof(min_val));

        for(int i=1; i<=n; i++){
            for(int j=0; j<=req_wt; j++){
                if(wt[i-1]>j) min_val[i][j]=min_val[i-1][j];
                else min_val[i][j]=max(min_val[i-1][j], val[i-1]+min_val[i][j-wt[i-1]]);
            }
        }
        cout<<min_val[n][req_wt]<<"\n";
    }
}