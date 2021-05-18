#include<bits/stdc++.h>
using namespace std;
int n, k;
int arr[100010];
vector<int> ans;
void print(int idx){
    for(int i=0; i<idx; i++) cout<<ans[i]<<" ";

    cout<<"\n";
}
void solve_subsetsum(int idx, int sum, int ite){
    
       if(sum==k){
           print(idx);
           //solve_subsetsum(idx-1, sum-arr[ite-1], ite+1);
           return;
       }
    for(int i=ite; i<n; i++){
       // if(i>ite && arr[i]==arr[i-1]) continue;   // for unique subset (sort the array list);
        ans.push_back(arr[i]);

        solve_subsetsum(idx+1, sum+arr[i], i+1);
        ans.pop_back();
    }
}
int main(){
    //int n, k;
    cin>>n>>k;

   // int arr[n];
    for(int i=0; i<n; i++)  cin>>arr[i];

    solve_subsetsum(0, 0, 0);
}