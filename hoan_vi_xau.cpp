#include<iostream>
using namespace std;
int n, b[20];
string a;
bool check = true;
void print(){
    for(int i = 0 ; i < n ; i++) cout<<a[b[i]-1];
    cout<<" ";
}
void after(){
    int i = n - 1;
    while (b[i] < b[i-1] && i >= 0) i--;
    if( i >= 1){
        i--;
        int j = n - 1;
        while (b[i] > b[j]) j--;
        swap(b[i], b[j]);
        int l = i + 1;
        int r = n - 1;
        while (r > l)
        {
            swap(b[r], b[l]);
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
        cin>>a;
        n = a.length();
        for(int i = 0 ; i < n ;i++) b[i] = i + 1;
        check = true;
        gene();
        cout<<endl;
    }
    
    return 0;
}