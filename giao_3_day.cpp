#include<bits/stdc++.h>
using namespace std;
int n1, n2, n3;
long long a[1000000], b[1000000], c[1000000];
long long ab[1000000], bc[1000000];
int countAB, countBC;
bool check = false;
void hopAB(){
    int i = 0, j = 0;;
    while (i < n1 && j < n2)
    {
        if( a[i] == b[j]) {
            ab[countAB++] = a[i];
            i++;
            j++;
        }
        else{
            if(a[i] > b[j] )j++;
            else i++;
        }
    }
}
void hopBC(){
    int i = 0, j = 0;
    while (i < n2 && j < n3)
    {
        if( b[i] == c[j]) {
            bc[countBC++] = b[i];
            i++;
            j++;
        }
        else{
            if(b[i] > c[j] ) j++;
            else i++;
        }
    }
}
void hop2cuoi(){
    int i = 0, j = 0;
    while (i < countAB && j < countBC)
    {
        if( ab[i] == bc[j]) {
            cout<<ab[i]<<" ";
            check = true;
            i++;
            j++;
        }
        else{
            if(ab[i] > bc[j] )j++;
            else i++;
        }
    }
    if(check == false) cout<<"-1";
}
void hop3day(){
    hopAB();
    hopBC();
    hop2cuoi();
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        countBC = countAB = 0;
        check = false;
        cin>>n1>>n2>>n3;
        for(int i = 0 ; i < n1; i++) cin>>a[i];
        for(int i = 0 ; i < n2; i++) cin>>b[i];
        for(int i = 0 ; i < n3; i++) cin>>c[i];
        hop3day();
        cout<<endl;
    }
    
    return 0;
}