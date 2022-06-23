#include<bits/stdc++.h>
using namespace std;
char store[26];
int a[100];
bool check;
int n, k;
void in(){
    for(int i = 0 ; i < k ; i++){
        cout<<store[a[i]];
    }
    cout<<endl;
}
void gene(){
    int i = k - 1;
    while (a[i] == n + i - k && i >= 0 ) i--;
    if(i >= 0 ){
        a[i]++;
        for(int j = i + 1; j < k ; j++) a[j] = a[j-1]+1;
    }
    else check = false;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0 ; i < 26; i++){
        store[i] = i + 'A';
    }
    while (t--)
    {
        cin>>n>>k;
        for(int i = 0 ; i <  k; i++) a[i] = i;
        check = true;
        while(check){
            in();
            gene();
        }
    }



    return 0;
}