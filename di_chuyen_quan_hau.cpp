#include<iostream>
using namespace std;
int n;
bool xuoi[50] = {0};
bool nguoc[50] = {0};
bool cot[50] = {0};
bool hang[50] = {0};
bool x[50] = {0};
int count = 0;
void Try(int i){
    for(int j = 0 ; j < n ; j++){
        if(!x[i] && !xuoi[i-j+n] && !nguoc[i+j-1] && !cot[j]){
            x[i] = xuoi[i-j+n] = nguoc[i+j-1] = cot[j] = 1;
            if( i == n - 1) count++;
            else Try(i+1);
            x[i] = xuoi[i-j+n] = nguoc[i+j-1] = cot[j] = 0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        count = 0;
        Try(0);
        cout<<count<<endl;
    }
    
}