#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int tmp = 0;
        int so4 = 0, so7 = 0;
        if(n % 4 == 0) so4 = n / 4;
        int count = 0 ;
        while(tmp <= n){
            tmp += 7;
            count++;
            if( (n - tmp) % 4 == 0 && n - tmp >= 0) {
                so4 = (n - tmp) / 4;
                so7 = count;
            }
        }
        if(so4 == 0 && so7  == 0) {
            cout<<-1<<endl;
        }
        else{
            for(int i = 0 ; i < so4; i++) cout<<'4';
            for(int i = 0 ; i < so7; i++) cout<<'7';
            cout<<endl;
        }
    }
    

    return 0;
}