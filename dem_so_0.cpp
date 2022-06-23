#include<bits/stdc++.h>
using namespace std;
int n;
int count0(int a[], int l , int r){
    if(a[0] == 1) return 0;
    if(a[n-1] == 0) return n;
    if( l == r ) return l;
    int mid = (l + r) /2;
    if( a[mid] == 1 && a[mid-1] == 0) return mid;
    else if(a[mid] == 0) return count0(a, mid + 1, r);
    else return count0(a, l , mid-1);
}
int main(){ 
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ;i++) cin>>a[i];
        cout<<count0(a, 0, n-1)<<endl;
    }
    

    return 0;
}