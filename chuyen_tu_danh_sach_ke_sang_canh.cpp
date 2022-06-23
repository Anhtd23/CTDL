#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore(1);
    bool a[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++) a[i][j] = 0;
    }
    string tmp;
    int t;
    for(int i = 0 ; i < n ; i++){
        getline(cin, tmp);
        stringstream ss(tmp);
        while (ss>>t){
            a[i][t-1] = true;
        }
    }
    for(int i = 0 ; i < n - 1; i++){
        for(int j = i ; j < n ; j++){
            if(a[i][j]) cout<<i+1<<" "<<j+1<<endl;
        }
    }
    return 0;
}