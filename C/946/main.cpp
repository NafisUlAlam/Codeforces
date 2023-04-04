#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    vector<bool> flag(26, false);
    vector<pair<int, char>> a;
    cin >> s;
    int n = s.size();
    int i = 0;
    char c = 'a';
    while(i < n)
    {
        if(s[i] <= c && c <= 'z')
        {
           flag[c - 'a'] = true;
           a.push_back(make_pair(i, c));
           c++;
        }
        i++;
    }
    bool f = true;
    for(auto e : flag) f &= e;
    if(f)
    {
        int j = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(j <(int) a.size() && a[j].first == i)
            {
                s[i] = a[j].second;
                j++;
            }
        }
        cout << s << endl;
    }
    else cout << -1 << endl;

}

int main()
{
    solve();
}
