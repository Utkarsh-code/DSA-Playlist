#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define ff first
#define ss second
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
    int degree[n+1]={0};
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        degree[a]++;
        degree[b]++;
    }
    
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(degree[i]&1) cnt++;
    }
    if(cnt!=2 || degree[n]==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    stack<int> st;
    st.push(1);

    while(!st.empty()){
        int u=st.top();

        if(degree[u]==0){
            ans.push_back(u);
            st.pop();
        }
        else{
            int v=edge[u][edge[u].size()-1];
            degree[v]--;
            degree[u]--;
            st.push(v);
            edge[u].pop_back();
        }
    }
    if(ans.size()!=m+1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
