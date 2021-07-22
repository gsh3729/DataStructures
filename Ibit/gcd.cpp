#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0) return b; //exactly divided
    else if (b == 0) return a;
    
    if (a == b) return a; //base case 

    return a>b ?  gcd(a-b,b): gcd(a, b-a);
}

int gcd_rec(int a, int b)
{
    if (b==0) return a;
    return gcd_rec(b, a%b);
}

int gcd_opt(int n, int m) 
{
    if (n%m ==0) return m;
    if (n < m) swap(n, m);
    while (m > 0) 
    {
        n = n%m;
        swap(n, m);
    }
    return n;
}
int main()
{
    cout << gcd_opt(36, 60) << endl;
    return 0;
}