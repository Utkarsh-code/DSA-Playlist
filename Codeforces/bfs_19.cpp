#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int prime[10010];
vector<int> arr;
void sieve(){
    for(int i=0; i<=10001; i++){
        prime[i]=i;
    }
    prime[1]=0;

    for(int i=2; i*i<=10001; i++){
        if(prime[i]==i){
            for(int j=2*i; j<=10001; j+=i){
                prime[j]=i;
            }
        }
    }
    for(int i=1000; i<=9999; i++){
        if(prime[i]==i) arr.push_back(i);
    }

   // for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
}
int main(){
      sieve();
     // cout<<"utk";
     // for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    // cout<<arr.size()<<" ";
    int t;
    cin>>t;
     while(t--){
         int src,des;
         cin>>src>>des;

         unordered_map<int, vector<int>> adj;

     for(int i=0; i<arr.size(); i++){
         for(int j=i+1; j<arr.size(); j++){
             int src=arr[i];
             int des=arr[j];
             
             int cnt=0;
             while(src>0 && des>0){
                 int r1=src%10;
                 int r2=des%10;

                 if(r1!=r2) cnt++;
                 src=src/10;
                 des=des/10;
             }
             if(cnt==1) {adj[arr[i]].push_back(arr[j]); adj[arr[j]].push_back(arr[i]);}
         }
     }
        //  for(auto i:adj[src]) cout<<i<<" ";
         vector<int> dis(10010, 1000000009);
         vector<int> vis(10010, 0);
         queue<int> q;
         q.push(src);
         dis[src]=0;
         while(!q.empty()){
            // cout<<"ut ";
             int x=q.front();
             q.pop();
             if(x==des) break;

              if(vis[x]) continue;
              vis[x]=1;

             for(auto i:adj[x]){
                // cout<<"ut ";
                 if(dis[i]>1+dis[x]){
                     dis[i]=1+dis[x];
                     q.push(i);
                 }
             }
         }
         cout<<dis[des]<<"\n";
        // cout<<dis[1033]<<" "<<dis[1733]<<" "<<dis[3733]<<" "<<dis[3739]<<" "<<dis[3779]<<" "<<dis[8779]<<" "<<dis[8179]<<" ";
     }
}