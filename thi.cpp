#include<bits/stdc++.h>
using namespace std;
int n;
string b[100000];
int countA = 0;
void Try(int i, string a){
    if( i == n){
            b[countA++] = a;
            return;
    }
    for(int j = 0; j <= 1 ; j++){
        if(j == 0) Try(i+1, a + '6');
        else Try(i+1, a + '8');
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        countA = 0;
        cin>>n;
        Try(0, "");
        cout<<countA<<endl;
        for(int i = 0 ; i < countA ; i++) cout<<b[i]<<" ";
        cout<<endl;
    }
    
}