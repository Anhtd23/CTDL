#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
bool check[1001];
void DFS(int V, int E, int u){
    cout<<u<<" ";
    check[u-1] = true;
    for(int i = 1 ; i <= a[u-1][0] ; i++){
        if(check[a[u-1][i]-1] == false){
            DFS(V, E, a[u-1][i]);
        } 
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int V, E, u;
        cin>>V>>E>>u;
        for(int i = 0 ; i < V ; i++){
            a[i][0] = 0;
            check[i] = false;
        }
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1-1][0]++;
            a[tmp1-1][a[tmp1-1][0]] = tmp2;
            a[tmp2-1][0]++;
            a[tmp2-1][a[tmp2-1][0]] = tmp1;
        }
        DFS(V, E, u);cout<<endl;
    }
    

    return 0;
}