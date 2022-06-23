#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
bool visited[20][20];
bool check = 0;
string c[10000];
int countA = 0;
void Try(int x, int y, string b){
    if(!visited[x][y]){
        visited[x][y] = 1;
        if(x == n && y == n ) {
            c[countA++] = b;
        }
        if(a[x+1][y] == 1 && x + 1 <= n) Try(x+1, y, b+"D");
        if(a[x][y-1] == 1 && y - 1 >= 1) Try(x, y -1, b + "L");
        if(a[x][y+1] == 1 && y + 1 <= n) Try(x, y+1, b + "R");
        if(a[x-1][y] == 1 && x -1 >= 1) Try(x - 1, y, b + "U");
        visited[x][y]=0;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        countA = 0;
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++) cin>>a[i][j];
        }
        Try(1, 1, "");
        if(countA == 0) cout<<-1;
        else{
            cout<<countA<<" ";
            for(int i = 0 ; i < countA; i++){
                cout<<c[i]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}