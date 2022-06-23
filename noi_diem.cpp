#include<bits/stdc++.h>
using namespace std;
int V;
typedef struct Dinh{
    double x, y;
}dinh;
double F[101][101];
double D[101];
bool chuaxet[101];
typedef pair<double, int> DD;
dinh a[101];
double distance(dinh a, dinh b){
    double x = (a.x - b.x);
    double y = (a.y - b.y);
    return sqrt(x * x + y * y);
}
int ans = 0;
bool check(){
    for(int i = 1 ; i <= V ; i++){
        if(chuaxet[i] == false) {
            ans = i;
            return false;
        }
    }
    return true;
}
void dijkstra(){
    memset(chuaxet, 0, V+1);
    priority_queue<DD, vector<DD>, greater<DD> > q;
    D[1] = 0;
    for(int i = 2 ; i <= V; i++ ) D[i] = 1000000000.0;
    q.push(DD(0, 1));
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        cout<<u<<endl;
        if(check()) 
            break;
        for(int i = 1 ; i <= V; i++){
            if(i != u && !chuaxet[i]){
                double dis = F[u][i];
                if(D[i] > D[u] + dis){
                    D[i] = D[u] + dis;
                    q.push(DD(D[i], i));
                }
            }
        }
    }
    cout<<ans<<endl;
    cout<<fixed<<setprecision(6);
    cout<<D[ans]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V;
        double tmp1, tmp2;
        for(int i = 1 ; i <= V ; i++){
            cin>>tmp1>>tmp2;
            a[i].x = tmp1;
            a[i].y = tmp2;
        }
        for(int i = 1 ; i < V; i++){
            for(int j = i + 1 ; j <= V ; j++) F[i][j] = F[j][i] = distance(a[i], a[j]);
        }
        for(int i = 1 ; i <= V; i++){
            for(int j = 1 ; j <= V ; j++) cout<<F[i][j]<<" ";
            cout<<endl;
        }
        for(int i = 1 ; i <= V ; i++) F[i][i] = 0.0;
        dijkstra();
    }
    return 0;
}