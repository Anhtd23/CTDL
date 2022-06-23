#include<bits/stdc++.h>
using namespace std;
int V;
int parent[100001];
int countA[100001];
void inDuong(int v){
    if(v == -1 ) return;
    inDuong(parent[v]);
    cout<<v<<" ";
}
int main(){
    int t;
    cin>>t;
    parent[1] = -1;
    while (t--)
    {
        cin>>V;
        memset(countA, 0, sizeof(countA));
        int x, y;
        for(int i = 0 ; i < V-1; i++){
            cin>>x>>y;
            countA[x]++;
            countA[y]++;
            parent[y] = x;
        }
        for(int i = 2 ; i <= V ; i++){
            if(countA[i] == 1 ) {
                inDuong(i);
                cout<<endl;
            }
        }
    }
    

    return 0;
}