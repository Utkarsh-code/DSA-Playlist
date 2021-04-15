#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        vector<int> sub;
        for(int j=i; j<n; j++){
            sub.push_back(arr[j]);
            if(sub.size()>=k){
                sort(sub.begin(), sub.end());
                ans=max(ans, sub[(sub.size()+1)/2 -1]);
            }
        }
    }
    cout<<ans<<"\n";
}