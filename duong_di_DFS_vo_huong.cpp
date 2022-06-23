#include<bits/stdc++.h>
using namespace std;
int V, E, x,y;
bool chuaxet[1005] = {0};
bool check = false;
int store[1005];
int sau[1005];
vector<vector<int>>a;
void DFS(int i){
    stack<int> c;
    c.push(i);
    memset(sau, 0, 4 * (V+1));
    while (!c.empty())
    {
        int k = c.top();
        if(k == y){
            check = true;
            break;
        }
        c.pop();
            for(int j = 0 ; j < a[k].size() ; j++){
                if(!chuaxet[a[k][j]]){
                    c.push(k);
                    c.push(a[k][j]);
                    chuaxet[a[k][j]] = true;
                    sau[k] = a[k][j];
                    break;
                }
            }
    }
    if(check == false) {
        cout<<"-1"<<endl;
        return;
    }
    while (true)
    {
        cout<<x<<" ";
        if(x== y) break;
        x = sau[x];
    }
    //for(int j = k - 1; j >= 0 ; j--) cout<<store[j]<<" ";
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
        DFS(x);
    }
    return 0;
}