#include<bits/stdc++.h>
using namespace std;
string a;
long long store[1000];
long long n;
long long len;
char Try(long long viTri, int j ){
    //cout<<"vi tri : "<<viTri<<endl;
    if( viTri <= len ) return a[viTri-1];
    while (store[j] >=  viTri) j--;
    //cout<<"j "<<store[j]<<endl;
    if(viTri == store[j] + 1 ) return Try(store[j], j);
    else return Try(viTri- store[j]-1, j);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a>>n;
        long long i = len =  a.length();
        if(len == 1 ){
            cout<<a<<endl;
            continue;
        }
        int j = 0;
        while (i < n)
        {
            store[j++] = i;
            i*=2;
        }
        cout<<Try(n, j-1)<<endl;
    }
    

    return 0;
}