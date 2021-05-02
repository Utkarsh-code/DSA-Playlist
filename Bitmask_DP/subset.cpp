#include<bits/stdc++.h>
using namespace std;
int n;
int a[21];
int main(){

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];


    //iterative dp
    int total=1<<n;

    for(int mask=0;  mask<total;  mask++){

          for(int i=0; i<n; i++){
              if(mask&(1<<i))
              cout<<a[i]<<" ";
          }
          cout<<"\n";
    }
}