#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    string st;
    cin>>st;

    vector<int> indeg(n+1, 0);
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int src, des;
        cin>>src>>des;

        adj[src].push_back(des);
        indeg[des]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) q.push(i);
    }
    int cnt=0;
    vector<int> toposort;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cnt++;
        toposort.push_back(x);
        for(auto i:adj[x]){
            indeg[i]--;
            if(indeg[i]==0) q.push(i);
        }
    }
    if(cnt<n) cout<<"-1\n";
    else{
         int  ans=0;
         int dp[n+1];

        for(char i='a'; i<='z'; i++){
            memset(dp, 0, sizeof(dp));
            for(auto j:toposort){
                if(st[j-1]==i) dp[j]++;

                for(auto k:adj[j]){
                    dp[k]=max(dp[k], dp[j]);
                }
                ans=max(ans, dp[j]);
            }
        }
        cout<<ans<<"\n";
    }
}