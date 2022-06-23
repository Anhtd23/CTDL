#include <iostream>
using namespace std;
int a[1000];
void sort(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = a[i], in = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                in = j;
            }
        }
        if (in != -1)
            swap(a[i], a[in]);
        cout<<"Buoc "<<i+1<<": ";
        for(int j = 0 ; j < n ; j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(n);
}