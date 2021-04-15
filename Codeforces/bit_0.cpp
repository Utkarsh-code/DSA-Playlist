#include<bits/stdc++.h>
using namespace std;
bool check(int arr[], int n, int tar){
    int sum=0;
    int idx=0;
    while(n){
        int k=n&1;
       // cout<<k<<" ";
        if(k==1) sum+=arr[idx];
        idx++;
        n=n>>1;
    }
    //cout<<sum<<" ";
    if(sum==tar) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n, sum;
        cin>>n>>sum;

        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        int range=(1<<n)-1, cnt=0;
        for(int i=0; i<=range; i++){
               bool ans=check(arr, i, sum);
               if(ans==true) cnt++;
        }
        int k=n&1;
        //cout<<k<<" ";
        if(cnt>0) cout<<"Yes\n";
        else cout<<"No\n";
    }
}