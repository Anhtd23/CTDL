#include<bits/stdc++.h>
using namespace std;
int V, E, x,y;
bool chuaxet[1005] = {0};
bool check = false;
int store[1005];
int truoc[1005];
vector<vector<int>>a;
void BFS(int i){
    queue<int> c;
    c.push(i);
    memset(truoc, 0, 4 * (V+1));
    while (!c.empty())
    {
        int k = c.front();
        if(k == y){
            check = true;
            break;
        }
        c.pop();
            for(int j = 0 ; j < a[k].size() ; j++){
                if(!chuaxet[a[k][j]]){
                    c.push(a[k][j]);
                    chuaxet[a[k][j]] = true;
                    truoc[a[k][j]] = k;
                }
            }
    }
    if(check == false) {
        cout<<"-1"<<endl;
        return;
    }
    int k = 0 ;
    store[k++] = y;
    while (true)
    {
        store[k++] = truoc[y];
        y = truoc[y];
        if(y == x) break;
    }
    for(int i = k - 1 ; i >= 0 ; i--) cout<<store[i]<<" "; 
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {   
        check = false;
        cin>>V>>E>>x>>y;
        a.clear();
        a.resize(V+1);
        memset(chuaxet, 0, V+1);
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
            a[tmp2].push_back(tmp1);
        }
        chuaxet[x] = true;
        BFS(x);
    }
    return 0;
}