#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int countA = 0;
        int n;
        cin>>n;
        int a[n], b[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        for(int i = 0 ; i < n ; i++) cin>>b[i];
        for(int i = 0 ; i < n - 1 ; i++){
            int min = b[i];
            int index = i;
            for(int j = i + 1; j < n ; j++){
                if(min > b[j] ){
                    index = j;
                    min = b[j];
                }
            }
            if(index != i){
                swap(a[i], a[index]);
                swap(b[i], b[index]);
            }
        }
        countA = 1;
        int start = a[0], end = b[0];
        for(int i = 1 ; i < n ; i++){
            if(a[i] >= end) {
                countA++;
                start = a[i];
                end = b[i];
            }
        }
        cout<<countA<<endl;
    }

    return 0;
}