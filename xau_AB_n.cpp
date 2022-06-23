#include<iostream>
using namespace std;
int n;
char a[20];
void print(){
    for(int i = 0 ; i < n ; i++) cout<<a[i];
    cout<<" ";
}
void gene(int k){
    for(int i = 0 ; i < 2 ; i++){
        if(i == 0 ) a[k] = 'A';
        else a[k] = 'B';
        if( k == n-1){
            print();
        }
        else gene(k+1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) a[i] = 'A';
        gene(0);
        cout<<endl;
    }
    
    return 0;
}