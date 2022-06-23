#include<bits/stdc++.h>
using namespace std;
long long p = 1000000007;
class Matrix{
   public: 
    long long F[20][20];
    int n, k;
    Matrix(int n, int k){
        this->n = n;
        this->k = k;
        for(int i =  0; i < n ; i++)
            for(int j  = 0 ; j < n ; j++) F[i][j] = 0;
    }
    void nhap(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++) cin>>F[i][j];
        }
    }
    void print(){
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = (ans + F[i][n-1-i])%p;
        }
        cout<<ans<<endl;
    }
    Matrix operator*(Matrix b){
        Matrix a(b.n, b.k);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < n; k++){
                    a.F[i][j] = (a.F[i][j] + ( F[i][k] * b.F[k][j] % p)) %p;
                }
            }
        }
        return a;
    }
};
Matrix power(Matrix a, int n){
    if(n == 1 ) return a;
    Matrix c = power(a, n/2);
    if(n % 2 == 0 ) return c * c;
    else return c * c * a;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        Matrix a(n, k);
        a.nhap();
        Matrix b = power(a, a.k);
        b.print();
    }
    
    return 0;
}