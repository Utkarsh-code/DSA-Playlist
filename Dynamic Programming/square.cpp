#include<bits/stdc++.h>
using namespace std;
int main(){

    while(1){
        int n;
        cin>>n;

        if(n==0) break;
        
        int ans=0;
        for(int i=1; i<=n; i++){
            ans+=(n-(i-1))*(n-(i-1));
        }
        cout<<ans<<"\n";
    }
}