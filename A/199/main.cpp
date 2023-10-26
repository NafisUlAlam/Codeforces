#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> fib;
void pre()
{
    fib.push_back(0); fib.push_back(1);
    while(fib[fib.size() - 2] + fib.back() < 1e9)
    {
        fib.push_back(fib[fib.size() - 2] + fib.back());
    }
    //cout << fib.size() << endl;
    //for(auto e : fib) cout << e << endl;
}

void solve()
{
    int n;
    cin >> n;
    int curr = n;
    for(int i = 1; i <= 3; i++)
    {
        int ind = lower_bound(fib.begin(), fib.end(), curr) - fib.begin();
        if(fib[ind] != curr)ind--;
        cout << fib[ind] << " ";
        curr -= fib[ind];
    }
    cout << endl;
}

int main()
{
    pre();
    solve();
}
