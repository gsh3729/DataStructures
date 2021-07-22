#include <bits/stdc++.h>
using namespace std;

vector<int> insertion(vector<int> a)
{
    for(int i=1;i<a.size();i++)
    {
        int temp = a[i];
        int j = i-1;
        while(j>=0 and a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    return a;
}

int main()
{
    vector<int> a = {13,4,2,44,32};
    vector<int> b = insertion(a);
    for(auto i:b)
    {
        cout<<i<<" ";
    }
    return 0;
}