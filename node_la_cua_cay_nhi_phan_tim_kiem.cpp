#include<bits/stdc++.h>
using namespace std;
void leafNode(int preorder[], int n)
{
    stack<int> s;
    int countA = 0;
    for (int i = 0, j = 1; j < n; i++, j++)
    {
        bool found = false;
        if (preorder[i] > preorder[j])
            s.push(preorder[i]);
        else
        {
            while (!s.empty())
            {
                if (preorder[j] > s.top())
                {
                    s.pop();
                    found = true;
                }
                else
                    break;
            }
        }
  
        if (found)
            countA++;
    }
    cout << n - countA - 1 << endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        leafNode(a, n);
    }
    

    return 0;
}