#include<bits/stdc++.h>
using namespace std;
int store[60];
int p[4] = {1, 2, 3, 5};
void Try(long long W, int c){
    int maxE = c * 4;
    
}
int main(){
    int t;
    cin>>t;
    int countA = 0;
    for(int i = 1 ; i < 16 ; i++) {
        for(int j = 0 ; j < 4; j++){
            store[countA++] = p[j] * (long long)(pow(10, i));
        }
    }
    while (t--)
    {
        long long W;
        cin>>W;
        int c;
        cin>>c;
        if(W % 1000 != 0 ) {
            cout<<0<<endl;
            continue;
        }
        else{
            W/= 1000;
            Try(W, c);
        }
    }
    
    return 0;
}