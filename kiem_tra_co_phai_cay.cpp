#include <bits/stdc++.h>
using namespace std;
int V, E;
bool chuaxet[1005];
vector<vector<int>> a;
bool check(){
    for(int i = 1 ; i <= V; i++){
        if(chuaxet[i] == false) return false;
    }
    return true;
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaxet[u] = true;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for(int i = 0 ; i < a[c].size(); i++){
            if(!chuaxet[a[c][i]]) {
                chuaxet[a[c][i]] = true;
                q.push(a[c][i]);
            }
        }
    }
}
bool kt(){
    for(int i = 1 ; i <= V; i++){
        memset(chuaxet, 0, V+1);
        BFS(i);
        if(check()) return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V;
        a.clear();
        a.resize(V+1);
        E = V-1;
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        if(kt()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } 
    return 0;
}