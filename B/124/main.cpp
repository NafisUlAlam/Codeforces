#include <bits/stdc++.h>

using namespace std;

void permute(vector<vector<int>>& perms, vector<int>& perm, int pos, int n, vector<bool>& flags)
{
    if(pos == n)
    {
        perms.push_back(perm);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(flags[i] == false)
        {
            perm.push_back(i);
            flags[i] = true;
            permute(perms, perm, pos + 1, n, flags);
            perm.pop_back();
            flags[i] = false;
        }
    }
}
void solve()
{
    vector<vector<int>> perms;
    vector<int> perm;
    int n, k;
    cin >> n >> k;
    vector<bool>flags(k, false);
    permute(perms, perm, 0, k, flags);
    //for(auto elem : perms)
    {
        //for(auto e : elem) cout << e << " "; cout << endl;
    }
    vector<string> a(n);
    for(auto &e : a) cin >> e;
    int ans = INT_MAX;
    for(int i = 0; i < perms.size(); i++)
    {
        vector<int> b(n, 0);
        for(int j = 0; j < perms[i].size(); j++)
        {
            int indx = perms[i][j];
            for(int k = 0; k < n; k++)
            {
                b[k] = b[k] * 10 + (a[k][indx] - '0');
            }
        }
        sort(b.begin(), b.end());
        int diff = b.back() - b.front();
        ans = min(ans, diff);
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
