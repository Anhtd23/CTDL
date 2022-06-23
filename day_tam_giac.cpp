#include<bits/stdc++.h>
using namespace std;
int dayTamGiac(int a[], int n){
    int nhoHon[n];
    int hon[n];
    nhoHon[0] = 1;
    for(int i = 1 ; i < n ; i++){
        nhoHon[i] = 1;
        if(a[i] > a[i-1]) nhoHon[i] = nhoHon[i-1]+1; 
    }
    hon[n-1] = 1;
    for(int i = n-2 ; i >= 0 ; i--){
       hon[i] = 1;
       if(a[i] > a[i+1]) hon[i] = hon[i+1]+1;
    }
    int minA = 0;
    for(int i = 0 ; i < n ; i++){
        minA = max(nhoHon[i] + hon[i] - 1, minA);
    }
    return minA;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        cout<<dayTamGiac(a, n)<<endl;
    }
    

    return 0;
}