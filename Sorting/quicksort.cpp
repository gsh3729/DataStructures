#include <bits/stdc++.h>
using namespace std;

int find_pivot(vector<int>& a, int l, int h)
{
    int j = l;
    for(int i=l;i<h;i++)
    {
        if(a[i] <= a[h])
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[h]);
    return j;
}

void qs(vector<int>& a, int l, int h)
{
    if(l>=h)
    {
        return;
    }
    int pivot = find_pivot(a,l,h);
    qs(a,l,pivot-1);
    qs(a,pivot+1, h);
    
    return ;
}

int main()
{
    vector<int> a = {13,4,2,44,32};
    qs(a, 0, a.size()-1);
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    return 0;
}