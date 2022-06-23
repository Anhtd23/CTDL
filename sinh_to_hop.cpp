#include<iostream>
using namespace std;
int n, k;
int a[20]={0};
bool check = true;
void print(){
    for(int i = 0 ; i < k ; i++) cout<<a[i];
    cout<<" ";
}
void after(){
    int i = k - 1;
    while (a[i] == n + i - k + 1 && i >= 0 ) i--;
    if(i >=0 ){
        a[i]++;
        for(int j = i + 1; j < k ; j++) a[j] = a[j-1]+1;
    }
    else check = false;
}
void gene(){
    while (check)
    {   print();
        after();
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for(int i = 0 ; i < k ; i++) a[i] = i+1;
        check = true;
        gene();
        cout<<endl;
    }
    
    return 0;
}