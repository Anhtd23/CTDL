#include<bits/stdc++.h>
using namespace std;
long long p = 1000000007;
class Matrix{
   public: 
    long long F[2][2]; 
    Matrix(){
        F[0][0] = 0;F[0][1] = 1;
        F[1][0] = 1;F[1][1] = 1; 
    }
    Matrix operator*(Matrix b){
        Matrix a;
        a.F[0][0] = ((F[0][0] * b.F[0][0])%p + (F[0][1] * b.F[1][0])%p)%p;
        a.F[0][1] = (F[0][0] * b.F[0][1]%p + F[0][1] * b.F[1][1]%p)%p;
        a.F[1][0] = (F[1][0] * b.F[0][0]%p + F[1][1] * b.F[1][0]%p)%p;
        a.F[1][1] = (F[1][0] * b.F[0][1]%p + F[1][1] * b.F[1][1]%p)%p;
        return a;
    }
};
Matrix power(Matrix a, int n){
    if(n == 1 ) return a;
    Matrix c = power(a, n/2);
    if(n % 2 == 0 ) return c * c;
    else return c * c * a;
}
long long fibonacy(int n){
    Matrix a;
    a = power(a, n);
    return a.F[1][0];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<fibonacy(n)<<endl;
    }
    

    return 0;
}