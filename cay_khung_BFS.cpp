#include<bits/stdc++.h>
using namespace std;
int V, E, u;
vector<vector<int>> a;
vector<pair<int, int> > cay;
bool chuaxet[1005];
void cayKhung(int u){
    queue<int> q;
    q.push(u);
    chuaxet[u] = true;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for(int i = 0 ; i < a[c].size(); i++){
            if(!chuaxet[a[c][i]]){
                cay.push_back(pair<int,int>(c, a[c][i]));
                chuaxet[a[c][i]] = true;
                q.push(a[c][i]);
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
        cayKhung(u);
        if(cay.size() < V - 1 ) cout<<"-1"<<endl;
        else {
            for(int i=0; i < cay.size(); i++) cout<<cay[i].first<<" "<<cay[i].second<<endl;
        }
    }
    
    return 0;
}