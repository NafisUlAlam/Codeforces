#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b;
    int f, s, x, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i <= 3)
        {
            f = i;
            s = i + 1;
            if(i == 3) s = 1;
            cout << "? " << f << " " << s << endl;
            cin >> x;
            b.push_back(x);
            if(i % 2 == 1) sum += x;
            else sum -= x;
            if(i == 3)
            {
                a[1] = sum / 2;
                a[3] = b[2] - a[1];
                a[2] = b[1] - a[3];
            }
        }
        else
        {
            cout << "? " << 1 << " " << i << endl;
            cin >> x;
            a[i] = x - a[1];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(i == 1) cout << "! ";
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    solve();
}
