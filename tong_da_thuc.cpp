#include<bits/stdc++.h>
using namespace std;
typedef struct Data{
    int x, y;
    struct Data *next;
}*data;
int chuyen(string a){
    stringstream ss(a);
    int k ; ss>>k;
    return k;
}
data tachBieuThuc(string a){
    data express, nextData;
    express = (data)malloc(sizeof(data));
    data ptr = express;
    stringstream ss(a);
    string s;
    ss>>s;
    int end = s.find("*x^");
    express->x = chuyen(s.substr(0, end));
    express->y = chuyen(s.substr(end+ 3, s.length() - 1));
    while(ss>>s)
    {
        if(s.length() == 1) continue;
            int end = s.find("*x^");
            data nextData;
            nextData = (data)malloc(sizeof(data));
            nextData->x = chuyen(s.substr(0, end));
            nextData->y = chuyen(s.substr(end+ 3, s.length() - 1));
            nextData->next = NULL;
            express->next = nextData;
            express = nextData;
    }
    return ptr;
}
void print(data d){
    cout<<d->x<<"*x^"<<d->y;
}
int main(){
    int t;
    cin>>t;
    cin.ignore(1);
    while (t--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        data ptrA = tachBieuThuc(a);
        data ptrB = tachBieuThuc(b);
        while (ptrA != NULL || ptrB != NULL)
        {
            if(ptrA->y > ptrB->y) {
                print(ptrA);
                ptrA = ptrA->next;
            }
            else if(ptrA->y < ptrB->y) {
                print(ptrB);
                ptrB = ptrB->next;
            }
            else {
                cout<<ptrA->x+ptrB->x<<"*x^"<<ptrA->y;
                ptrA = ptrA->next;
                ptrB = ptrB->next;
            }
            if(ptrA != NULL || ptrB != NULL ) cout<<" + ";
        }
        if(ptrA == NULL){
            while (ptrB != NULL)
            {
                print(ptrB);
                if(ptrB != NULL) cout<<" + ";
            }
        }
        else if(ptrA != NULL){
            while (ptrB != NULL)
            {
                print(ptrB);
                if(ptrB != NULL) cout<<" + ";
            }
        }
        cout<<endl;
    }
    return 0;
}