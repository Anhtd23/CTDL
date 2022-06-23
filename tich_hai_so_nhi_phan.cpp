#include<bits/stdc++.h>
using namespace std;
long long chuyenDoi(string a){
    long long sum = 0;
    int n = a.length();
    for(int i = 0; i < n ;i++){
        sum += (a[n - 1 - i] - '0') * (long long)pow(2, i);
    }
    return sum;
}
long long tichNhiPhan(string a, string b){
    return chuyenDoi(a) * chuyenDoi(b);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        cout<<tichNhiPhan(a, b)<<endl;
    }
    
    return 0;
}