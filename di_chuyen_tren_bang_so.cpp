#include<bits/stdc++.h>
using namespace std;
typedef struct Canh{
    int x, y, W;
}canh;
struct cmp{
    bool operator()(canh &a, canh &b){
        return a.W > b.W;
    }
};
int N , M;
int D[500][500];
int a[500][500];
bool chuaxet[500][500];
int direcX[] = {0, -1, 0, 1};
int direcY[] = {1, 0, -1, 0};
int dijkstra(){
    priority_queue<canh, vector<canh>, cmp >q;
    canh tmp, tmp1;tmp.x = 0;tmp.y = 0;tmp.W = a[0][0];
    q.push(tmp);
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++) {
            D[i][j] = 1e9;
            chuaxet[i][j] = false;
        }
    }
    D[0][0] = a[0][0];
    while (!q.empty())
    {
        tmp1 = q.top();
        q.pop();
        //cout<<tmp1.x<<" "<<tmp1.y<<" " <<tmp1.W<<endl;
        chuaxet[tmp1.x][tmp1.y] = true;
        for(int i = 0 ; i < 4; i++){
            int x = tmp1.x + direcX[i];
            int y = tmp1.y + direcY[i];
            if(x >= 0 && x < N && y >= 0  && y < M && !chuaxet[x][y] ){
                if( D[x][y] > D[tmp1.x][tmp1.y] + a[x][y]){
                    D[x][y] = D[tmp1.x][tmp1.y] + a[x][y];
                    tmp.x = x;tmp.y = y;tmp.W = D[x][y];
                    //cout<<x<<" "<<x<<" "<<D[x][y]<<endl;
                    q.push(tmp);
                }
            }
        }
        //cout<<endl;
    }
    return D[N-1][M-1];
    
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>N>>M;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                cin>>a[i][j];
            }
        }
        cout<<dijkstra()<<endl;
    }
    
    return 0;
}
