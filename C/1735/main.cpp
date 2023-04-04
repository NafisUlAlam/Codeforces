#include <bits/stdc++.h>

using namespace std;

bool dfs(int curr, vector<int>& parent, vector<bool>& visited)
{
    visited[curr] = true;
    if(parent[curr] == -1) return true;
    if(visited[parent[curr]] == true) return false;
    return dfs(parent[curr], parent, visited);
}

void solve()
{
    int n, rem = 26;
    string s;
    cin >> n >> s;
    vector<int> parent(26, -1), available(26, 1);

    for(int i = 0; i < n; i++)
    {
        int curr = s[i] - 'a';
        if(parent[curr] == -1)
        {
            for(int j = 0; j < 26; j++)
            {
                if(curr == j || available[j] == 0) continue;
                parent[curr] = j;
                if(rem == 1) break;
                vector<bool> visited(26, false);
                if(dfs(curr, parent, visited))
                {
                    available[j] = 0;
                    rem--;
                    break;
                }
            }
        }
    }

    string t;
    for(int i = 0; i < n; i++) t.push_back(parent[s[i] - 'a'] + 'a');
    cout << t << endl;

}


int main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
}
