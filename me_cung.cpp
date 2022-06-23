#include<iostream>
using namespace std;
int a[20][20];
bool check = true;
void way(int a[20][20], int n, int x, int y, string b){
    if(a[x+1][y] == 1 && x < n){
        way(a, n, x+1, y, b + "D");
    }
    if(a[x][y+1] == 1 && y < n){
        way(a, n, x, y+1, b + "R");
    }
    if( x == n -1 && y == n - 1) {
        cout<<b<<" ";
        check = false;
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n ; j++) cin>>a[i][j];
        }
        if( a[0][0] == 0){
            cout<<-1<<endl;
            continue;
        }
        check = true;
        string b = "";
        way(a, n, 0 , 0, b);
        if(check == true) cout<<-1;
        cout<<endl;
    }
    
}