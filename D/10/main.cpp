#include <bits/stdc++.h>

using namespace std;

vector<int> getparent(vector<int>& c, vector<int>& p, int mark)
{
    vector<int> ans;
    while(mark != -1)
    {
        ans.push_back(c[mark]);
        mark = p[mark];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> getlics(vector<int>& c)
{
    int inf = INT_MAX;
    int n = c.size();
    vector<int> p(n, -1), indx(n, -1), b(n + 1, inf);
    b[0] = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int l = 1, r = n;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(c[i] > b[mid - 1] && c[i] < b[mid])
            {
                b[mid] = c[i];
                indx[mid] = i;
                p[i] = indx[mid - 1];
                break;
            }
            else if(c[i] < b[mid - 1]) r = mid - 1;
            else l = mid + 1;
        }
    }
    int mark = -1;
    for(int i = 0; i <= n; i++)
    {
        if(b[i] < inf) mark = indx[i];
    }

    vector<int> ans = getparent(c, p, mark);
    return ans;
}

vector<int> getlcs(vector<int>& a, vector<int>& b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    //for(int i = 1; i <= n; i++)
    {
        //for(int j = 1; j <= m; j++) cout << dp[i][j] << " "; cout << endl;
    }
    int i = n, j = m;
    vector<int> ans;
    while(i > 0 && j > 0)
    {
        //cout << i << " " << j << endl;
        if(a[i - 1] == b[j - 1])
        {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

void solve()
{
    int n1, n2;
    cin >> n1;
    vector<int> a(n1);
    for(int i = 0; i < n1; i++) cin >> a[i];
    cin >> n2;
    vector<int> b(n2), p(n2, -1), c(n2, 0);
    for(int i = 0; i < n2; i++) cin >> b[i];

    for(int i = 0; i < n1; i++)
    {
        int curr = 0;
        int parent = -1;
        for(int j = 0; j < n2; j++)
        {
            if(a[i] == b[j])
            {
                if(c[j] < curr + 1)
                {
                    c[j] = curr + 1;
                    p[j] = parent;
                }
            }
            if(a[i] > b[j])
            {
                if(curr < c[j])
                {
                    parent = j;
                    curr = c[j];
                    //if(i == n1 - 1 && j == 1)cout << i << " " << j << " " << parent;
                }
            }
        }
    }
    //for(auto e : c) cout << e << " "; cout << endl;
    //for(auto e : p) cout << e << " "; cout << endl;
    int maxi = 0, mark = -1;
    for(int i = 0; i < c.size(); i++)
    {
        if(c[i] > maxi)
        {
            maxi = c[i];
            mark = i;
        }
    }
    vector<int> ans = getparent(b, p, mark);
    cout << ans.size() << endl;
    for(auto e : ans) cout << e << " "; cout << endl;

}

int main()
{
    solve();
}
