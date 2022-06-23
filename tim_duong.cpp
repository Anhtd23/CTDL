#include<bits/stdc++.h>
using namespace std;
char a[500][500];
typedef pair<int,int> douInt;
int n, m;
douInt nguon, dich;
int directX[4] = {0, -1, 0, 1};
int directY[4] = {1, 0, -1, 0};
bool chuaxet[500][500];
bool kt = false;
void check(douInt u, int i, int countA){
    if(kt == true || countA > 2) return;
    if(u.first == dich.first && u.second == dich.second) {
        kt = true;
        return;
    }
    chuaxet[u.first][u.second] = true;
    for(int j = 0 ; j < 4 ; j++){
        int x = u.first + directX[j];
        int y = u.second + directY[j];  
        if(x >= 1 && x <= n && y >= 1 && y <= m && !chuaxet[x][y] && a[x][y] == '.'){
            if(i == -1 || i == j){
                check(douInt(x, y), j, countA);
            }
            else {
                check(douInt(x, y),j, countA+1);
            }
        }
    }
    chuaxet[u.first][u.second] = false;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0 ; i < 500; i++){
        for(int j = 0 ; j < 500; j++) chuaxet[i][j] = false;
    }
    while (t--){
        cin>>n>>m;
        kt = false;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                cin>>a[i][j];
                if(a[i][j] == 'S'){
                    nguon.first = i;
                    nguon.second = j;
                }
                else if(a[i][j] == 'T'){
                    dich.first = i;
                    dich.second = j;
                    a[i][j] = '.';
                }
            }
        }
        check(nguon, -1, 0);
        if(kt) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    

    return 0;
}