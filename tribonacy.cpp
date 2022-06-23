#include<bits/stdc++.h>
using namespace std;
unsigned long long p = 1e15+7;
unsigned long long md = (p + 1) / 2;
class Matrix{
    public:
    unsigned long long a[3][3];
    Matrix(){
        a[0][0] = a[0][1] = a[0][2] = 1;
        a[1][0] = 1; a[1][1] = a[1][2] = 0;
        a[2][0] = a[2][2] = 0; a[2][1] = 1;
    }
    unsigned long long chiaDu( unsigned long long a, unsigned long long b){
        if(a == 0 || b == 0) return 0;
        if( a == 1 ) return b;
        if( a % 2 == 0 ) return (2 * chiaDu(a/2, b)) %p;    
        return ((2 * chiaDu(a/2, b))%p + b) %p; 
    }
    Matrix operator*(Matrix b){
        Matrix c;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3; j++){
                c.a[i][j] = 0;
                for(int k = 0 ; k < 3; k++)
                c.a[i][j] = (c.a[i][j] + chiaDu(a[i][k], b.a[k][j]))%p;
            }
        }
        return c;
    }
};
Matrix power(Matrix a, unsigned long long n){
    if(n == 1 ) return a;
    Matrix c = power(a, n/2);
    if(n % 2 == 0 ) return c * c;
    else return c * c * a;
}
unsigned long long tribonacy(unsigned long long n){
    if(n <= 3 ) return n;
    n-= 3;
    Matrix a;
    Matrix b = power(a, n);
    return ((b.a[0][0] * 3%p + b.a[0][1] * 2 %p)%p+ b.a[0][2]) % p; 
}
unsigned long long tong(unsigned long long n){
    if(n == 1 ) return 1;
    if(n == 2) return 3;
    if(n == 3 ) return 6;
    long long k = (tribonacy(n+2) + tribonacy(n) -2 ) % p;
    if(k % 2 == 0 ) return k/2;
    return (p + k ) /2;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        unsigned long long n;
        cin>>n;
        cout<<tong(n)<<endl;
    }
    return 0;
}