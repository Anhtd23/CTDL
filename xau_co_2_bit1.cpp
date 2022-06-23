#include<iostream>
using namespace std;
int n, k;
int a[20] = {0};
void print(){
    for(int i = 0 ; i < n ; i++) cout<<a[i];
    cout<<endl;
}
bool check(){
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == 1) count++;
    }
    return count == k;
}
void gene(int i){
    for(int j = 0 ; j < 2 ; j++){
        a[i] = j; 
        if( i == n-1 ){
            if(check()) 
            print();
        }
        else gene(i+1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for(int i = 0 ; i < n ; i++) a[i] = 0;
        gene(0);
    }
    
    return 0;
}