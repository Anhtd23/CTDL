#include<bits/stdc++.h>
#include<cstring>
using namespace std;
vector<vector<int>> a;
int V, E, cnt = 0, ans = 0;
int low[1005], num[1005], visit[1005];
vector<int> L;
void DFS(int u){
    num[u] = cnt++;
    low[u] = num[u];
    L.push_back(u);
    visit[u] = true;
    for(int i = 0 ; i < a[u].size(); i++){
        if(visit[a[u][i]] == false) DFS(a[u][i]);
        else low[u] = min(low[u], low[a[u][i]]);
    }
    if(num[u] == low[u]){
        ans++;
        while (true)
        {
            int v = L.back();
            L.pop_back();
            if(v == u ) break;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cnt = ans = 0;
        cin>>V>>E;
        memset(num,-1, 4 * (V+1));
        memset(low, 0, 4*(V+1));
        a.clear();
        a.resize(V+1);
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
        }
        for(int i = 1 ; i <= V; i++ ){
            if(num[i] == -1 ) DFS(i);
        }
        if(ans > 1 ) cout<<"NO"<<endl;
        else cout<<"YES"<<endl; 
    }
    
    return 0;
}