#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[501][501];
bool chuaxet[500][500];
int direcX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int direcY[8] = {1, 0, -1, -1,-1, 0, 1, 1};
typedef pair<int, int> douInt;
void BFS(int x, int y){
    queue<douInt> q;
    q.push(douInt(x, y));
    chuaxet[x][y] = true;
    douInt tmp;
    while (!q.empty()) 
    {
        tmp = q.front();
        q.pop();
        for(int i = 0 ; i < 8; i++){
            int x1 = tmp.first + direcX[i];
            int y1 = tmp.second + direcY[i];
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m){
                if(!chuaxet[x1][y1] && a[x1][y1] == 1){
                    chuaxet[x1][y1] = true;
                    q.push(douInt(x1, y1));
                }
            }
        }  
    }
}
int demLt(){
    int ans = 0;
    for(int i=0; i< n; i++){
        for(int j=0; j< m ; j++) chuaxet[i][j] = false;
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            if(!chuaxet[i][j] && a[i][j] == 1){
                ans++;
                BFS(i, j);
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                cin>>a[i][j];
            }
        }
        cout<<demLt()<<endl;
    }
    
}