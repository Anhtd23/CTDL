#include<bits/stdc++.h>
using namespace std;
int pos[1001];
int nag[1001];
int minDis(int duong , int am){
    if(duong == 0){
        return nag[1] + nag[0];
    }
    else if(am==0){
        return pos[0] + pos[1];
    }
    else{
        int min1 = 10000000;
        int r = 0, l = 0;
        while (r < duong && l < am)
        {
            int tmp = pos[r] + nag[l];
            if(tmp == 0 ){
                return 0;
            }
            else if(tmp > 0) l++;
            else r++;
            if(abs(tmp) < abs(min1)) min1 = tmp;
        }
        if(min1 > abs(pos[0] + pos[1])) min1 =pos[0] + pos[1];
        if(min1 > abs(nag[0] + nag[1])) min1 =nag[0] + nag[1];
        return min1;
    }
    
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, tmp;
        cin>>n;
        int duong = 0 , am = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>tmp;
            if(tmp >= 0) pos[duong++] = tmp; 
            else nag[am++] = tmp;
        }
        sort(pos, pos+duong);
        sort(nag, nag+am, greater<>());
        cout<<minDis(duong, am)<<endl;
    }
    
}