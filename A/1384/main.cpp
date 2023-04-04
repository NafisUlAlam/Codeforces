#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n + 1);
    string s;
    for(int i = 0; i <= 60; i++) s.push_back('a');
    a[0] = s;
    for(int i = 0; i < n; i++)
    {
        a[i + 1] = a[i];
        int x;
        cin >> x;
        if(a[i + 1][x] != 'z') a[i + 1][x]++;
        else a[i + 1][x] = 'a';
    }
    for(auto elem : a)cout << elem << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
