#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, f = -1, s = -1;
    cin >> n;
    vector<int> a(n, 0);
    for(int x, i = n; i >= 2; i--)
    {
        cout << "? " << 1 << " " << i << endl;
        cin >> x;
        s = x;
        if(i == n) {f = s; continue;}
        else
        {
            a[i] = f - s;
            f = s;
        }
    }
    cout << "? " << 2 << " " << 3 << endl;
    cin >> s;
    a[1] = s - a[2];
    a[0] = f - a[1];
    cout << "! ";
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}

int main()
{
    solve();
}
