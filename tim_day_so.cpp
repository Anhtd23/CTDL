#include<bits/stdc++.h>
using namespace std;
int soMin(int m, int n){
    int thuong = m / n;
    while (true)
    {
        if(thuong == 1 ) break;
        if(m / (thuong - 1 ) == n) thuong--;
        else break;
    }
    if(m / thuong != n) return 0;
    else return thuong;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    int minA = *min_element(a, a+n);
    int ans = 10000000;
    for(int i = 1 ; i <= minA ; i++){
        int sum = 0;
        for(int j = 0 ; j < n ; j++){
            int tmp = soMin(a[j], i);
            if(tmp > 0 )
                sum += tmp;
            else {
                sum += 10000000;
                break;
            }
        }
        ans = min(sum, ans);
    }
    cout<<ans<<endl;
    return 0;
}