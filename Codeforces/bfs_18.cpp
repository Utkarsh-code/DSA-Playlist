#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
int dijkstra(unordered_map<int, vector<pair<int, int>>> &adj){
        vector<int> dis(n+1, 1000000009);
        vector<bool> vis(n+1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 1));
        dis[1]=0;

        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();

            int wt=x.first;
            int node=x.second;

            if(vis[node]) continue;
            vis[node]=true;

            for(auto i:adj[node]){
                int ndis=wt+i.second;
                if(dis[i.first]>ndis){
                    dis[i.first]=ndis;
                    pq.push(make_pair(dis[i.first], i.first));
                }
            }
        }
        int sum=0;
        for(int i=1; i<=n; i++){
            sum+=dis[i];
        }
        return sum;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int  m;
        cin>>n>>m;

        unordered_map<int, vector<pair<int, int>>> adj1;
        unordered_map<int, vector<pair<int, int>>> adj2;
         for(int i=0; i<m; i++){
             int src, des, wt;
             cin>>src>>des>>wt;

             adj1[src].push_back(make_pair(des, wt));
             adj2[des].push_back(make_pair(src, wt));
         }
         int ans1=dijkstra(adj1);
         int ans2=dijkstra(adj2);

         int ans=ans1+ans2;
         cout<<ans<<"\n";
    }
}