#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
void bfs(int v,map<int, vector<int>>&adj, vector<int>& d){
    d[v]=0;

    queue<int>q;
    q.push(v);

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto i:adj[x]){
            if(d[i]==INF){
                d[i]=1+d[x];
                q.push(i);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        map<int, vector<int>> adj;
        for(int i=0; i<m; i++){
            int src, dis;
            cin>>src>>dis;

            adj[src].push_back(dis);
            adj[dis].push_back(src);
        }
        vector<int> d(n+1, INF);
        bfs(1, adj, d);

        vector<int> even;
        vector<int> odd;

        for(int i=1; i<=n; i++){
            if(d[i]%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        if(odd.size()>even.size()){
            cout<<even.size()<<"\n";
            for(int i=0; i<even.size(); i++){
                cout<<even[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<odd.size()<<"\n";
            for(int i=0; i<odd.size(); i++){
                cout<<odd[i]<<" ";
            }
            cout<<"\n";
        }
    }
}