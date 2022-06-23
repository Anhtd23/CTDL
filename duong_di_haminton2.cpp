#include<bits/stdc++.h>
using namespace std;
int V, E;
int a[100][100];
bool ans;
bool check(int arr[]){
    for(int i = 0 ; i < V - 1; i++){
        if(a[arr[i]][arr[i+1]] == 0) return false;
    }
    return true;
}
bool cycle(){
    int arr[V];
    for(int i = 0 ; i < V; i++) arr[i] = i+1;
    do{
        if(check(arr)){
            return true;
        }
    }while (next_permutation(arr, arr+V));
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>V>>E;
        int tmp1, tmp2;
        for(int i = 1 ; i <= V; i++){
            for(int j = 1 ; j <= V ; j++) a[i][j] = 0;
        }
        for(int i = 0 ; i < E; i++){
            cin>>tmp1>>tmp2;
            a[tmp1][tmp2] = 1;
            a[tmp2][tmp1] = 1;
        }
        if(cycle()) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}