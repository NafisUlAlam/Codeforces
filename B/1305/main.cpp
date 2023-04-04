#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> a(2);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(') a[0].push_back(i + 1);
        else a[1].push_back(i + 1);
    }

    int l = 0, r = (int)a[1].size() - 1;
    vector<int> ans;
    while(l <(int)a[0].size() && r >= 0 && a[0][l] < a[1][r])
    {
        ans.push_back(a[0][l]);
        ans.push_back(a[1][r]);
        l++;
        r--;
    }
    if(ans.size() > 0)
    {
        sort(ans.begin(), ans.end());
        cout << 1 << endl << ans.size() << endl;
        for(auto elem : ans) cout << elem << " "; cout << endl;
    }
    else cout << 0 << endl;
}

int main()
{
    solve();
}
