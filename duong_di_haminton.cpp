#include<bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int>> a;
bool chuaxet[1005]= {0};
bool ans = false;
void hmt(int u, int k){
    if(k == V){
        ans = true;
        return;
    }
    for(int i = 0; i < a[u].size(); i++){
        if(!chuaxet[a[u][i]]){
            chuaxet[a[u][i]] = true;
            hmt(a[u][i], k+1);
            chuaxet[a[u][i]] = false;
        }
    }
}
void cycleA(){
    ans = false;
    for(int i = 1; i < V; i++){
        chuaxet[i] = true;
        hmt(i, 1);
        chuaxet[i] = false;
        if(ans == true) break;
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
        a.resize(100);
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        cycleA();
        if(ans) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}