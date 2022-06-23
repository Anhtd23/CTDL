#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string b;
        cin>>b;
        int len = b.length();
        for(int i = 0; i < len ; i++) a[i] = b[i] - '0';
        cout<<n<<" ";
        if(next_permutation(a, a+len)){
            for(int i = 0 ; i < len ; i++) cout<<a[i];
        }
        else cout<<"BIGGEST";
        cout<<endl;

    }
    

    return 0;
}