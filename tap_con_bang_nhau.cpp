#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n, a[150];
int sum = 0;
bool check = true;
bool checkSum(int sumA){
    bool part[sumA+1][n+1]={0};
    for(int i = 0 ; i <= n ; i++){
        part[0][i] = true;
    }
    for(int i = 1 ; i <= sumA; i++) part[i][0] = false;
    for(int i = 1 ; i <= sumA; i++){
        for(int j = 1 ; j <= n ; j++){
            part[i][j] = part[i][j-1];
            if(i >= a[j]){
                part[i][j] = part[i][j] || part[i-a[j]][j-1];
            }
        }
    }
   /* for(int i = 0 ; i <= sumA; i++){
        for(int j = 0 ; j <= n ; j++){
            cout<<part[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    return part[sumA][n];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        sum = 0;
        for(int i = 1 ; i <= n ; i++) {
            cin>>a[i];
            sum += a[i];
        }
        check = true;
        if(sum % 2 != 0)
            cout<<"NO"<<endl;
        else {
            sum /= 2;
            if(checkSum(sum)) 
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    
}