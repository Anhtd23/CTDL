#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[100];
int D[100];
int countA = 0;
bool check = true;
void print(){
    for(int i = 0 ; i < n ; i++) {
        if(D[i] == 1)    cout<<a[i]<<" ";
    }
    cout<<endl;
    countA++;
}
bool checkSum(){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i] * D[i];
    }
    return sum == k;
}
void gene(){
    int i = n - 1;
    while (D[i] == 1 && i >= 0) {
        D[i] = 0;
        i--;
    }
    if( i >= 0) D[i]++;
    else   check = false;
}
int main(){
        cin>>n>>k;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        if(checkSum()) print();
        while (check)
        {
            gene();
            if(checkSum()) print();
        }
        cout<<countA;
    return 0;
}