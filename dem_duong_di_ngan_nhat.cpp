#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long > II;
int V, E;
vector<vector<II>> a;
long long num[100001];
long long D[100001];
void countRoad(){
    num[1] = 1;
    D[1]  = 0;  
    for(int i = 2 ; i <= V; i++) D[i] = 1e18;
    priority_queue<II, vector<II>, greater<II> > q;
    q.push(II(0, 1));
    while (!q.empty())
    {
        long long c = q.top().second;
        q.pop();
        if(c == V) {
            cout<<D[V]<<" "<<num[V]<<endl;
            return;
        }
        for(int i = 0 ; i < a[c].size() ; i++){
            long long k = a[c][i].first;
            long long d_u_v = a[c][i].second;
            if(D[k] > D[c] + d_u_v){
                D[k] = D[c] + d_u_v;
                num[k] = num[c];
                q.push(II(D[k], k));
            }
            else if(D[k] == D[c] + d_u_v){
                num[k] += num[c];
            }
        }
    }
}
int main(){
    cin>>V>>E;
    int tmp1, tmp2, tmp3;
    a.resize(100001);
    for(int i = 0 ; i < E ; i++){
        cin>>tmp1>>tmp2>>tmp3;
        a[tmp1].push_back(II(tmp2, tmp3));
        a[tmp2].push_back(II(tmp1, tmp3));
    }
    countRoad();
    return 0;
}