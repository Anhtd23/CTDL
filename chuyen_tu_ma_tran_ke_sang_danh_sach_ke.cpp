#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];

int main(){
    int V;
    cin>>V;
    for(int i = 0 ; i < V; i++){
        for(int j = 0 ; j < V ; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0 ; i < V; i++){
        for(int j = 0 ; j < V; j++){
            if(a[i][j] == 1 ) cout<<j+1<<" ";
        }
        cout<<endl;
    }

    return 0;
}