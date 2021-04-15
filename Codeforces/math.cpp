#include<bits/stdc++.h>
using namespace std; 
int main(){
    int x, y;
    cin>>x>>y;

    vector<int> ans;
    int fl=0;
    while(y>x){
        ans.push_back(y);
        if(y%2==0) y=y/2;
        else{
            if((y-1)%10==0)
            y=(y-1)/10;
            else{ 
                fl=1;
                break;
            }
        }
    }
    ans.push_back(y);
    if(fl) cout<<"NO\n";
    else{
        if(ans[ans.size()-1]==x){
            cout<<"YES\n";
            cout<<ans.size()<<"\n";
            reverse(ans.begin(), ans.end());
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i]<<" ";
            }
        }
        else cout<<"NO\n";
    }
}