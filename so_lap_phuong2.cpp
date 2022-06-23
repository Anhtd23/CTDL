#include<bits/stdc++.h>
using namespace std;
int a[20];
int b[20];
int n;
long long maxA = 0;
long long chuyen(){
    long long sum = 0;
    for(int i = 0 ; i < n ; i++) {
        if(a[i] == 1 ) sum = sum * 10 + (long long)a[i] * b[i];
    }
    return sum;
}
long long checkA(){
    long long n = chuyen();
    long long tmp = round(cbrt(n));
    if((tmp * tmp * tmp) == n) {
        return n;
    }
    else return 0;
}
void Try(int i ){
    for(int j = 1 ; j >= 0 ; j--){
        a[i] = j;
        if(i == n) {
            long long k = checkA();
            if( k > 0 && maxA < k) {
                maxA  = k;
            }
        }
        else Try(i + 1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        maxA = 0;
        string c;
        cin>>c;
        n = c.length();
        for(int i = 0 ; i < n; i++) {
            b[i] = c[i] - '0';
        }
        Try(0);
        if(maxA > 0) cout<<maxA<<endl;
        else cout<<-1<<endl;
    }
    

    return 0;
}