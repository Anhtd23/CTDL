#include <bits/stdc++.h>
using namespace std;
int parent[1005];
int V, E, x, y;
vector<vector<int>> a;
bool chuaxet[1005];
bool check = false;
void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaxet[u] = true;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        if(k == y) {
            check = true;
            break;
        }
        for(int i = 0; i < a[k].size(); i++){
            if(!chuaxet[a[k][i]]){
                chuaxet[a[k][i]] = true;
                parent[a[k][i]] = k;
                q.push(a[k][i]);
            }
        }
    }
    if(check == true){
         int store[V+1];
        int i = 0;
        while (y != 0)
        {
            store[i++] = y;
            y = parent[y];
        }
        for(int j = i-1 ; j >=0 ; j--) cout<<store[j]<<" ";
        }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V>>E>>x>>y;
        a.clear();
        a.resize(V+1);
        check = false;
        memset(parent, 0, 4 * (V+1));
        memset(chuaxet, 0, V+1);
        int tmp1, tmp2;
        for(int i = 1 ; i <= E ; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
        }
        BFS(x);
        if(check == false) cout<<-1;
        cout<<endl;
    }

    return 0;
}