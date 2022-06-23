#include<bits/stdc++.h>
using namespace std;
int minTrans(int s, int t){
    int countA = 0;
    while (s < t)
    {
        if(t % 2 == 1){
            t = (t + 1);
        }
        else t /= 2;
        countA++;
    }
    if(t < s){
        countA += (s-t);
    }
    return countA;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int S, T;
        cin>>S>>T;
        cout<<minTrans(S, T)<<endl;
    }
}