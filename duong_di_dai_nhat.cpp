#include<bits/stdc++.h>
using namespace std;
int m, n;
int a[20][20];
int maxRoad = 0;
void duongDiDaiNhat(int k, int countA){
    if(countA > maxRoad) maxRoad = countA;
    for(int i = 0 ; i < n ; i++){
        if(a[k][i] == 1){
            a[k][i] = 0;
            a[i][k] = 0;
            duongDiDaiNhat(i, countA+1);
            a[i][k] = a[k][i] = 1;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++){
                a[i][j] = 0;
            }
        }
        for(int i = 0 ; i < m ; i++){
            int tmp1, tmp2;
            cin>>tmp1>>tmp2;
            a[tmp1][tmp2] = 1;
            a[tmp2][tmp1] = 1;
        }
        maxRoad = 0;
        for(int i = 0 ; i < n ; i++){
            duongDiDaiNhat(i, 0);
        }
        cout<<maxRoad<<endl;
    }
    
    return 0;
}