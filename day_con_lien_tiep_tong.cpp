#include<bits/stdc++.h>
using namespace std;
int n, a[100];
int maxSub(){
    int max = a[0];
    int x = a[0], here = a[0];
    for(int i = 1 ; i < n ; i++){
        here += a[i];
        if(a[i] > here){
            here = a[i];
        }
        else{
            if(max < here) max = here ;
        }
    }
    return max;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        cout<<maxSub()<<endl;
    }
    

    return 0;
}