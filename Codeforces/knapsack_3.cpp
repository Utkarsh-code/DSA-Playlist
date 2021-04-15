/*
Ques:-http://www.spoj.com/problems/SCUBADIV/
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){

    int reqOxygen, reqNitrogen, n;
    cin>>reqOxygen>>reqNitrogen>>n;
    int Oxygen[n], Nitrogen[n], wt[n];
    for(int i=0; i<n; i++){
        cin>>Oxygen[i]>>Nitrogen[i]>>wt[i];
    }

    int min_wt[n+1][reqOxygen+1][reqNitrogen+1];
    //memset(min_wt, INT_MAX, sizeof(min_wt));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=reqOxygen; j++){
            for(int k=0; k<=reqNitrogen; k++){
                min_wt[i][j][k]=1000000007;
            }
        }
    }
        for(int i=0; i<=n; i++){
            min_wt[i][0][0]=0;
        }

     for(int i=1; i<=n; i++){
         for(int j=0; j<=reqOxygen; j++){
             for(int k=0; k<=reqNitrogen; k++){
                 if(j<Oxygen[i-1] && k<Nitrogen[i-1])
                  min_wt[i][j][k]=min_wt[i-1][j][k];

                 else if(j>=Oxygen[i-1] && k<Nitrogen[i-1]) 
                 min_wt[i][j][k]=min(wt[i-1]+min_wt[i-1][j-Oxygen[i-1]][0], min_wt[i-1][j][k]);

                 else if(j<Oxygen[i-1] && k>=Nitrogen[i-1])
                 min_wt[i][j][k]=min(wt[i-1]+min_wt[i-1][0][k-Nitrogen[i-1]], min_wt[i-1][j][k]);

                 else if(j>=Oxygen[i-1] && k>=Nitrogen[i-1]){
                     min_wt[i][j][k]=min(wt[i-1]+min_wt[i-1][j-Oxygen[i-1]][k-Nitrogen[i-1]], min_wt[i-1][j][k]);
                 }
             }
         }
     }
     cout<<min_wt[n][reqOxygen][reqNitrogen]<<"\n";
    }
}
