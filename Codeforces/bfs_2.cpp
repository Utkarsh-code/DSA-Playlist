#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    map<int, vector<int>> adj;
    for(int i=0; i<n-1; i++){
        int src, des;
        cin>>src>>des;

        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    vector<bool> vis(n+1, false);

    queue<int> q;
    q.push(1);
    vector<int> dis(n+1, INT_MIN);
    dis[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(auto i:adj[x]){
            if(!vis[i]) {dis[i]=max(1+dis[x], dis[i]);
            q.push(i);}
        }
    }
    int ans=INT_MIN;
    int node=1;
    for(int i=1; i<=n; i++){
        if(dis[i]>ans) {ans=dis[i]; node=i;}
    }
    q.push(node);
    vector<int> d(n+1, 0);
    vector<bool> v(n+1, false);
    dis[node]=0;
    while(!q.empty()){
        int y=q.front();
        q.pop();

        if(v[y]) continue;
        v[y]=true;

        for(auto i:adj[y]){
            if(!v[i]) {d[i]=1+d[y];
            q.push(i);}
        }
    }
    cout<<*max_element(d.begin(), d.end());
}