#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> ss(1e6 + 10);
void sieve()
{
    for(int i = 1; i <= 1e6 + 9; i++) ss[i] = i;
    for(int i = 2; i * i <= 1e6 + 9; i++)
    {
        if(ss[i] == i)
        {
            for(int j = i * i; j <= 1e6 + 9; j += i)
            {
                if(ss[j] == j) ss[j] = i;
            }
        }
    }
    //for(int i = 2; i <= 20; i++) cout << "i : " << i << " " << ss[i] << endl;
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    for(int e, i = 0; i < n; i++)
    {
        cin >> e;
        while(e != 1)
        {
            cnt[ss[e]]++;
            e /= ss[e];
        }
    }
    for(auto e : cnt)
    {
        //cout << "(" << e.first << " " << e.second << ")";
        if(e.second % n != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--) solve();
}
