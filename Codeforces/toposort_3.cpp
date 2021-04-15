#include<bits/stdc++.h>
using namespace std;
void dfs(string src, string des, map<string, vector<string>>& adj, map<string, set<string>>& adjList){
         for(auto i:adj[des]){
             adjList[src].insert(i); 
             if(adj.count(i))  dfs(src, i, adj,  adjList);
         }
}
void toposort(string v, map<string, bool>& vis, stack<string>&st, map<string,set<string>>&adj){
    vis[v]=true;

    for(auto i: adj[v]){
        if(!vis[i]) toposort(i, vis, st, adj);
    }
    st.push(v);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        map<string, bool> vis;
        for(int i=0; i<n; i++){
            string s;
            cin>>s;
            vis[s]=false;
        }
        int m; cin>>m;
        map<string, vector<string>> adj;
        map<string, set<string>> adjList;
        map<string, int> indegree;
        for(int i=0; i<m; i++){
            string src, des;
            cin>>src>>des;
            adj[src].push_back(des);
            //indegree[des]++;
        }
        for(auto i=adj.begin(); i!=adj.end(); i++){
            string s=i->first;
            dfs(s, s, adj, adjList);
        }
        /*queue<string> q;
        for(auto i:vis){
            if(indegree[i.first]==0) q.push(i.first);
        }

        while(!q.empty()){
            string st=q.front();
            q.pop();
            cout<<st<<" ";
            for(auto i:adjList[st]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        cout<<"\n\n";*/
        stack<string> mystack;
        for(auto i: vis){
            if(!i.second) toposort(i.first, vis, mystack, adjList);
        }
        while(!mystack.empty()){
            cout<<mystack.top()<<" ";
            mystack.pop();
        }
        cout<<"\n";
    }
}