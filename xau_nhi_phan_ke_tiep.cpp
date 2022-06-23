#include<iostream>
#include<string>
using namespace std;
string after(string a){
    int n = a.length();
    int i = n - 1;
    while (a[i] == '1' && i >= 0)
    {
        a[i] = '0';
        i--;
    }
    if(i >= 0 ){
        a[i] = '1';
    }
    return a;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a;
        cin>>a;
        cout<<after(a)<<endl;
    }
    

    return 0;
}