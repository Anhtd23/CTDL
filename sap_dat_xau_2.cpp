#include<bits/stdc++.h>
using namespace std;
int b[150] = {0};
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        string a;
        cin>>a;
        memset(b, 0, 4 * 150);
        int n = a.length();
        for(int i = 0 ; i < n ; i++) b[a[i]]++;
        int max = 0;
        for(int i = 'A' ; i <= 'Z' ; i++){
            if(max < b[i]) max = b[i];
        }
        int check;
        if(n % D == 0 ) check = n/D;
        else check = n /D+1;  
        if(max > check){
            cout<<-1;
        }
        else cout<<1;
        cout<<endl;
    }
    return 0;
}