#include<bits/stdc++.h>
using namespace std;

/*bool detect_cycle(int v, bool vis[], bool st[], vector<vector<int>>& adj){
    if(!vis[v]){
        vis[v]=true;
        st[v]=true;

        for(int i=0; i<adj[v].size(); i++){
            if(!vis[adj[v][i]] && detect_cycle(adj[v][i],vis, st, adj))
            return true;
            else if(st[adj[v][i]]) return true;
        }
    }
    st[v]=false;
    return false;
}

void toposort(int v, bool vis[], stack<int> & st, vector<vector<int>> & adj){
    vis[v]=true;

    for(int i=0; i<adj[v].size(); i++){
        if(!vis[adj[v][i]]) toposort(adj[v][i],vis, st, adj);
    }
    st.push(v);
}*/

/*void toposort(map<char, bool>&vis, map<char, int>&indegree, map<char, vector<char>>&adj, vector<char>& res){
    int flag=0;
    for(auto i: vis){
        char ch=i.first;

        if(!vis[ch] && indegree[ch]==0){
            for(auto j: adj[ch]) indegree[j]--;
            res.push_back(ch);
            vis[ch]=true;
            toposort(vis, indegree, adj, res);

            vis[ch]=false;
            res.erase(res.end()-1);

            for(auto j: adj[ch]) indegree[j]++;

            flag=true;
        }
    }
    if(!flag){
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
}
*/
int main(){
    int n, m;
    cin>>n>>m;
    int edge[m][2];
    for(int i=0; i<m; i++){
        for(int j=0; j<2; j++){
            cin>>edge[i][j];
        }
    }

    vector<vector<int>> adj(n);
    int indegree[n];
    vector<int> topo_order;
    for(int i=0; i<n; i++) indegree[i]=0;

    for(int i=0; i<m; i++){
        int src=edge[i][0]-1;
        int des=edge[i][1]-1;

        adj[src].push_back(des);
        indegree[des]+=1;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0) q.push(i);
    }
    int i=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo_order.push_back(node);
        for(int j=0; j<adj[node].size(); j++){
            indegree[adj[node][j]]--;
            if(indegree[adj[node][j]]==0) q.push(adj[node][j]);
        }
    }
    if(topo_order.size()==n) {
        for(int i=0; i<n; i++){
            cout<<topo_order[i]+1<<" ";
        }
    }
    else cout<<"Sandro fails";

    /*bool vis[n+1];
    bool vis1[n+1];
    bool st[n+1];
    vector<vector<int>> adj(n+1);

    for(int i=1; i<=n; i++){
        st[i]=false;
        vis[i]=false;
        vis1[i]=false;
    }

    for(int i=0; i<m; i++){
        int src=edge[i][0];
        int des=edge[i][1];

        adj[src].push_back(des);
    }
    
    int fl=0;
    stack<int> sta;
    for(int i=1; i<=n; i++){
        if(detect_cycle(i, vis1, st, adj)){
            fl=1;
            break;
        }

        if(!vis[i]) toposort(i, vis, sta, adj);
    }
    if(fl==1) cout<<"Sandro fails\n";
    else{
        while(!sta.empty()){
            cout<<sta.top()<<" ";
            sta.pop();
        }
    }*/
   
   /*int n;
   cin>>n;
   // vector<char> ch;
    map<char, bool> vis;
    for(int i=0; i<n; i++){
        char ch;
        cin>>ch;
        vis.insert({ch, false});
    }

    int m;
    cin>>m;
    map<char, vector<char>> adj;
    map<char, int> indegree;
    for(int i=0; i<m; i++){
       char src, des;
       cin>>src>>des;
       
       adj[src].push_back(des);
       indegree[des]++;
    }
    vector<char> res;
    toposort(vis, indegree, adj, res);*/
}