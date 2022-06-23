#include<bits/stdc++.h>
using namespace std;
int V, E;
int chuaxet[1005];
vector<vector<int>> a;
int parent[1005];
bool BFS(int v){
    queue<int> q;
    q.push(v);
    chuaxet[v] = 1;
    parent[v] = v;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for(int i = 0; i < a[c].size(); i++){
            if(chuaxet[a[c][i]] == 0 ){
                chuaxet[a[c][i]] = 1;
                parent[a[c][i]] = parent[c];
                q.push(a[c][i]);
            }
            else if(parent[a[c][i]] == parent[c] ){
                return true;
            }
        }
    }
    return false;
}
bool kt(){
    memset(chuaxet, 0, 4*(V+1));
    memset(parent, 0, 4 * (V+1));
    for(int i = 1 ; i < V; i++){
        if(chuaxet[i] == 0 ){
            if(BFS(i) == true) return true;           
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        int tmp1, tmp2;
        a.clear();
        a.resize(V+1);
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
        }
        if(kt()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }    

    return 0;
}