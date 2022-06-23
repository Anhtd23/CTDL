#include<iostream>
using namespace std;
int a[105][105];
int n;
bool unused[105];
int X[105];
int fopt = 10000000;
void init(){
    cin>>n;
    for(int  i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        unused[i] = false;
    }
    X[1] = 1;
}
void print(){
    cout<<fopt<<endl;
}
void Back_Track(int i, int sum){
    if(sum > fopt) return;
    
    for(int j = 2 ; j <= n ; j++){
        if(!unused[j]){
            X[i] = j;
            unused[j] = true;
            if( i == n){
                sum += a[X[i-1]][X[i]];
                sum += a[X[i]][1];
                if(sum < fopt) fopt = sum;
            } 
            else Back_Track(i+1, sum + a[X[i-1]][X[i]]);
            unused[j] = false;
        }
    }   
}
int main(){
    init();
    if(n == 1) {
        cout<<0<<endl;
        return 0;
    }
    Back_Track(2, 0);
    print();
    return 0;
}