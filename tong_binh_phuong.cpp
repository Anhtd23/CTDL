#include<bits/stdc++.h>
using namespace std;
int a[10002];
int numSquare(int n){
    if(a[n] != 0 || n == 0) return a[n];
    int s = (int)sqrt(n);
    int minA = 10000000;
    for(int i = s;i >= 1 ; i--){
        minA = min(numSquare(n - i * i) + 1, minA);
    }
    a[n] = minA;
    return minA;
}
int main(){
    int t;
    cin>>t;
    a[0] = 0;a[1] = 1;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<numSquare(n)<<endl;
    }
    

    return 0;
}