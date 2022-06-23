#include<iostream>
#include<math.h>
using namespace std;
int sA5[7];
int sA6[7];
int sB5[7];
int sB6[7];
int a, b;
int count5A, count5B, count6A, count6B;
int main(){
    
        cin>>a>>b;
        string sA = to_string(a);
        string sB = to_string(b);
        int nA = sA.length();
        int nB = sB.length();
        int max = a + b , min = a + b;
        for(int i = nA - 1; i >= 0; i--){
            if(sA[i] == '5'){
                max += pow(10, nA-1-i);
            }
            else if(sA[i] == '6'){
                min -= pow(10, nA-1-i);
            }
        }
        for(int i = nB - 1; i >= 0; i--){
            if(sB[i] == '5'){
                max += pow(10, nB-1-i);
            }
            else if(sB[i] == '6'){
                min -= pow(10, nB-1-i);
            }
        }
        cout<<min<<" "<<max<<endl;
    
    return 0;
}