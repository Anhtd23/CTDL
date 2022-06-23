#include<bits/stdc++.h>
using namespace std;
int n, k;
void Try(int i, string a, int countA){
    if(countA == k ){
        cout<<a<<endl;
        return;
    }
    if(i >= n) return;
    for(int j = i ; j < n; j++){
        char tmp = j + 'A';
        Try(j + 1, a + tmp, countA+1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        Try(0, "", 0);
    }
    return 0;
}