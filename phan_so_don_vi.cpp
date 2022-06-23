#include<bits/stdc++.h>
using namespace std;
typedef struct {
    long long x;
    long long y;
}phanSo;
void rutGon(phanSo &x){
    long long m = __gcd(x.x, x.y);
    x.x /= m;
    x.y /= m;
}
phanSo truPhanSo(phanSo x, phanSo y){
    phanSo c;
    c.x = x.x * y.y - y.x * x.y;
    c.y = x.y * y.y;
    rutGon(c);
    return c;
}
long long soSanh(phanSo x, phanSo y){
    return (x.x * y.y - y.x * x.y);
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        phanSo x;
        cin>>x.x>>x.y;
        rutGon(x);
        phanSo soTru;
        soTru.x = 1;
        soTru.y = 2;
        while (x.x != 1)
        {
            if(soSanh(x, soTru) > 0){
                x = truPhanSo(x, soTru);
                cout<<soTru.x<<"/"<<soTru.y<<" + ";
            }
            soTru.y++;
        }
        cout<<x.x<<"/"<<x.y;
        cout<<endl;
    }
    
    return 0;
}