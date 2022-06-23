#include<bits/stdc++.h>
using namespace std;
char a[51][51][51];
bool chuaxet[51][51][51];
typedef struct Point{
    int x, y, z;
}point;
void khoiTao(point &tmp , int x, int y, int z){
    tmp.x = x;
    tmp.y = y;
    tmp.z = z;
}
void in(point p){
    cout<<p.x<<" "<<p.y<<" "<<p.z<<endl;
}
point nguon, dich;
int demBuoc(int A, int B, int C){
    queue<point> q;
    q.push(nguon);
    for(int i = 0 ; i < A ; i++){
        for(int j = 0 ; j < B ; j++){
            for(int k = 0 ; k < C ; k++) chuaxet[i][j][k] = false;
        }
    }
    int level = 0;
    point p;
    while (!q.empty())
    {
        level++;
        int s = q.size();
        for(int i = 0 ; i < s ; i++){
            point tmp = q.front();
            q.pop();
            if(tmp.x == dich.x && tmp.y == dich.y && tmp.z == dich.z) return level-1;
            if(tmp.x - 1 >= 0 && (a[tmp.x-1][tmp.y][tmp.z] == '.' || a[tmp.x-1][tmp.y][tmp.z] == 'E') && !chuaxet[tmp.x-1][tmp.y][tmp.z]){
                chuaxet[tmp.x-1][tmp.y][tmp.z] = true;
                khoiTao(p, tmp.x-1, tmp.y, tmp.z);
                q.push(p);
            }
            if(tmp.y - 1 >= 0 && (a[tmp.x][tmp.y-1][tmp.z] == '.' || a[tmp.x][tmp.y-1][tmp.z] == 'E') && !chuaxet[tmp.x][tmp.y-1][tmp.z]){
                chuaxet[tmp.x][tmp.y-1][tmp.z] = true;
                khoiTao(p, tmp.x, tmp.y-1, tmp.z);
                q.push(p);
            }
            if(tmp.z - 1 >= 0 && (a[tmp.x][tmp.y][tmp.z-1] == '.' || a[tmp.x][tmp.y][tmp.z-1] == 'E') && !chuaxet[tmp.x][tmp.y][tmp.z-1]){
                chuaxet[tmp.x][tmp.y][tmp.z-1] = true;
                khoiTao(p, tmp.x, tmp.y, tmp.z-1);
                q.push(p);
            }
            if(tmp.x + 1  < A && (a[tmp.x+1][tmp.y][tmp.z] == '.' || a[tmp.x+1][tmp.y][tmp.z] == 'E') && !chuaxet[tmp.x+1][tmp.y][tmp.z]){
                chuaxet[tmp.x+1][tmp.y][tmp.z] = true;
                khoiTao(p, tmp.x+1, tmp.y, tmp.z);
                q.push(p);
            }if(tmp.y + 1 < B && (a[tmp.x][tmp.y+1][tmp.z] == '.' || a[tmp.x][tmp.y+1][tmp.z] == 'E') && !chuaxet[tmp.x][tmp.y+1][tmp.z]){
                chuaxet[tmp.x][tmp.y+1][tmp.z] = true;
                khoiTao(p, tmp.x, tmp.y+1, tmp.z);
                q.push(p);
            }if(tmp.z + 1 < C && (a[tmp.x][tmp.y][tmp.z+1] == '.' || a[tmp.x][tmp.y][tmp.z+1] == 'E') && !chuaxet[tmp.x][tmp.y][tmp.z+1]){
                chuaxet[tmp.x][tmp.y][tmp.z+1] = true;
                khoiTao(p, tmp.x, tmp.y, tmp.z+1);
                q.push(p);
            }
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int A, B, C;
        cin>>A>>B>>C;
        for(int i = 0 ; i < A; i++){
            for(int j = 0 ; j < B; j++){
                for(int k = 0 ; k < C; k++) {
                    cin>>a[i][j][k];
                    if(a[i][j][k] == 'S'){
                       khoiTao(nguon, i, j, k);
                    }
                    else if(a[i][j][k] == 'E'){
                        khoiTao(dich, i, j, k);
                    }
                }
            }
        }
        cout<<demBuoc(A, B, C)<<endl;
    }
    

    return 0;
}