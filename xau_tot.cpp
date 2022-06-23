#include <bits/stdc++.h>
using namespace std;
long long n;
long long greatString(string a){
    long long countA = 0;
    int posA = 0 , posB = 0;
    for(int i = 1 ; i <= n ; i++ ){
      if(a[i-1] == 'A'){
        int dis = i - posA;
        countA += dis + (posA > posB && posB);
        posA = i;
      }
      else{
        int dis  = i - posB;
        countA += dis + (posB > posA && posA);
        posB = i;
      }
    }
    //cout<<countA<<endl;
    return (n * (n+1))/2 -countA;
}

int main()
{
    cin>>n;
    string a;
    cin>>a;
    cout<<greatString(a);
    return 0;
}