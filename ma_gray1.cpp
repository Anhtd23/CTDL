#include<bits/stdc++.h>
using namespace std;
int n;
long long cal(string a){
    int n = a.length();
    long long m = 0;
    for(int i = 0 ; i < n ; i++) m += (((long long)pow(2, n - i - 1)) * (a[i] - '0'));
    return m;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string b;
        cin>>b;
        n = b.length();
        int len = n;
        string a[10000];
        a[0] = "0";
        a[1] = "1";
        int count = 2;
        n--;
        while (n--)
        {
            for(int i = 0 ; i < count ; i++){
                string tmp = a[i];
                a[i] = ("0" + tmp);
                a[2*count - i -1] = ("1" + tmp);
            }
            count *= 2;
        }   
        int i = 0;
        while (i < count && a[i].compare(b) != 0)
        {
            i++;
        }
        int c[len];
        int j = 0;
        while(j < len){
            c[j] = i%2;
            i/=2;
            j++;
        }
        for(int k = len - 1; k >= 0; k--) cout<<c[k];
        cout<<endl;
    }
    
    return 0;
}