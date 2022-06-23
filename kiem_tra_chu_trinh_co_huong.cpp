#include<bits/stdc++.h>
using namespace std;
int V, E;
int chuaxet[1005];
bool check = false;
vector<vector<int>> a;
void DFS(int v){
    chuaxet[v] = 1;
    for(int i = 0 ; i < a[v].size(); i++){
        if(chuaxet[a[v][i]] == 0 ){
            DFS(a[v][i]);
        }
        else if(chuaxet[a[v][i]] == 1 ){
            check = true;
            return;
        }
    }
    chuaxet[v] = 2;
}
void kt(){
    memset(chuaxet, 0, 4*(V+1));
    for(int i = 1 ; i < V; i++){
        if(chuaxet[i] == 0 ) DFS(i);
    }
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
        check = false;
        memset(chuaxet, 0, 4*(V+1));
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
        }
        kt();
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }    

    return 0;
}