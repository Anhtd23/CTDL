#include<bits/stdc++.h>
using namespace std;
bool check = true;
int n, k;
int a[100];
int mark[100]= {0};
void after(){
    int i = k - 1;
    while (a[i] == n + i - k + 1 && i >= 0 ) i--;
    if(i >=0 ){
        a[i]++;
        for(int j = i + 1; j < k ; j++) a[j] = a[j-1]+1;
    }
    else check = false;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        check = true;
        cin>>n>>k;
        for(int i = 0; i < k; i++) {
            cin>>a[i];
            mark[a[i]]++;
        }
        after();
        //for(int i = 0 ; i < k ; i++) cout<<a[i]<<" ";
        if(check == false){
            cout<<k<<endl;
            for(int i = 0 ; i < 100; i++) {
                mark[i] = 0;
            }
        }
        else{
            for(int i = 0; i < k ; i++) mark[a[i]]++;
            int count = 0 ;
            for(int i = 0 ; i < 100; i++) {
                if(mark[i] == 2) count++;
                mark[i] = 0;
            }
            cout<<k - count<<endl;
        }
        
    }
    return 0;
}