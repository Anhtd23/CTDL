#include<bits/stdc++.h>
using namespace std;
typedef pair<int , int > douInt;
bool isOperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')') return true;
    else return false;
}
void setVal(douInt &val, int a, int b){
    val.first = a;
    val.second = b;
}
long long tinhToan(long long a, long long b, int tt){
    if(tt == 2 ) return a + b;
    if(tt == 3 ) return a - b;
    if(tt == 4 ) return a * b;
    if(tt == 5 )  return a / b;
}
douInt store[100];
int countA = 0;
long long tinh(string a){
    int n = a.length();
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        if(isOperator(a[i])){
            if(!isOperator(a[i-1]))setVal(store[countA++], sum, -1);
            if(a[i] == '+') {
                setVal(store[countA++], 2, 2);
            }
            else if(a[i] == '-') {
                setVal(store[countA++], 3, 2);
            }
            else if(a[i] == '*') {
                setVal(store[countA++], 4, 3);
            }
            else if(a[i] == '/') setVal(store[countA++], 5, 3);
            else if(a[i] == '(') setVal(store[countA++], 6, 0);
            else setVal(store[countA++], 7, 7);
            sum = 0;
        }
        else{
            sum = sum * 10 + (a[i]-'0');
        }
    }
    if(!isOperator(a[n-1])){ setVal(store[countA++], sum, -1);}; 
    //for(int i = 0 ; i < countA ; i++) cout<<store[i].first<<" "<<store[i].second<<endl;
    stack<douInt> c;
    long long ans = 0;
    douInt F[100];
    int k = 0;
    for(int i = 0 ; i < countA ; i++){
        if(store[i].second == -1) setVal(F[k++], store[i].first, store[i].second);
        else if(store[i].second == 0){
            c.push(store[i]);
        }
        else if(store[i].second == 7){
            while (c.top().second != 0)
            {
                setVal(F[k++], c.top().first, c.top().second); 
                c.pop();
            }
            c.pop();
        }
        else {
            while (!c.empty() && store[i].second <= c.top().second)
            {
                F[k++] = c.top();
                c.pop();
            }
            c.push(store[i]);
        }
    }
    while (!c.empty())
    {
        if(c.top().second == 0) break;
        setVal(F[k++], c.top().first, c.top().second);
        c.pop();
    }
    stack<long long> q;
    for(int i = 0 ; i < k ; i++ ){
        if(F[i].second == -1) q.push(F[i].first);
        else {
            long long tmp1 = q.top();
            q.pop();
            long long tmp2 = q.top();
            q.pop();
            long long tmp3 = tinhToan(tmp2, tmp1, F[i].first);
            q.push(tmp3);
        }
    }
    return q.top();
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        countA = 0;
        string a;
        cin>>a;
        cout<<tinh(a)<<endl;
    }
    

    return 0;
}