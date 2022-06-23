#include<iostream>
#include<stack>
#include<string>
using namespace std;
pair<int, char> arr[100000];
int d[100000]={0};
int numberBracket(string a){
    int n = a.length();
    for(int i  = 0 ; i < n ; i++){
        arr[i].first = i;
        arr[i].second = a[i];
    }
    stack<pair<int, char>> c;
    for(int i = 0 ; i < n ; i++){
        if(arr[i].second == '('){
            c.push(arr[i]);
            continue;
        }
        else{
            if(!c.empty()){
                d[c.top().first] = 1;
                d[arr[i].first] = 1;
                c.pop();
            }
        }
    }
    int count = 0, max = 0;
    for(int i = 0 ; i < n ; i++){
        if(d[i] == 1){
            count++;
            if(max < count ) max = count;
            d[i] = 0;
        }
        else count = 0;
    }
    return max;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a; 
        cin>>a;
        cout<<numberBracket(a)<<endl;
    }
    
}