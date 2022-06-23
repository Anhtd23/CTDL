#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        int countA = 0;
        for(int i = 0 ; i < n - 1; i++){
            int min = a[i];
            int index = i;
            for(int j = i+1; j < n ; j++){
                if(min > a[j]) {
                    min = a[j];
                    index = j;
                }
            }
            if(min != a[i]) {
                swap(a[i], a[index]);
                countA++;
            }
        }
        cout<<countA<<endl;
    }
    return 0;
}