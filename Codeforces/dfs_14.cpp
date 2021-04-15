#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
    int n, m;
    cin>>n>>m;
    
    map<int, vector<pair<int, int>>> adj;
    for(int i=0; i<m; i++){
        int src, des, wt;
        cin>>src>>des>>wt;

        adj[src].push_back({des, wt});
    }
    vector<bool> vis(n+1, false);
    vector<int> dis(n+1, INF);
    dis[1]=0;
    multiset<pair<int, int>> s;
    s.insert({0, 1});
    // cout<<"hu"<<" ";
    while(!s.empty()){
       // cout<<"dv"<<" ";
        pair<int, int> p=*s.begin();
        //cout<<(*p.first)<<" ";
        s.erase(s.begin());

        int curr_node=p.second;
       // cout<<curr_node<<" ";
       // if(vis[curr_node]==true) continue;
       // vis[curr_node]=true;
        for(auto i:adj[curr_node]){
            int next_node=i.first;
            int w=i.second;
            //cout<<w<<" ";
            if(w+dis[curr_node]< dis[next_node]){
                auto f=s.find(make_pair(dis[next_node], next_node));
                if(f!=s.end()) s.erase(f);

                dis[next_node]=w+dis[curr_node];
                s.insert({dis[next_node], next_node});
            }
        }
    }

    for(int i=2; i<=n; i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
}