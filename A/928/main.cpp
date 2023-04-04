#include <bits/stdc++.h>

using namespace std;

void change(string& s)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(isupper(s[i])) s[i] = tolower(s[i]);
        if(s[i] == '0') s[i] = 'o';
        if(s[i] == '1' || s[i] == 'i' || s[i] == 'l') s[i] = 'i';
    }
}

void solve()
{
    int n; string s;
    cin >> s >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {cin >> a[i]; change(a[i]);}
    change(s);
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        string curr = a[i];
        //cout << curr << " " << s << endl;
        if(curr.size() != s.size()) continue;
        int j;
        for(j = 0; j < s.size(); j++)
        {
            if(curr[j] == s[j] || (curr[j] == '1' && (s[j] == '1' || s[j] == 'l' || s[j] == 'i') )
               || (s[j] == '1' && (curr[j] == '1' || curr[j] == 'l' || curr[j] == 'i') ))continue;
            else break;
        }
        if(j == s.size()) {flag = true; break;}
    }
    if(flag) cout << "No" << endl;
    else cout << "Yes" << endl;
}

int main()
{
    int t = 1;
    while(t--)solve();
}
