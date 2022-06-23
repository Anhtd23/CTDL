#include<iostream>
using namespace std;
int n;
bool xuoi[50] = {0};
bool nguoc[50] = {0};
bool cot[50] = {0};
bool hang[50] = {0};
bool x[50] = {0};
int count = 0;
int a[8][8];
void Try(int i, int sum){
    for(int j = 0 ; j < n ; j++){
        if(!x[i] && !xuoi[i-j+n] && !nguoc[i+j-1] && !cot[j]){
            x[i] = xuoi[i-j+n] = nguoc[i+j-1] = cot[j] = 1;
            if( i == n - 1) {
                sum += a[i][j];
                if(count < sum) count = sum;
            }                
            else Try(i+1, sum + a[i][j]);
            x[i] = xuoi[i-j+n] = nguoc[i+j-1] = cot[j] = 0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        n = 8;
        count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n ; j++) cin>>a[i][j];
        }
        Try(0, 0);
        cout<<count<<endl;
    }
    
}