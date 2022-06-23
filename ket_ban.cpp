#include<bits/stdc++.h>
using namespace std;
int V, E;
int soLuong[100002];
int store[100002][2];
int parent[100002];
int find(int v){
    if (parent[v] == -1)
        return v;
    return find(parent[v]);
}
int demNhom(){
    for(int i = 1 ; i <= V ; i++) soLuong[i] = 1;
    memset(parent, -1, 4 * (V+1));
    int maxA = 0;
    for(int i = 0 ; i < E; i++){
        int x = find(store[i][0]);
        int y = find(store[i][1]);
        if( x != y ){
            if(soLuong[x] > soLuong[y] ){
                soLuong[x] += soLuong[y];
                parent[y] = x;
            }
            else {
                soLuong[y] += soLuong[x];
                parent[x] = y;
            }
        }
    }
    return *max_element(soLuong, soLuong + V + 1);
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
        cout<<demNhom()<<endl;
    }
    
}
