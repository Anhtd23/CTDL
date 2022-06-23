#include<bits/stdc++.h>
using namespace std;
typedef struct dinh {
    int x, y;
    int value;
}Dinh;
bool compareA(Dinh a, Dinh b){
    if(a.value != b.value) return a.value > b.value;
    else if(a.x != b.x){
        return a.x > b.x;
    }
    else return a.y > b.y;
}
class Dothi{
    public:
    int a[100][100];
    int chuaxet[100];
    Dinh tapDinh[10000];
    int n, countA = 0;
    void nhap(){
        cin>>n;
        for(int i = 1 ; i <= n; i++ ){
            for(int j = 1; j <= n ; j++) cin>>a[i][j];
        }
    }
    void reset(){
        for(int i = 1 ; i <= n ; i++) chuaxet[i] = false;
    }
    void in(Dinh *store, int n){
        for(int i = 0 ; i < n ; i++) cout<<store[i].x<<" "<<store[i].y<<endl;
    }
    void nhanDinh(){
        for(int i = 1 ; i <= n - 1 ; i++){
            for(int j = i +  1;  j <= n ; j++){
                if(a[i][j]){
                    tapDinh[countA].x = i;
                    tapDinh[countA].y = j;
                    tapDinh[countA].value = a[i][j];
                    countA++;
                }
            }
        }
        sort(tapDinh, tapDinh + countA, compareA);
    
    }
    bool kiemTraChuTrinh(Dinh *a, int n){
        reset();
        for(int i = 0 ; i < n ; i++){
            if(chuaxet[a[i].x] && chuaxet[a[i].y]) {
                return false;
            }
            else {
                chuaxet[a[i].x] = true;
                chuaxet[a[i].y] = true;
            }
        }
        return true;
    }
    void Kruskal(){
        nhanDinh();
        Dinh store[100];
        int countDinh = 0;
        int sum = 0;
        while(countDinh < n - 1 && countA > 0){
            store[countDinh] = tapDinh[countA-1];
            if(kiemTraChuTrinh(store, countDinh+1)){
                countDinh++;
                sum += tapDinh[countA-1].value;
            }
            countA--;
        }
        if(countDinh == n - 1) {
            cout<<"dH = "<<sum<<endl;
            in(store, countDinh);
        }
        else cout<<"-1"<<endl;
    }
};
int main(){
    Dothi a;
    a.nhap();
    a.Kruskal();
    return 0;
}