#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        int sum;
        cin>>sum;

        int total=(1<<n), f=1;
        for(int mask=0; mask<total; mask++){
            int add=0;
            for(int i=0; i<n; i++){
               if(mask &(1<<i))
               add+=a[i];
            }
            if(add==sum){
                cout<<"YES\n";
                f=0;
                break;
            }
        }
        if(f) cout<<"NO\n";
    }
}