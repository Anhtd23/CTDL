#include<bits/stdc++.h>
using namespace std;
void addArr(int a[], int n1, int b[], int n2, int c[], int n3){
            int dis = n2 - n3;
            for(int i = n3 - 1; i >= 0; i--){
                a[dis+i] = b[dis+i] + c[i];
            }
            for(int i = dis-1; i >= 0 ; i--){
                a[i] = b[i];
            }
        }
        void lessArr(int a[], int n1, int b[], int n2, int c[], int n3){
            int dis = n2 - n3;
            for(int i = n3 - 1 ; i >= 0; i--){
                a[dis+i] = b[dis+i] - c[i];
            }
            for(int i = dis-1; i >= 0 ; i--){
                a[i] = b[i];
            }
        }
class Poly{
    public:
        int a[100];
        int n;
        Poly(int n){
            this->n = n;
            for(int i = 0 ; i < n ; i++) a[i] = 0;
        }
        void nhap(){
            for(int i = 0 ; i < n ; i++ ) cin>>a[i];
        }
        void print(){
            int i = 0;
            while (a[i] == 0)
            {
                i++;
            }
            for(; i < n ; i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        Poly makeSame(Poly b, int k){
            Poly a(b.n);
            for(int i = 0 ; i < b.n; i++) a.a[i] = b.a[i]* k;
            return a;
        }
        Poly incre(int k){
            Poly a(n+k);
            for(int i = 0 ; i < n ;i++) a.a[i] = this->a[i];
            return a;
        }
        Poly operator+(Poly b){
            int m = max(n, b.n);
            int len1 = n, len2 = b.n;
            Poly a(m);
            if( len1 > len2) addArr(a.a, m, this->a, len1, b.a, len2);
            else addArr(a.a, m, b.a, len2, this->a, len1);
            return a;
        }
        Poly operator-(Poly b){
            int m = max(n, b.n);
            int len1 = n, len2 = b.n;
            Poly a(m);
            if( len1 > len2) lessArr(a.a, m, this->a, len1, b.a, len2);
            else lessArr(a.a, m, b.a, len2, this->a, len1);
            return a;
        }
        pair<Poly, Poly> tach(Poly a, int len, int max){
            Poly tmp2(len);
            int len2 = max -len;
            Poly tmp1(len2);
            int i = a.n-1, j = len-1;
            while (i >= 0 && j >= 0)
            {
                tmp2.a[j] = a.a[i];
                j--;i--;
            }
            j = len2-1;
            while(i>=0 && j >= 0)
            {
                tmp1.a[j] = a.a[i];
                j--;i--;
            }            
            pair<Poly, Poly> c(tmp1, tmp2);
            return c;
        }
        Poly operator*(Poly b){
            if(n == 1) {
                return makeSame(b, a[0]);
            }
            if(b.n == 1) {
                return makeSame(*this, b.a[0]);
            }
            int len = max(n,b.n);
            int m = len/2;
            pair<Poly, Poly> c1 = tach(*this, m, len);
            pair<Poly, Poly> c2 = tach(b, m, len);
            Poly tmp1 = c1.first * c2.first;
            Poly tmp2 = c1.first * c2.second;
            Poly tmp3 = c1.second * c2.first;
            Poly tmp4 = c1.second * c2.second;
            return tmp1.incre(m*2) + (tmp2 + tmp3).incre(m) + tmp4;
        }
};
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        Poly a(n), b(m);
        a.nhap();
        b.nhap();
        (a*b).print();

    }
    

    return 0;
}