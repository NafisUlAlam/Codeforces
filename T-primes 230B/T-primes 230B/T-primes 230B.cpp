#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int n = 1000007;

vector<bool> Prime(n);



void sieve()
{
    for (int i = 0; i < n; i++)
    {
        Prime[i] = true;
    }
    Prime[0] = Prime[1] = false;
    for (int i = 2; i * i < n ; i++)
    {
        for (int j = i * i; j < n; j += i)
        {
            if (Prime[i]) 
            {
                Prime[j] = false;
            }
        }
    }
}


void solve()
{
    int n;
    cin >> n;
    ull number;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        ull root = sqrt(number);
        if (Prime[root] && root * 1ll * root == number) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

int main()
{
    sieve();
    solve();
}

