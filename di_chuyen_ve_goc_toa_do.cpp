#include<bits/stdc++.h>
using namespace std;
long long a[100][100];
long long diChuyen(int n, int m){
    if(a[n][m] > 0) return a[n][m];
    long long tmp = diChuyen(n-1, m) + diChuyen(n, m-1);
    a[n][m] = tmp;
    return tmp;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < 101; i++){
        a[i][0] = a[0][i] = 1;
    }
    a[0][0] = 0;
    while (t--)
    {
        int n , m;
        cin>>n>>m;
        cout<<diChuyen(n, m)<<endl;
    }
    
    return 0;
}