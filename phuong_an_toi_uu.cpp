#include<bits/stdc++.h>
using namespace std;
int c[100005], a[100005];
int t[100005];
long long n, W;
long long F[100005], FOPT = 0;
bool check = true;
int tinhSum(){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += c[i] * t[i]; 
    }
    return sum;
}
int tinhKL(){
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i] * t[i]; 
    }
    return sum;
}
void upDate(int sumA){
    FOPT = sumA;
    for(int i = 0 ; i < n ; i++) F[i] = t[i]; 
}

void gene(){
    int i = n -1;
    while(i >= 0  && t[i] == 1 ){
        t[i] = 0;
        i--;
    }
    if( i < 0) check = false;
    else {
        t[i] = 1;
    }
}
int main(){
    fstream fileIn("data.in", ios::in);
    fileIn>>n>>W; 
    for(int i = 0 ;i < n ; i++) t[i] = 0;
    int i = 0;
    while (i < n)
    {
        fileIn>>c[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        fileIn>>a[i];
        i++;
    }
    fileIn.close();
    while (check)
    {
        gene();
        long long tmp = tinhSum();
        if(tmp > FOPT && tinhKL() <= W) upDate(tmp);
    }
    cout<<FOPT<<endl;
    for(int i = 0 ; i < n ; i++) cout<<F[i]<<" ";

    return 0;
}