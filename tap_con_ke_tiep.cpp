#include<iostream>
using namespace std;
int n, k;
void after(int a[]){
    int i = k - 1;
    while (a[i] == n + i - k + 1 && i >= 0 ) i--;
    if(i >=0 ){
        a[i]++;
        for(int j = i + 1; j < k ; j++) a[j] = a[j-1]+1;
    }
    else {
        for(int j = 0 ; j < k ; j++){
            a[j] = j + 1;
        }
    }
    for(int i = 0 ; i < k ; i++) cout<<a[i]<<" ";
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        int a[k];
        for(int i = 0 ; i < k ; i++) cin>>a[i];
        after(a);
        cout<<endl;
    }
    
    return 0;
}