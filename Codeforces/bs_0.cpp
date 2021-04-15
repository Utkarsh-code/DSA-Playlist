#include<bits/stdc++.h>
using namespace std;
int n,c;
bool check(int d, vector<int>& arr){
    int last=arr[0];
    int cnt=1;
    for(int i=1; i<arr.size(); i++){
         int curr=arr[i];
         if(curr>=last+d) {cnt++; last=curr;}
    }
    if(cnt>=c) return true;
    else return false;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        
        cin>>n>>c;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            arr[i]=a;
        }
        sort(arr.begin(), arr.end());
        int l=0, r=1000000009;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;

            if(check(mid, arr)){
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        cout<<ans<<"\n";
    }
}