#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
}node;
int N, maxA = 0;
bool check = false, checkLa = false, OK = false;
void makeNode(node *root, int x, int y, char c){
    if(c == 'L') root->left = new node(y);
    else root->right = new node(y);
}
void insert(node *root, int x, int y, char c){
    if(check == true) return;
    if(root == NULL ) return;
    if(root->data == x ) {
        makeNode(root, x, y, c);
        check = true;
    }
    else{
        insert(root->left, x, y, c);
        insert(root->right, x, y, c);
    }
}
void nodeLa(node *root,int level){
    if(checkLa == true) return;
    if(root->left == NULL && root->right == NULL) { 
        if(OK == false) {
            maxA = level;
            OK = true;
        }
        else {
            if(level != maxA) checkLa = true;
        }
    }
    else{
        if(root->left != NULL) nodeLa(root->left,level+1);
        if(root->right != NULL) nodeLa(root->right,level+1);
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>N;
        int x, y;char c;
        cin>>x>>y>>c;
        node *root = NULL;
        root = new node(x);
        makeNode(root,x, y, c);
        for(int i = 1 ; i < N ; i++){
            cin>>x>>y>>c;
            check = false;
            insert(root,x, y, c);
        }
        checkLa = false;
        OK = false;
        nodeLa(root, 0);
        if(checkLa == true) cout<<0<<endl;
        else cout<<1<<endl;
    }
    

    return 0;
}