#include<bits/stdc++.h>
using namespace std;
string a;
struct Node{
    char data;
    Node *left, *right;
    Node(char n){
        data = n;
        left = right = NULL;
    }
};
Node *root;
bool isOperator(char b){
    if(b == '+' || b == '-' || b == '*' || b == '/') return true;
    return false;
}
void cayBieuThuc(){
    stack<Node *> c;
    Node *tmp1, *tmp2;
    for(int i = 0; i < a.length(); i++){
        if(isOperator(a[i])){
            Node* tmp = new Node(a[i]);
            tmp1 = c.top();
            c.pop();
            tmp2 = c.top();;
            c.pop();
            tmp->left = tmp2;
            tmp->right = tmp1;
            c.push(tmp);
        }
        else {
            Node *tmp = new Node(a[i]);
            c.push(tmp);
        }
    }
    root = c.top();
}
void inorder(Node *root){
    if(root->left != NULL)inorder(root->left);
    cout<<root->data;
    if(root->right != NULL) inorder(root->right);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a;
        cayBieuThuc();
        inorder(root);
        cout<<endl;
    }
    return 0;
}