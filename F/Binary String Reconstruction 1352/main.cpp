#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    string a = "", b = "", c = "", output = "";
    if(n0 > 0)
    {
        for(int i = 1; i <= n0 + 1; i++) a += '0';
    }
    if(n1 > 0)
    {
        for(int i = 1; i <= n1 + 1; i++)
        {
            if(i % 2 == 1) b += '1';
            else b += '0';
        }
    }
    if(n2 > 0)
    {
        for(int i = 1; i <= n2 + 1; i++) c += '1';
    }
    //cout << a << " " << b << " " << c << endl;
    if(a != "" && b != "") b.pop_back();
    if(b != "" && b.back() == '1' && c != "") c.pop_back();
    output = a + b + c;
    cout << output << endl;
}


int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
