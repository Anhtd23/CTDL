#include<bits/stdc++.h>
using namespace std;
int V, E, u;
void BFS(vector<vector<int>> a){
    bool chuaxet[V+1] = {0};
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int k = q.front();
        cout<<k<<" ";
        q.pop();
        chuaxet[k] = true;
        for(int i = 0 ; i < a[k].size(); i++){
            if(chuaxet[a[k][i]] == 0) {
                chuaxet[a[k][i]] = true;
                q.push(a[k][i]);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E>>u;
        vector<vector<int>> a(V+1);
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        BFS(a);cout<<endl;
    }
    
    return 0;
}