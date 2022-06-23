#include<bits/stdc++.h>
using namespace std;
int V, E, u;
vector<vector<int>> a;
vector<pair<int, int> > cay;
bool chuaxet[1005];
void cayKhung(int u){
    for(int i = 0 ; i < a[u].size(); i++){
        if(!chuaxet[a[u][i]]){
            cay.push_back(pair<int, int>(u, a[u][i]));
            chuaxet[a[u][i]] = true;
            cayKhung(a[u][i]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E>>u;
        int tmp1, tmp2;
        a.clear();
        a.resize(V+1);
        for(int i = 0 ; i < E;i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        cay.clear();
        memset(chuaxet, 0, V+1);
        chuaxet[u] = true;
        cayKhung(u);
        if(cay.size() < V - 1 ) cout<<"-1"<<endl;
        else {
            for(int i=0; i < cay.size(); i++) cout<<cay[i].first<<" "<<cay[i].second<<endl;
        }
    }
    
    return 0;
}