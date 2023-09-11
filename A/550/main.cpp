#include <bits/stdc++.h>

using namespace std;

bool check(string& s, string t)
{
    int n = s.size(); bool f = false;
    for(int i = 0; i + 1 < n; i++)
    {
        if(f == false)
        {
            if(s.substr(i, 2) == t)
            {
                f = true;
                i++;
                reverse(t.begin(), t.end());
                //cout << t << endl;
            }
        }
        else
        {
            if(s.substr(i, 2) == t) return true;
        }
    }
    return false;
}

void solve()
{
    string s;
    cin >> s;
    if(check(s, "AB") || check(s, "BA")) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main()
{
    //while(1)
    solve();
}
