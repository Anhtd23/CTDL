#include<bits/stdc++.h>
using namespace std;
vector<int> road;
int V, E, x, y;
vector<vector<int>> a;
bool chuaxet[1005];
bool check = false;
void DFS(int u){
    if(check == true) return;
    road.push_back(u);
    if(u == y ) {
        check = true;
        for(int i=0; i < road.size(); i++) cout<<road[i]<<" ";
    }
    chuaxet[u] = true;
    for(int i = 0; i < a[u].size();i++){
        if(!chuaxet[a[u][i]]){
            DFS(a[u][i]);
        }
    }
    chuaxet[u] = true;
    road.pop_back();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V>>E>>x>>y;
        road.clear();
        a.clear();
        a.resize(V+1);
        check = false;
        memset(chuaxet, 0, V+1);
        int tmp1, tmp2;
        for(int i = 1 ; i <= E ; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
        }
        DFS(x);
        if(check == false) cout<<-1;
        cout<<endl;
    }

}