#include<bits/stdc++.h>
using namespace std;
int n, m, i1, i2;
char a[100][100];
bool chuaxet[100][100];
typedef pair<int, int> II;
int direcX[] = {1, 1, 0 ,-1, -1, -1, 0, 1};
int direcY[] = {0, 1, 1, 1, 0, -1, -1, -1};
II check(){
    for(; i1 < n ; i1++){
        for(i2 = 0  ; i2 < m ; i2++){
            if(chuaxet[i1][i2] == false && a[i1][i2] == 'W') return II(i1, i2);
        }
    }
    return II(-1, 0);
}
int BFS(){
    queue<II> q;
    II tmp;
    int lt = 0;
    while (true)
    {
        tmp = check();
        //cout<<tmp.first<<" "<<tmp.second<<endl;
        if(tmp.first == -1) break;
        q.push(tmp);
        chuaxet[tmp.first][tmp.second] = true; 
        lt++;
        while (!q.empty())
        {
            II c = q.front();
            q.pop();
            for(int i = 0 ; i < 8 ; i++){
                int x = c.first + direcX[i];
                int y = c.second + direcY[i];
                if(x >= 0 && x < n && y >= 0 && y < m && !chuaxet[x][y] && a[x][y] == 'W'){
                    q.push(II(x, y));
                    chuaxet[x][y] = true;
                }
            }
        }
        
    }
    return lt;
}
int main(){
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++) cin>>a[i][j];
    }
    cout<<BFS()<<endl;
    return 0;
}