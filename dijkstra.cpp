#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> douInt;
int V, E, start;
int D[1005];
vector<vector<douInt>> a;
void Dijkstra(){
    int u , v;
    for(int i = 1 ; i <= V; i++) {
        D[i] = 10000000;
    }
    D[start] = 0;
    priority_queue<douInt, vector<douInt> , greater<douInt> > q;
    q.push(douInt(0, start));
    while (!q.empty()){
        u = q.top().second;
        q.pop();
        for(int i = 0; i < a[u].size(); i++){
            v = a[u][i].first;
            int d_u_v = a[u][i].second;
            if(d_u_v + D[u] < D[v] ){
                D[v] = D[u] + d_u_v;
                q.push(douInt(D[v], v));
            }
        }
    }
    for(int i = 1; i <= V; i++) cout<<D[i]<<" ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E>>start;
        a.clear();
        a.resize(V+1);
        int tmp1, tmp2, tmp3;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2>>tmp3;
            a[tmp1].push_back(douInt(tmp2, tmp3));
            a[tmp2].push_back(douInt(tmp1, tmp3));
        }
        Dijkstra();
    }
    return 0;
}