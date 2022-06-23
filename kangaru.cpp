#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000];
int b[100000];
int find(int l, int r, int k){
    int mid;
    while (l <= r)
    {
        mid = (l + r)/2;
        if(a[mid] >= k && a[mid-1] < k) {
            while ( b[mid] == 1) mid++;
            return mid;
        }
        if(a[mid] >= k) r = mid - 1;
        else l = mid + 1;   
    }
    return -1;
}
int findBin(int k, int l, int r){
    int fin = find(l, r, k);
    if(fin == -1) return -1;
    else return findBin(a[fin],fin+1, r);
}
int kanguru(int l, int r){
    for(int i = 0 ; i < n ; i++) b[i] = 0;
    int count = 0;
    int mid = find(l, r, a[r]/2);
    if(mid == -1 ) return r-l;
    int run = mid;
    for(int i = 0 ; i < mid ; i++){
        if(b[i] == 0){

        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a + n);
        cout<<kanguru()<<endl;
    }
    return 0;
}