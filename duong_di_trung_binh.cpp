#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int V, E;
void avarage(){
    for(int k = 1 ; k <= V; k++){
        for(int i = 1 ; i <= V; i++){
            for(int j = 1 ; j <= V ; j++){
                if(a[i][j] > a[i][k] + a[k][j] && a[i][k] != 1e9 && a[k][j] != 1e9) a[i][j] = a[i][k] + a[k][j]; 
            }
        }
    }
    int countA = 0;
    int sum = 0;
    for(int i = 1 ; i <= V; i++){
        for(int j = 1 ; j <= V ; j++){
            if(a[i][j] != 1e9 && i != j){
                countA++;
                sum += a[i][j];
            }
        }
    }
    cout << fixed << setprecision(2);
    cout << (double)sum /countA << endl;
}
int  main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        int tmp1, tmp2;
        for(int i = 1 ; i <= V; i++){
            for(int j = 1 ; j <= V; j++){
                if(i == j) a[i][j] = 0;
                else a[i][j] = 1e9;
            }
        }
        for(int i = 0 ; i < E ; i++){
            cin>>tmp1>>tmp2;
            a[tmp1][tmp2] = 1;
        }
        avarage();
    }
    return 0;
}