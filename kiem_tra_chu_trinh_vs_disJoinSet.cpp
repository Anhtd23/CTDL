#include<bits/stdc++.h>
using namespace std;
int V, E;
int store[500000][2];
int parent[1005];
int find(int v){
    if (parent[v] == -1)
        return v;
    return find(parent[v]);
}
bool chuTrinh(){
    memset(parent, -1, 4 * (V+1));
    for(int i = 0 ; i < E; i++){
        int x = find(store[i][0]);
        int y = find(store[i][1]);
        if(x == y ) return true;
        parent[x] = y;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        for(int i = 0 ; i < E; i++){
            cin>>store[i][0]>>store[i][1];
        }
        if(chuTrinh()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}