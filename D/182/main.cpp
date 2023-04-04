#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(string &s, int curr)
{
    for(int i = 0; i < curr; i++)
    {
        int j = i;
        while(j < (int)s.size() && s[i] == s[j]) j+= curr;
        if(j < (int)s.size()) return false;
    }
    return true;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    int ss = s.size(), ts = t.size();
    if(ss < ts) {swap(s, t); swap(ss, ts);}
    //if(ss % ts != 0) {cout << 0 << endl; return;}
    int i = 0, j = 0;
    while(i < ss)
    {
        if(s[i] == t[j]) {i++; j = (j + 1) % ts;}
        else {cout << 0 << endl; return;}
    }

    vector<int> divisors;
    for(i = 1; i * i <= ts; i++) if(ts % i == 0) {divisors.push_back(i); divisors.push_back(ts / i);}
    sort(divisors.begin(), divisors.end());
    int n = divisors.size(), mark = -1;
    for(i = 0; i < n; i++)
    {
        int curr = divisors[i];
        if(check(t, curr))
        {
            mark = curr;
            break;
        }
    }
    //cout << mark << endl;
    if(mark == -1) {cout << 0 << endl; return;}
    ll cnt = 0, mul = 1;
    while(mark * 1ll * mul <= 1ll * ts)
    {
        if(ss % (mark * mul) == 0 && ts % (mark * mul) == 0) cnt++;
        mul++;
    }
    cout << cnt << endl;
}

int main()
{
    int t = 1;
    //cin >> t;
    while(t--) solve();
}
