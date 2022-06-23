#include<iostream>
using namespace std;
int n;
int a[20];
bool check = true;
void print(){
    for(int i = 0 ; i < n ; i++) cout<<a[i];
    cout<<" ";
}
void after(){
    int i = n - 1;
    while (a[i] > a[i-1] && i >= 0) i--;
    if( i >= 1){
        i--;
        int j = n - 1;
        while (a[i] < a[j]) j--;
        swap(a[i], a[j]);
        int l = i + 1;
        int r = n - 1;
        while (r > l)
        {
            swap(a[r], a[l]);
            r--;
            l++;
        }
    }
    else check = false;
}
void gene(){
    while (check)
    {
        print();
        after();
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ;i++) a[i] = n - i;
        check = true;
        gene();
        cout<<endl;
    }
    
    return 0;
}