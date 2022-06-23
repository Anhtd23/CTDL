#include<bits/stdc++.h>
using namespace std;
int searching(int a[], int n, int k){
    int l = 0, r = n -1;
    while (l < r)
    {
        int mid = (l+r)/2;
        if(a[mid] == k) return mid;
        else if(a[mid] < k){
            if(k == a[r] ) return r;
            if(k < a[r]) l = mid + 1;
            else r = mid - 1;
        }
        else{
            if(k == a[l]) return l; 
            if(k > a[l]) r = mid - 1;
            else l = mid + 1;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        cout<<searching(a, n , k)+1<<endl;
    }
    

    return 0;
}