#include<bits/stdc++.h>
using namespace std;
typedef struct CV{
    int x, y, z;
}cv;
bool soSanh(cv a, cv b){
    return a.z > b.z;
}
void maxCv(int n , cv a[]){
    sort(a, a+n, soSanh);
    bool check[1005] = {0};
    int countCv = 0, ans = 0;
    for(int i = 0 ; i < n ; i++){
        int j = a[i].y;
        while (j >= 1 && check[j] == true) j--;
        if(j >= 1) {
            countCv++;
            ans+= a[i].z;
            check[j] = true;
        }
    }
    cout<<countCv<<" "<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cv a[n];
        for(int i = 0 ; i < n ; i++) {
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        maxCv(n, a);
    }
    
    return 0;
}