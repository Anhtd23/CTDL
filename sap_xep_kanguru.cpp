#include<bits/stdc++.h>
using namespace std;
int check[100000];
int countA = 0;
int minKanguru(int a[], int n){
    int ans = n;
    int i = 0, j = n/2;
    while (i <= n /2 - 1 && j < n )
    {
        if(a[i] >= 2 * a[j]){
            j++;
            i++;
            ans--;
        }
        else j++;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ;i < n ; i++) cin>>a[i];
        sort(a, a+n, greater<int>());
        cout<<minKanguru(a, n)<<endl;
    }
    

    return 0;
}