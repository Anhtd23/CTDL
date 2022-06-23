#include<bits/stdc++.h>
using namespace std;
int n;
long long maxN = 0;
void merge(long long *a, int l,int mid, int r){
    long long b[r - l+1];
    int i = l, j = mid+1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if(a[i] <= a[j]){
            b[k++] = a[i++];
            maxN += (long long)(j - mid-1);
        }   
        else{
            b[k++] = a[j++];
        }
    }
    if(i == mid + 1){
        while (j <= r)
        {
            b[k++] = a[j++];
        }
    }
    else {
        while (i <= mid)
        {
            b[k++] = a[i++];
            maxN += (long long)(j - mid - 1);
        }
    }
    int x = l;
    for(int t = 0 ; t < k ; t++){
        a[x++] = b[t];
    }
}
void mergeSort(long long *a, int l, int r){
    if(l == r) return;
    if(l < r){
        int mid = (l + r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l,mid, r);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        maxN = 0;
        cin>>n;
        long long *a = new long long [n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        mergeSort(a, 0, n-1);
        //for(int i = 0 ; i < n ; i++) cout<<a[i]<<" ";
        //cout<<endl;
        cout<<maxN<<endl;
    }
    

    return 0;
}