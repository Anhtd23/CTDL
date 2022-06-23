#include<iostream>
using namespace std;
int a[1000];
void interChange(int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1; j < n ; j++){
            if(a[i] > a[j]) swap(a[i], a[j]);
        }
        cout<<"Buoc "<<i+1<<": ";
        for(int j = 0 ; j < n ; j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    for(int  i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    interChange(n);
}