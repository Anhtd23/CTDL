#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n, k;
int a[20], b[20];
bool check = true;
int sum(int c[]){
    int sumA = 0;
    for(int i = 0 ; i < n ; i++){
        sumA += a[i] * c[i]; 
    }
    return sumA;
}
void print(int b[]){
    string c ="";
    c += '[';
    for(int i = 0 ; i < n; i++){
        if(b[i] == 1 ) {
            c += to_string(a[i]);
            c += " ";
        }
    }
    c.pop_back();
    c += "]";
    cout<<c<<" ";
}
void sumSeq(int i){
    for(int j = 1 ; j >= 0; j--){
        b[i] = j;
        if( i == n - 1 ) {
            if(sum(b) == k){
                print(b);
                check = false;
            }
        }
        else sumSeq(i+1); 
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for(int i = 0; i < n ; i++) cin>>a[i];
        sort(a, a + n);
        check = true;
        sumSeq(0);
        if(check == true) cout<<"-1"<<endl;
        cout<<endl;
    }
    

    return 0;
}