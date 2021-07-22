#include <bits/stdc++.h>
using namespace std;

vector<int> bubble(vector<int> a)
{
    for(int i=0;i<a.size()-1;i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]>a[j])
            {
                // int temp = a[j];
                // a[j] = a[i];
                // a[i] = temp;
                swap(a[i], a[j]);
            }
        }
    }
    return a;
}

int main()
{
    vector<int> a = {13,4,2,44,32};
    vector<int> b = bubble(a);
    for(auto i:b)
    {
        cout<<i<<" ";
    }
    return 0;
}