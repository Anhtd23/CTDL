#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int countA = 0;
string c[1000000];
void Try(int i, string b){
    c[countA++] = b;
    for(int j = i ; j < n ; j++){
        Try(j+1, b + a[j]);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        countA = 0;
        cin>>n;
        cin>>a;
        sort(a.begin(), a.end());
        Try(0, "");
        for(int i = 1; i < countA ; i++) cout<<c[i]<<" ";
        cout<<endl;
    }
    

    return 0;
}