#include <bits/stdc++.h>

using namespace std;

bool check(int seg, string s)
{
    int cnta = 0, cntb = 0, cntc = 0;
    int l = 0, r = 0;
    for(; r < seg; r++)
    {
        if(s[r] == 'a') cnta++;
        else if(s[r] == 'b') cntb++;
        else cntc++;
    }
    if(cnta > cntb && cnta > cntc) return true;
    for(r = seg; r < (int)s.size(); r++, l++)
    {
        if(s[r] == 'a') cnta++;
        else if(s[r] == 'b') cntb++;
        else cntc++;

        if(s[l] == 'a') cnta--;
        else if(s[l] == 'b') cntb--;
        else cntc--;
        if(cnta > cntb && cnta > cntc) return true;
    }
    return false;
}


void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = -1;
    for(int seg = 2; seg <= 7; seg++)
    {
        if(seg == 5 || seg == 6 || seg > n) continue;
        if(check(seg, s) == true)
        {
            ans = seg;
            break;
        }
    }
    cout << ans << endl;
}


int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
