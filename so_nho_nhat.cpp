#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n , k;cin>>n>>k;
        int a[k]={0};
        a[0] = 1;
        int i = 0;
        n--;
        for( i = k -1; i >= 1; i--){
            if( n >= 9){
                a[i] += 9;
                n -= 9;
            }
            else{
                a[i] += n;
                n = 0;
            }
        }
        if( n <= 8) {
            a[i] += n;
            for(int i = 0 ; i < k ; i++) cout<<a[i];
            cout<<endl;
        }
        else {
            cout<<"-1"<<endl;
            continue;
        }
    }
    
}