#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int pr[10005];
unordered_map<int, vector<int>> edge;

void sieve(){
    for(int i=0; i<10005; i++) pr[i]=1;

    for(int i=2; i*i<10005; i++){
        if(pr[i]==1){
            for(int j=2*i; j<10005; j+=i){
                 pr[j]=0;
            }
        }
    }
    for(int i=1000; i<10000; i++){
        if(pr[i]==1) prime.push_back(i);
    }
}

bool compare(int x, int y){
    int cnt=0;

    string s=to_string(x);
    string t=to_string(y);

    if(s.length()!=t.length()) return false;

    for(int i=0; i<s.length(); i++){
        if(s[i]!=t[i]) cnt++;
    }
    return (cnt==1);
}

int main(){
    sieve();
    int a, b;
    cin>>a>>b;

    for(int i=0; i<prime.size(); i++){
        for(int j=i+1; j<prime.size(); j++){

            int num1=prime[i];
            int num2=prime[j];
            if(compare(num1,num2)==true){
            edge[num1].push_back(num2);
            edge[num2].push_back(num1);}

        }
    }

    queue<pair<int, int>> q;
    q.push({a, 0});
    int vis[10010];

    while(!q.empty()){
        auto x=q.front();
        q.pop();
         
        int node=x.first;
        int d=x.second;

        if(node==b){
            cout<<d<<"\n";
            break;
        }

        for(int i:edge[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i, d+1});
            }
        }
    }
}