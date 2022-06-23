#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[100];
int c[100];
int countA = 0;
void Try(int i,int run, int dem){
    if( dem == k ) {
        countA++;
        return;
    }
    for(int j = run ; j <= n ; j++){
        if(a[j] > c[i-1]){
            c[i] = a[j];
            Try(i+ 1, j + 1, dem+1);
        }
    }
}
int main(){
    cin>>n>>k;
    for(int i = 1 ; i <= n ; i++) cin>>a[i];
    Try(1, 1, 0);
    cout<<countA<<endl;
    return 0;
}