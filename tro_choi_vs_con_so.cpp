#include<bits/stdc++.h>
using namespace std;
bool check(int b[], int n){
    for(int i = 1 ; i < n - 1 ; i++){
        if(b[i] == b[i-1] - 1 || b[i] == b[i-1] +1 || b[i] == b[i+1] -1 || b[i] == b[i+1] + 1 ) return false;
    }
    return true;
}
void in(int b[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<b[i];
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int b[n];
        for(int i = 0 ; i < n ; i++) b[i] = i+1;
        do
        {
            if(check(b, n)) in(b, n);            
        }while (next_permutation(b,b+n));
        
    }
    

    return 0;
}