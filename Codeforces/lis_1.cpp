#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1; i<n; i++){
        int num=arr[i];
        if(num>ans.back()) ans.push_back(num);
        else{
            int fl=1,l=0, r=ans.size()-1;

            while(l<=r){
                int mid=(l+r)/2;
                if(num==ans[mid]){ fl=0; break;}
                else if(num>ans[mid]) l=mid+1;
                else r=mid-1;
            }
            if(fl) ans[l]=num;
        }
    }
    cout<<ans.size()<<"\n";
}