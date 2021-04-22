#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll cnt=0;
int par(ll idx, ll prev, ll sum, string st){
    
    if(idx==st.length()){
        //if(prev<=sum) cnt++;
        return 1;
    }
    int su=0, ans=0;
    for(int i=idx; i<st.length(); i++){
        su+=st[i]-'0';
        if(sum<=su){
            ans+=par(i+1, prev, su, st);
        }
    }
    return ans;
}
int main(){
    
    ll idx=1;
    while(1){

        string st;
        cin>>st;

        if(st=="bye") break;
        
        cnt=0;
        int ans=par(0, 0, 0, st);
        cout<<idx++<<". "<<ans<<"\n";
    }
}
