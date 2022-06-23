#include<bits/stdc++.h>
using namespace std;
int k;
string a, b;
string maxA;
int n;
bool soSanh(string a, string b){
    int n1 = a.length();
    for(int i = 0 ; i <n1 ; i++){
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    } 
    return false;
}
void Try(int i, int countA){
    if(i >= n || countA == 0){
        if(soSanh(a, maxA)) maxA = a;
    }
    else{
        if(a[i] != b[i]){
            for(int j = i + 1 ; j < n ; j++){
                if(a[j] == b[i]){
                    swap(a[j], a[i]);
                    Try(i+1, countA - 1);
                    swap(a[i], a[j]);
                }
            }
        }
        else{
            Try(i+1, countA);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>k;
        cin>>a;
        maxA = b = a;
        n = a.length();
        sort(b.begin(), b.end(), greater<>());
        Try(0, k);
        cout<<maxA<<endl;
    }


    return 0;
}