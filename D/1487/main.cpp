#include <bits/stdc++.h>

using namespace std;

vector<int> a;

void pre()
{
    int l = 1, r = 4, diff = 3;
    while(l <= (int)1e9)
    {
        a.push_back(r);
        diff += 4;
        l = r + 1;
        r = l + diff;
    }
    //cout << a.size() << endl;
}

void solve()
{
    int n;
    cin >> n;
    int index = lower_bound(a.begin(), a.end(), n) - a.begin();
    cout << index << endl;
}

int main()
{
    pre();
    int t;
    cin >> t;
    while(t--) solve();
}
