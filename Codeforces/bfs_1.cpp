#include<bits/stdc++.h>
using namespace std;
int solve(string num, int a) 
{ 
    int res = 0; 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} 
int main(){
    int t; cin>>t;

    while(t--){
        int n;
        cin>>n;

       // if(n==1) {cout<<1<<"\n"; return 0;}
        queue<string> q;
        string st="1";
        q.push(st);

        while(!q.empty()){
           string x=q.front();
            q.pop();
            if(solve(x,n)==0) {cout<<x<<"\n"; break;}
            q.push(x+"0");
            q.push(x+"1");
        }
    }
}