#include<iostream>
using namespace std;
int a[1000];
void sort(int n){
    cout<<"Buoc 0: "<<a[0]<<endl;
    for(int i = 1 ; i < n; i++){
        int j = i - 1 , x = a[i];
        while(j >= 0 && a[j] > x){
           a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
        cout<<"Buoc "<<i<<": ";
        for(int k = 0 ; k <= i ; k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>a[i];
    sort(n);
}