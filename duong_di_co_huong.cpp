#include<bits/stdc++.h>
using namespace std;
int V, E, u, v;
vector<vector<int> > a;
int truoc[1001];
int chuaxet[1001];
void solve(){
    memset(truoc, 0, 1001*4);
    memset(chuaxet, 0, 1001*4);
    queue<int> q;
    q.push(u);
    chuaxet[u] = true;
    bool check = true;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        if(c == v) {
            check = false;
            break;
        }
        for(int i = 0 ; i < a[c].size(); i++){
            if(chuaxet[a[c][i]] == false){
                q.push(a[c][i]);
                chuaxet[a[c][i]] = true;
                truoc[a[c][i]] = c;
            }
        }
    }
    if(check == true) cout<<-1<<endl;
    else{
        stack<int> c;
        int tmp = v;
        while(v != u){
            c.push(v);
            v = truoc[v];
        }
        c.push(u);
        while (!c.empty())
        {
            cout<<c.top()<<" ";
            c.pop();
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        a.clear();
        cin>>V;
        cin>>E>>u>>v;
        a.resize(V+1);
        int tmp1, tmp2;
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1].push_back(tmp2);
        }
        solve();
    }
    

    return 0;
}