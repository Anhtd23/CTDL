    #include<bits/stdc++.h>
    using namespace std;
    string a;
    bool chuaxet[101];
    int maxLength(){
        int ans = 0;
        stack<int> c;
        for(int i = 0 ; i < a.length() ; i++){
            if(a[i] == '('){
                c.push(i);
            }
            else{
                if(!c.empty()){
                    chuaxet[i] = chuaxet[c.top()] = true;
                    c.pop();
                }
            }
        }
        int countA = 0;
        for(int i = 0 ; i < a.length(); i++){
            if(chuaxet[i] )
            {
                countA++;
                chuaxet[i] = false;
            }
        }
        return countA;
    }
    int main(){
        int t;
        cin>>t;
        while(t--){
            cin>>a;
            cout<<maxLength()<<endl;
        }

        return 0;
    }