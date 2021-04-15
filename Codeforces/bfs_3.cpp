#include<bits/stdc++.h>
using namespace std;
vector<int> dis(1000005, 0);
int bfs(int v, map<int, vector<int>>&adj, int n){
    queue<int> q;
    q.push(v);
    dis[v]=1;
    vector<bool> vis(n+1, false);

    while(!q.empty()){
        int x=q.front();
        q.pop();

        if(vis[x]) continue;
        vis[x]=true;


        for(auto i:adj[x]){
            if(!vis[i]){
                dis[i]=1+dis[x];
                q.push(i);
            }
        }
    }
    int ans=INT_MIN, idx=0;
    for(int i=1; i<=n; i++){
        if(ans<dis[i]){
            ans=dis[i];
            idx=i;
        }
    }
    return idx;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        map<int, vector<int>> adj;
        for(int i=0; i<n-1; i++){
            int src, des;
            cin>>src>>des;
            src++;
            des++;
            
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        int root=bfs(1, adj, n);
       // dis.erase();
        int ans=bfs(root, adj, n);

        int a=ceil(dis[ans]/2);
        cout<<a<<"\n";
    }
}