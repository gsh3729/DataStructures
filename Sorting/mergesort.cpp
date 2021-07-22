#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int l, int mid, int h)
{
        vector<int> left, right;
        int x;
        for(x = l;x<=mid;x++)
        {
            left.push_back(a[x]);
        }
        for(x = mid+1;x<=h;x++)
        {
            right.push_back(a[x]);
        }
        
        int i=0, j=0, k=l;
        while(i<left.size() && j<right.size())
        {
            if(left[i]<right[j])
            {
                a[k] = left[i];
                i++;
            }
            else
            {
                a[k] = right[j];
                j++;
            }
            k++;
        }
        while(i<left.size())
        {
            a[k] = left[i];
            k++; 
            i++;
        }
        while(j<right.size())
        {
            a[k] = right[j];
            j++;
            k++; 
        }
        return;
}
void mergesort(vector<int>& a, int l, int h)
{
    if(l<h)
    {
        int mid = int((l+h)/2);
        mergesort(a, l, mid);
        mergesort(a, mid+1, h);
        merge(a, l, mid, h);
    }
    return;    
}

int main()
{
    vector<int> a = {13,4,2,44,32};
    mergesort(a, 0, a.size()-1);
    cout<<"output"<<endl;
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    return 0;
}