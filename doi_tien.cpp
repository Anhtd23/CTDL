#include<iostream>
using namespace std;
int n;
int a[10] = {1, 2 ,5 , 10, 20, 50, 100, 200, 500, 1000};
int total(){
    int i = 9;
    int count = 0;
    while (n != 0)
    {
        if( n >= a[i]) {
            n -= a[i];
            count++;
        }
        else i--;
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<total()<<endl;
    }
    
    return 0;
}