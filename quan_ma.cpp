#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> II;
bool chuaxet[9][9];
int direcX[8] = {-1, -2, -2 , -1, 1, 2, 2, 1};
int direcY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int minJump(string a, string b){
    for(int i = 1 ; i <= 8; i++) 
        for(int j = 1 ; j <= 8 ; j++) chuaxet[i][j] = false;
    II nguon(a[0] - 'a' + 1,8 -  (a[1] - '0') + 1);
    II dich(b[0] - 'a' + 1,8 - (b[1] - '0') + 1 );
    queue<II> q;
    q.push(nguon);
    chuaxet[nguon.first][nguon.second] = true;
    int level = 0;
    while(true){
        int s = q.size();
        for(int i = 0 ; i < s; i++){
            II c = q.front();
            q.pop();
            if(c.first == dich.first && c.second == dich.second) return level;
            for(int j = 0 ; j < 8; j++){
                int x = c.first + direcX[j];
                int y = c.second + direcY[j];
                if(x >= 1 && x <= 8 && y >= 1 && y <= 8 && !chuaxet[x][y]){
                    q.push(II(x, y));
                    chuaxet[x][y] = true;
                }
            }
        }
        level++;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--){
        string a, b;cin>>a>>b;
        cout<<minJump(a,b)<<endl;
    }
    return 0;
}