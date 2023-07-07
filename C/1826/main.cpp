#include <bits/stdc++.h>
using namespace std;

void sieve(vector<int>& a)
{
    for(int i = 2; i * i < (int) a.size(); i++)
    {
        for(int j = i * i; j < a.size(); j += i)
        {
            if(a[j] == j) a[j] = i;
        }
    }
}

void solve(vector<int>& a)
{
    int n, m;
    cin >> n >> m;
    if(a[n] > m || n == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> factors(1e6 + 10, 0);
    for(int i = 1; i < factors.size(); i++) factors[i] = i;
    sieve(factors);
    int t = 1;
    cin >> t;
    while(t--) solve(factors);
}
