#include<bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int>> a;
bool chuaxet[1005];
void DFS(int u){
    cout<<u<<" ";
    chuaxet[u] = true;
    for(int i = 0; i < a[u].size(); i++){
        if(!chuaxet[a[u][i]]){ 
            DFS(a[u][i]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int u;
        cin>>V>>E>>u;
        a.clear();
        a.resize(V+1);
        memset(chuaxet, 0, V+1);
        int tmp1, tmp2;
        for(int i = 1 ; i <= E ; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
        }
        DFS(u);
        cout<<endl;
    }
    

    return 0;
}