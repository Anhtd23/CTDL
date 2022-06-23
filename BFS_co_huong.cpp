#include<bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int>> a;
bool chuaxet[1005];
void BFS(int u){
    queue<int> q;
    q.push(u);chuaxet[u] = true;
    while(!q.empty()){
        int c = q.front();
        cout<<c<<" ";
        q.pop();
        for(int i = 0 ; i < a[c].size(); i++){
            if(!chuaxet[a[c][i]]){
                chuaxet[a[c][i]] = true;
                q.push(a[c][i]);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
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
        BFS(u);
        cout<<endl;
    }

    return 0;
}