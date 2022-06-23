#include<bits/stdc++.h>
using namespace std;
bool OK = true;
void print(int a[], int n){
    int i = 0;
    string b = "(";
    while (i < n && a[i] > 0)
    {
        b += to_string(a[i]);
        b += " ";
        i++;
    }
    b.pop_back();
    cout<<b<<") ";
}
void gene(int a[], int n){
    int sum = 0 ;
    int i = n-1; 
    while (i >= 0 && a[i] <= 1){
        if(a[i] == 1) sum++;
        i--;
    }
    if(i == -1) {
        OK = false;
        return;
    }
    sum++;
    a[i]--;
    int thuong = sum/a[i];
    int div = sum % a[i];
    for(int j = 0; j < thuong ; j++){
        a[i+j+1] = a[i];
    }
    a[i+thuong + 1] = div;
    for(int j = i + thuong + 2; j < n ; j++) a[j] = 0;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n] = {0};
        a[0] = n;
        OK = true;
        if(n == 0 ){
            cout<<"(0)"<<endl;
            continue;
        }
        while (OK)
        {
            print(a, n);
            gene(a, n);
        }
        cout<<endl;
    }
    return 0;
}