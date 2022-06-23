#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
Node* createNode(int a[], int l, int r){
    if(l > r) return NULL;
    int minA = (l + r) / 2;
    Node* tmp = new Node(a[minA]);
    tmp->left = createNode(a, l , minA-1);
    tmp->right = createNode(a, minA+1, r);
    return tmp;
}
void countNode(Node* root){
    queue<Node*> q;
    q.push(root);
    int ans = 0;
    while(!q.empty()){
        Node* c = q.front();
        q.pop();
        if(c->left == NULL && c->right == NULL) ans++;
        else{
            if(c->left != NULL) q.push(c->left);
            if(c->right != NULL) q.push(c->right);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        sort(a, a+n);
        Node* root = createNode(a, 0, n-1);
        countNode(root);
    }
    return 0;
}