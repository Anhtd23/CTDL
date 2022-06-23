#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){ 
    int V;
    cin>>V;
    cin.ignore(1);
    string s;
    int tmp;
    for(int i=1; i <= V; i++){
        for(int j= 1; j <= V; j++) a[i][j] =0;
    }
    for(int i = 1; i <= V; i++){
        getline(cin, s);
        stringstream ss(s);
        while (ss>>tmp)
        {
            a[i][tmp] = 1;
        }
    }
    for(int i = 1 ; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}