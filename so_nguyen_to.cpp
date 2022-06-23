#include<bits/stdc++.h>
using namespace std;
int snt[100];
int countA = 0;
int P, S, N;
string store[200];
bool Prime(int n){
    if( n <= 1 ) return false;
    if( n % 2 == 0 ) return false;
    else if( n == 2) return true;
    for(int i = 3; i <= sqrt(n); i+=2){
        if(n % i == 0 ) return false;
    }
   return true;
}
void init(){
    int count = 1, run = 3;
    snt[0] = 2;
    while (count < 100)
    {
        if(Prime(run)) snt[count++] = run;
        run += 2;
    }
}
void Try(int i, int s, int count, int sum, string a){
    if(sum == S ){
        if(count == N) store[countA++] = a;
    }
    else if(sum < S){
        for(int j = i ; j <=  s; j++){
            string tmp= to_string(snt[j]); 
            Try(j+1, s, count+1, sum + snt[j], a + tmp+" "); 
        }
    }
}
int main(){
    int t;
    cin>>t;
    init();
    while (t--)
    {
        cin>>N>>P>>S;
        if( N == 1 ){
            cout<<1<<endl;
            cout<<S<<endl;
            continue;
        }else{
            int tmp, s;
            countA = 0;
            for(int i = 0 ; i < 100; i++) {
                if(snt[i] == P) 
                    tmp = i;
                if(S > snt[i]) s = i;
            }
            Try(tmp+1,s, 0, 0, "");
            cout<<countA<<endl;
            for(int i = 0 ; i < countA; i++) cout<<store[i]<<endl;
        }
    }
    
    return 0;
}