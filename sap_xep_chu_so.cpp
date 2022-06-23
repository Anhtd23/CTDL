#include<bits/stdc++.h>
using namespace std;
int mark[100];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cin.ignore(1);
        string a;
        getline(cin, a);
        n = a.length();
        memset(mark,0, 4*100);
        for(int i = 0 ; i < n ; i++){
            mark[a[i]]++;
        }
        for(int i = '0' ; i <= '9'; i++) if(mark[i] > 0 ) cout<<(char)i<<" ";
        cout<<endl;
    }
    return 0;
}