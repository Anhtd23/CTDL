#include<bits/stdc++.h>
using namespace std;
string store[1001];
int main(){ 
    int t;
    cin>>t;
    cin.ignore(1);
    while (t--)
    {
        string a;
        getline(cin, a);
        stringstream ss(a);
        int countA = 0;
        while (ss>>store[countA]) countA++;
        for(int i = countA - 1 ; i >= 0 ; i--) cout<<store[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}