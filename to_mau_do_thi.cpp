#include<bits/stdc++.h>
using namespace std;
int V, E, M;
vector<vector<int>> a;
int color[1005];
bool danhDau[1005];
bool ans;
bool check(){
    for(int i = 1 ; i <= V ; i++){
        for(int j = 0 ; j < a[i].size() ; j++){
            if(color[i] == color[a[i][j]]) return false; 
        }
    }
    return true;
}
void paintPoint(int u){
    if(ans == true) return;
    if(u > V){
        if(check() == true){
            ans = true;
        }
        return;
    }
    bool chuaxet[M+1] = {0};
    for(int i = 0 ; i < a[u].size() ; i++){
        chuaxet[color[a[u][i]]] = 1;
    }
    for(int i = 1 ; i <= M ; i++){
        if(chuaxet[i] == 0){
            color[u]  = i;
            for(int j = 0 ; j < a[u].size() ; j++){
                paintPoint(u+1);
            }
        }
    }
}
void paint(){
    memset(danhDau, 0 , V+1);
    memset(color, 0, 4*(V+1));
    ans = false;
    paintPoint(1);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E>>M;
        int tmp1, tmp2;
        a.clear();
        a.resize(V+1);
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        paint();
    }
    

    return 0;
}