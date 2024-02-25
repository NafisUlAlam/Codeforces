#include <bits/stdc++.h>

using namespace std;

int get(string& s, int l, int r, char ch)
{
    if(l == r)
    {
        if(s[l] == ch) return 0;
        else return 1;
    }
    int mid = (l + r) / 2, cnt1 = 0, cnt2 = 0;
    for(int i = l; i <= mid; i++)
    {
        if(s[i] != ch) cnt1++;
    }
    for(int i = mid + 1; i <= r; i++)
    {
        if(s[i] != ch) cnt2++;
    }

    int x = get(s, mid + 1, r, ch + 1);
    int y = get(s, l, mid, ch + 1);
    return min(cnt1 + x, cnt2 + y);
}

void solve()
{
    int n; string s;
    cin >> n >> s;
    cout << get(s, 0, n - 1, 'a') << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
