#include<bits/stdc++.h>
using namespace std;
string a[10000];
long long n;
struct Node{
    long long data;
    Node *left, *right;
    Node(long long b){
        data = b;
        left = right = NULL;
    }
};
long long chuyen(string a){
    stringstream ss(a);
    long long tmp;
    ss>>tmp;
    return tmp;
}
long long chuyenOperator(string b){
    if(b == "+") return -1;
    if(b == "-") return -2;
    if(b == "*") return -3;
    if(b == "/") return -4;
}
bool isOperator(string b){
    if(!b.compare("+")|| !b.compare("-")|| !b.compare("*")|| !b.compare("/")) return true;
    return false;
}
long long tinh(long long x, long long y, long long b){
    if(b == -1) return x+y;
    if(b == -2) return x-y;
    if(b == -3) return x*y;
    if(b == -4) return x/y;
}
long long tinhGiaTri(Node *root){
    //cout<<root->data<<endl;
    if(root->left != NULL){
        long long x = tinhGiaTri(root->left);
        long long y = tinhGiaTri(root->right);
        long long k = tinh(x, y, root->data);
        return k;
    }
    else return root->data;
}
void cayBieuThuc(){
    queue<Node*> q;
    Node *tmp1, *tmp2; 
    Node* root = new Node(chuyenOperator(a[0]));
    q.push(root);
    int i = 1;
    while(i < n){
        Node* tmp = q.front();
        q.pop();
        if(isOperator(a[i])){
            tmp1 = new Node(chuyenOperator(a[i]));
        }
        else {
            tmp1 = new Node(chuyen(a[i]));
        }
        i++;
        if(isOperator(a[i])){
            tmp2 = new Node(chuyenOperator(a[i]));
        }
        else {
            tmp2 = new Node(chuyen(a[i]));
        }
        i++;
        tmp->left = tmp1;
        tmp->right = tmp2;
        q.push(tmp1);
        q.push(tmp2);
    }
    cout<<tinhGiaTri(root)<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i = 0 ; i < n ; i++) cin>>a[i];  
        cayBieuThuc();
    }
    return 0;
}