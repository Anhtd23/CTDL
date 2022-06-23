#include<bits/stdc++.h>
using namespace std;
int V, E;
bool chuaxet[1005];
vector<vector<int>> a;
int check(){
    for(int i = 1 ; i <= V; i++){
        if(chuaxet[i] == false) return i;
    }
    return 0;
}
int DFS(){
    queue<int> q;
    int ans = 0;
    while (true)
    {
        int k = check();
        if(k == 0) break;
        ans++;
        q.push(k);
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            if(!chuaxet[c]){
                chuaxet[c] = true;
                for(int j = 0 ; j < a[c].size(); j++){
                    if(chuaxet[a[c][j]] == false){
                        q.push(a[c][j]);
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        int tmp1, tmp2;
        a.clear();
        a.resize(V+2);
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        memset(chuaxet, 0, V+1);
        int ltAll = DFS();
        for(int i = 1 ; i <= V; i++){
            memset(chuaxet, 0, V+1);
            chuaxet[i] = true;
            if(ltAll < DFS()) cout<<i<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}