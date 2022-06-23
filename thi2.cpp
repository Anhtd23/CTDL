#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int tmp1 = a[0] * a[1];
    int tmp2 = a[0] * a[1] * a[2];
    int tmp3 = a[0] * a[n-1];
    int tmp4 = a[0] * a[n-1] * a[n-2];
    int tmp5 = a[n-1] * a[n-2];
    int tmp6 = a[n-1] * a[n-2] * a[n-3];
    int tmp7 = a[0] * a[1] * a[n-1];
    int maxA = max(max(tmp1, tmp2), max(max(tmp3, tmp4), max(tmp5, tmp6)));
    maxA = max(tmp7, maxA);
    cout<<maxA;
    return 0;
}