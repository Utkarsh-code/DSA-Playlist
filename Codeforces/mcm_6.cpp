#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        string st;
        cin>>st;

        int n=st.length();
        int mx[n][n];
        int mn[n][n];

        for(int i=0; i<n; i++){
            if(i%2==0) {
                mx[i][i]=st[i]-'0';
                mn[i][i]=st[i]-'0';
            }
        }
        for(int l=3; l<=n; l=l+2){
            for(int i=0; i<n-l+1; i=i+2){
                int j=i+l-1;
                mx[i][j]=INT_MIN;
                mn[i][j]=INT_MAX;
                for(int k=i; k<j; k=k+2){
                     if(st[k+1]=='+'){
                         mx[i][j]=max(mx[i][j], mx[i][k]+mx[k+2][j]);
                         mn[i][j]=min(mn[i][j], mn[i][k]+mn[k+2][j]);
                     }
                     else{
                         mx[i][j]=max(mx[i][j], mx[i][k]*mx[k+2][j]);
                         mn[i][j]=min(mn[i][j], mn[i][k]*mn[k+2][j]);
                     }
                }
            }
        }
        cout<<mx[0][n-1]<<" "<<mn[0][n-1]<<"\n";
    }
}