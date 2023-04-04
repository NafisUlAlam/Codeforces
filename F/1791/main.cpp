#include <bits/stdc++.h>

using namespace std;

int digitsum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    set<int> st;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st.insert(i);
    }

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int f, s;
            cin >> f >> s;
            auto it = st.lower_bound(f);
            if(it == st.end() || *it > s) continue;
            for(; it != st.end(); )
            {
                if(*it > s) break;
                else
                {
                    a[*it] = digitsum(a[*it]);
                    //cnt[*it]++;
                    if(a[*it] < 10)it = st.erase(it);
                    else it++;
                }
            }
        }
        else
        {
            int x;
            cin >> x;
            cout << a[x] << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}
