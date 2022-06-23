#include<iostream>
using namespace std;
int n;
void after(int a[]){
    int i = n - 1;
    while (a[i] < a[i-1] && i >= 0) i--;
    if( i >= 1){
        i--;
        int j = n - 1;
        while (a[i] > a[j]) j--;
        swap(a[i], a[j]);
        int l = i + 1;
        int r = n - 1;
        while (r > l)
        {
            swap(a[r], a[l]);
            r--;
            l++;
        }
        for(int k = 0 ; k < n ; k++) cout<<a[k]<<" ";
    }
    else{
        for(int i = 0 ; i < n ; i++)
            cout<<i+1<<" ";
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        after(a);  
        cout<<endl;
    }
    
    return 0;
}