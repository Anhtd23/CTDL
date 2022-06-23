#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t; 
    while (t--)
    {    
        long long n, k;
        cin>>n>>k;
        long long a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        int i = 0;
        int check = 1;
        while (i <= n && a[i] <= k) {
            i++;
        }
        if(i) cout<<i<<endl;
        else cout<<-1<<endl;
        
    }

    return 0;
}