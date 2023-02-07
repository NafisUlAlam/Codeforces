#include <bits/stdc++.h>

using namespace std;


void solve()
{
    int n, n1;
    cin >> n;
    n1 = n;
    if(n % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }

    string bot, top, mid;
    while(n > 0)
    {
        int rem = n % 2;
        bot.push_back((rem + '0'));
        n /= 2;
    }
    reverse(bot.begin(), bot.end());
    int sz = bot.size();
    for(int i = 1; i <= sz; i++) top.push_back('1');
    for(int i = 0; i < sz; i++)
    {
        int x = ( (bot[i] - '0') ^ (top[i] - '0') );
        mid.push_back((x + '0'));
    }

    //cout << top << " " << mid << " " << bot << endl;
    int top1 = 0, mid1 = 0, mul = 1;
    for(int i = sz - 1; i >= 0; i--)
    {
        if(top[i] == '1') top1 += mul;
        if(mid[i] == '1') mid1 += mul;
        mul *= 2;
    }
    int mid2 = (top1 + mid1) / 2;
    int diff = mid2 - n1;
    //cout <<top1 << " " << mid1 << " " <<  diff << endl;
    if(diff < 0)
    {
        cout << -1 << endl;
        return;
    }
    int i = sz - 1;
    int cdiff = diff;
    while(diff > 0)
    {
        if(diff & 1)
        {
            if(mid[i] == '1')
            {
                mid[i] = '0';
                top[i] = '0';
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        diff = diff >> 1;
        i--;
    }
    cout << top1 - cdiff << " " << mid1 - cdiff << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
