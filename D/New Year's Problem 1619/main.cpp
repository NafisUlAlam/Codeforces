#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull n, m;
vector<vector<ull>> p;


bool check(ull x)
{
    bool peir = false;
    ull c = 0;
    vector<bool> abl(m,false);

    for (int i = 0; i < n; i++)
    {
        c = 0;
        for(int j = 0; j < m; j++)
        {
            if(p[i][j] >= x)
            {
                abl[j] = true;
                c += 1;
            }
        }
        if(c > 1) peir = true;
    }

    if(!peir && m > 1) return false;
    bool ans = true;
    for(auto elem : abl)
    {
        ans &= elem;
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    p.assign(n, vector<ull> (m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }
    ull left = 1; ull right = 2;

    while(check(right) == true) right *= 2;
    while( right - left > 1)
    {
        ull mid = (left + right) / 2;
        if(check(mid) == true) left = mid;
        else right = mid;
    }

    cout << left << endl;
}



int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
