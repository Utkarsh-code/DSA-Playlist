#include<bits/stdc++.h>
using namespace std;
int rec_knapsack(int w, int wt[], int val[], int n){
    if(w==0 || n==0) return 0;
    if(w<wt[n-1]) return rec_knapsack(w, wt, val, n-1);
    else{
        return max(val[n-1]+rec_knapsack(w-wt[n-1], wt, val, n-1), rec_knapsack(w, wt, val, n-1));
    }
}
int main(){
    int W, n;
    cin>>W>>n;

    int wt[n], val[n];
    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }

    int ans=rec_knapsack(W, wt, val, n);
    cout<<ans<<"\n";
}