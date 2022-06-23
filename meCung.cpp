#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[101][101];
int parent[101][101];
int mangLt[101];
typedef pair<int, int> II;
vector<II> diamond;
vector<II> cuaso;
vector<vector<int>> edge;
bool xetCua[101];
int directX[] = {0, -1, 0, 1};
int directY[] = {1, 0, -1, 0};
II check(int x){
    for(int i = x ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(parent[i][j] == 0 && (a[i][j] == '.' || a[i][j] == '$')) return II(i, j); 
        }
    }
    return II(-1, -1);
}
void lienThong(){
    queue<II> q;
    int x = 1;
    int lt = 1;
    while (true)
    {
        lt++;
        II k = check(x); 
        if(k.first == -1 ) break; 
        x = k.first;
        q.push(k);
        parent[k.first][k.second] = lt;
        while (!q.empty())
        {            
            II u = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int x = k.first + directX[i];
                int y = k.second + directY[i];
                if(x >= 1 && x <= n && y >= 1 && y <= m &&( a[x][y] == '.' || a[x][y] == '$') && parent[x][y] == 0){
                    parent[x][y] = lt;
                    q.push(II(x, y));
                }
            }
        }
    }
    for(int i = 0 ; i <= n+1;i++){
        for(int j = 0 ; j <= m + 1; j++) cout<<parent[i][j]<<" ";
        cout<<endl;
    }
    edge.resize(lt+1);
    for(int i  = 0 ; i < cuaso.size() ; i++){
        if(parent[cuaso[i].first - 1][cuaso[i].second] != 0 && parent[cuaso[i].first + 1][cuaso[i].second] != 0) edge[parent[cuaso[i].first-1][cuaso[i].second]].push_back(parent[cuaso[i].first+1][cuaso[i].second]);
        if(parent[cuaso[i].first][cuaso[i].second - 1] != 0 && parent[cuaso[i].first][cuaso[i].second + 1] != 0) edge[parent[cuaso[i].first][cuaso[i].second-1]].push_back(parent[cuaso[i].first][cuaso[i].second-1]);
    }
    for(int i = 1 ; i <= lt ; i++){
        for(int j = 0 ; j < edge[i].size(); i++) cout<<edge[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    cin>>n>>m;
    diamond.clear();
    cuaso.clear();
    for(int i = 0; i <= n + 1 ; i++){
        for(int j = 0 ; j <= m + 1; j++){
            if(i == 0 || i == n+1 || j == 0 || j == m+1) {
                a[i][j] = '.';
                parent[i][j] = 1;
            }
            else {
                cin>>a[i][j];
                if(a[i][j] == '$') diamond.push_back(II(i,j));
                else if(a[i][j] == '#') cuaso.push_back(II(i,j));
            }
        }
    }
    lienThong();
    return 0;
}