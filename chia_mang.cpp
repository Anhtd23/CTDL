#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[20];
bool chuaxet[20];
int sumA;
bool ans = false;
bool Try(int i, int sum){
    if(sum == a[i]) {
        chuaxet[i] = true;
        return true;
    }
    if(sum < a[i]) return false;
    else {
        for(int j = i ; j < n ; j++){
            if(sum > a[j] && chuaxet[j] == false){
                bool check = Try(j + 1, sum - a[j]);
                if(check){
                    chuaxet[j] = true;
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
        ans = false;
        cin>>n>>k;
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a+n);
        int sum = 0;
        for(int i = 0 ; i < n ; i++) sum += a[i];
        if(sum % k != 0 ){
            cout<<0<<endl;
        }
        else {
            for(int i = 0 ; i < n ; i++) chuaxet[i] = false;
            cout<<Try(0, sum/k)<<endl;
        }
        
}