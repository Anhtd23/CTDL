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
void duyetTheoMuc(node *root){
    queue<node*> q;
    q.push(root);
    stack<int> s;
    while (!q.empty())
    {
        node* c = q.front();
        q.pop();
        s.push(c->data);
        if(c->right != NULL) q.push(c->right);
        if(c->left != NULL) q.push(c->left);
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
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
        duyetTheoMuc(root);
        cout<<endl;
    }
    

    return 0;
}