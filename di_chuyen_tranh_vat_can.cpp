#include<bits/stdc++.h>
using namespace std;
char a[101][101];
typedef pair<int, int> douInt;
douInt nguon, dich;
int diChuyen(int n){
    queue<douInt> q;
    q.push(nguon);
    int level = 0;
    bool chuaxet[n][n] = {0};
    while (true)
    {
        int s = q.size();
        for(int i = 0 ; i < s; i++){
            douInt tmp = q.front();
            q.pop();
            if(tmp == dich) return level;
            int i1 = tmp.first-1;
            int i2 = tmp.second-1;
            int i3 = tmp.first+1;
            int i4 = tmp.second+1;
            while (i1 >= 0 && a[i1][tmp.second] != 'X' && !chuaxet[i1][tmp.second] ){
                chuaxet[i1][tmp.second] = true;
                q.push(douInt(i1 , tmp.second));
                i1--;
            }
            while (i2 >= 0 && a[tmp.first][i2] != 'X' && !chuaxet[tmp.first][i2] ){
                chuaxet[tmp.first][i2] = true;
                q.push(douInt(tmp.first , i2));
                i2--;
            }
            while (i3 < n && a[i3][tmp.second] != 'X' && !chuaxet[i3][tmp.second] ){
                chuaxet[i3][tmp.second] = true;
                q.push(douInt(i3 , tmp.second));
                i3++;
            }
            while (i4 < n && a[tmp.first][i4] != 'X' && !chuaxet[tmp.first][i4] ){
                chuaxet[tmp.first][i4] = true;
                q.push(douInt( tmp.first, i4));
                i4++;
            }
        }
        level++;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin>>a[i][j];
            }
        }
        cin>>nguon.first;cin>>nguon.second;
        cin>>dich.first;cin>>dich.second;
        cout<<diChuyen(n)<<endl;
    }

    return 0;
}