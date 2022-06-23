#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int V, E;
        cin>>V>>E;
        int a[V][V];
        for(int i = 0 ; i < V ; i++){
            a[i][0] = 0;
        }
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1-1][0]++;
            a[tmp1-1][a[tmp1-1][0]] = tmp2;
        }
        for(int i = 0 ; i < V ; i++){
            cout<<i+1<<": ";
            for(int j = 1 ; j <= a[i][0] ; j++) cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    

    return 0;
}