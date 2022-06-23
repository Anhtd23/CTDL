#include<bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int>> a;
bool chuaxet[1005];
int parent[1005];
void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaxet[u] = true;
    parent[u] = u;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for(int i = 0; i < a[k].size(); i++){
            if(!chuaxet[a[k][i]]){
                chuaxet[a[k][i]] = true;
                q.push(a[k][i]);
                parent[a[k][i]] = parent[k];
            }
        }
    }
}
void chuTrinh(){
    for(int i = 1; i <=  V ; i++){
        if(!chuaxet[i]) BFS(i);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V>>E;
        int tmp1 , tmp2;
        a.clear();
        a.resize(V+1);
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        memset(chuaxet, 0, V+1);
        memset(parent, 0, 4 * (V+1));
        chuTrinh();
        int Q;
        cin>>Q;
        for(int i = 0 ; i < Q; i++){
            int dau, cuoi;
            cin>>dau>>cuoi;
            if(parent[dau] == parent[cuoi]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}