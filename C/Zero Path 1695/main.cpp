#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 7;

int a[N][N];
int maxi[N][N];
int mini[N][N];


void bruteforcesolve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<set<int>>> possible(n, vector<set<int>>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int curr;
            cin >> curr;
            if(i == 0 && j == 0)
            {
                possible[i][j].insert(curr);
                continue;
            }

            if(j > 0)
            {
                for(auto x : possible[i][j - 1]) possible[i][j].insert(x + curr);
            }
            if(i > 0)
            {
                for(auto x : possible[i - 1][j]) possible[i][j].insert(x + curr);
            }

            cout << "[" << i << "," << j << "]: ";
            for(auto x : possible[i][j]) cout << x << " "; cout << endl;
        }
    }


}


void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    maxi[0][0] = mini[0][0] = a[0][0];

    for(int j = 1; j < m; j++) maxi[0][j] = mini[0][j] = maxi[0][j - 1] + a[0][j];
    for(int j = 1; j < n; j++) maxi[j][0] = mini[j][0] = maxi[j - 1][0] + a[j][0];

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            maxi[i][j] = max(maxi[i - 1][j], maxi[i][j - 1]) + a[i][j];
            mini[i][j] = min(mini[i - 1][j], mini[i][j - 1]) + a[i][j];
        }
    }

    if(maxi[n - 1][m - 1] < 0 || mini[n - 1][m - 1] > 0 || (n + m) % 2 == 0) cout << "NO" << endl;
    else cout << "YES" << endl;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) bruteforcesolve();
}
