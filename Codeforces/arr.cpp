#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> st;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        st.push_back(s);
    }
    string tar;
    cin>>tar;
    int sidx;
    cin>>sidx;

    int i=sidx, j=sidx;
    int cnt=0;
    while(1){
        if(st[i%n]==tar || st[n+j]==tar){
            break;
        }
        else{
            cnt++;
            i++;
            j--;
        }
    }
    cout<<cnt<<"\n";
}