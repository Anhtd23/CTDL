#include<iostream>
using namespace std;
void print(int a[], int n){
    cout<<'[';
    for(int i = 0 ; i < n-1 ; i++) cout<<a[i]<<" ";
    cout<<a[n-1];
    cout<<']';
    cout<<" ";
}
void printSeq(int a[], int n){
    if(n > 1 ){
        int b[n];
        for(int i = 0 ; i < n-1 ; i++) b[i] = a[i] + a[i+1];
        printSeq(b, n - 1);
        print(b , n - 1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        printSeq(a, n);
        print(a, n);
        cout<<endl;
    }
    
    return 0;
}