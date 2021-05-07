#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

int mod=1e9+7;
int inf=1e18;
int ninf=-1e18;

int pown(int x, int y){
    int res=1;

    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}
unordered_map<int, vector<int>> edge;
void solve(){
    int n, m;
    cin>>n>>m;

    int indegree[n+1]={0};
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int x=q.front();
        q.pop();

        topo.push_back(x);
        for(int i:edge[x]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    if(topo.size()<n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int i=0; i<topo.size(); i++) cout<<topo[i]<<" ";
    cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
