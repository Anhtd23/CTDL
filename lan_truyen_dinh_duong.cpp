#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
typedef pair<long long, long long> II;
long long num[200001];
long long D[200001];
int V;
II DFS(int u){
    D[u] = 1;
    num[u] = 0;
    if(a[u].size() == 0 ) return II(1, 1);
    for(int i = 0 ; i < a[u].size() ; i++){
        II k = DFS(a[u][i]);
        D[u] += (2 * k.first -1);
        num[u] += k.second; 
    }
    return II(D[u], num[u]+1);
}
int main(){
    cin>>V;
    a.resize(V+1);
    int tmp;
    for(int i = 2 ;  i <= V; i++){
        cin>>tmp;
        a[tmp].push_back(i);
    }
    DFS(1);
    for(int i = 1 ; i <= V; i++){
        cout<<D[i]+ num[i]<<" ";
    }
    return 0;
}