#include<iostream>
using namespace std;
int a[1000];
void sort(int n){
    int count = 1;
    for(int i = 0 ; i < n - 1; i++){
        bool check = true;
        for(int j = 0 ; j < n- 1 - i; j++){
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                check = false;
            }
        }
        if(check == false){
            cout<<"Buoc "<<count++<<": ";
            for(int j = 0 ; j < n ; j++){
                cout<<a[j]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i <n ; i++) cin>>a[i];
    sort(n);
}