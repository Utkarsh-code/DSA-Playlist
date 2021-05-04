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

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int vis[n+1]={0};
    stack<int> st;
    map<int, int> par;
    queue<pi> q;
    q.push({1, 0});
    int fl=1;
    vis[1]=1;
    while(!q.empty()){
        pi p=q.front();
        q.pop();

        int node=p.first;
        int s=p.second;
        if(node==n){

            while(1){
                st.push(n);
                n=par[n];
                if(n==1) break;
            }
            st.push(1);
            fl=0;
            break;
            
        }

        for(int x:edge[node]){
            if(!vis[x]){
                vis[x]=1;
               q.push({x, s+1});
               par[x]=node;
            }
        }
    }
    if(fl) cout<<"IMPOSSIBLE\n";
    else{
        cout<<st.size()<<"\n";

        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
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
