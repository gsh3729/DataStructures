#include<bits/stdc++.h>
using namespace std;

void print_set(set<int> s)
{
    set<int> :: iterator i;
    for(i=s.begin(); i!=s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    set<int> s; //set<int, greater<int>> s;
    s.insert(3);
    s.insert(1);
    print_set(s);
    s.insert(2);
    print_set(s);
    s.insert(3); //wont add
    print_set(s);

    s.erase(s.begin(), s.find(2));
    print_set(s);

    s.insert(1);
    print_set(s);
    s.erase(3);
    print_set(s);

    return 0;
}