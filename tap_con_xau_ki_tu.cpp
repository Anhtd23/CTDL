#include<bits/stdc++.h>
using namespace std;
char s[20];
int n;
void Try(int i , string a){
    cout<<a<<" ";
    for(int j = i+1 ; j < n ; j++){
        Try(j, a + s[j]);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>s[i];
        for(int i = 0 ; i < n ; i++){
            string tmp = "";
            Try(i, tmp+s[i]);
        }  
        cout<<endl;
    }
    

    return 0;
}