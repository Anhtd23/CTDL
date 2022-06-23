#include<bits/stdc++.h>
using namespace std;
int x[10]={0};
int soSanh(int b[], int n){
    for(int i = 0 ; i < n ; i++){
        if(b[i] > x[i]) return 1;
        if(b[i] < x[i]) return 0;
    }
    return 0;
}
void capNhat(int b[], int n) {
    for(int i = 0 ; i < n ; i++) x[i] = b[i];
}
void numMax(int a[], int b[],int y, int n, int k){
    if(k == 0 || y == n-1){
        if(soSanh(b, n) == 1) capNhat(b, n);
    }
    else if(k > 0 && y < n-1){
        if(a[y] != b[y]){
            for(int i = y+1; i < n ; i++){
                if(a[y] == b[i]){
                    swap(b[y], b[i]);
                    numMax(a, b, y+1, n, k-1);
                    swap(b[y], b[i]);
                }
            }
        }
        else numMax(a, b, y+1, n, k);
        
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int k;
        string s;
        cin>>k>>s;
        memset(x,0, 4*10);
        int n = s.length();
        int a[n];
        for(int i =0 ; i < n ; i++) a[i] = s[i]-'0';
        int b[n];
        for(int i = 0 ; i < n ; i++) b[i] = a[i];
        sort(a, a+n, greater<>());
        numMax(a, b,0, n, k);
        for(int i =0 ; i < n ; i++) cout<<x[i];
        cout<<endl;
    }
    

    return 0;
}