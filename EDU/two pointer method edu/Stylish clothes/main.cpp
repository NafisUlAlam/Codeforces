#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<vector<int>> color(1e5 + 7);

    for(int i = 1; i <= 4; i++)
    {
        int n;
        cin >> n;
        for(int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if(color[x].size() == 0 || color[x].back() != i)color[x].push_back(i);

        }
    }
    //for(int i = 0; i <= 20; i++)
    {
        ////cout << " i : " << i << " its elements ";
        //for(int j = 0; j < color[i].size(); j++) cout << color[i][j] << " "; cout << endl;
    }
    int l = 1, r = 1, left, right, ans = INT_MAX;
    int shirt = 1, pant = 1, shoe = 1, cap = 1;
    for(r = 1; r < color.size(); r++)
    {
        for(auto elem : color[r])
        {
            if(elem == 1) shirt--;
            else if(elem == 2) pant--;
            else if(elem == 3) shoe--;
            else if(elem == 4) cap--;
        }
        while(shirt <= 0 && pant <= 0 && shoe <= 0 && cap <= 0)
        {
            if(shirt <= 0 && pant <= 0 && shoe <= 0 && cap <= 0)
            {
                if(r - l + 1 < ans)
                {
                    ans = r - l + 1;
                    left = l;
                    right = r;
                }
            }
            for(auto elem : color[l])
            {
                if(elem == 1) shirt++;
                else if(elem == 2) pant++;
                else if(elem == 3) shoe++;
                else if(elem == 4) cap++;
            }
            l++;

        }
    }
    //cout << left << " " << right << endl;
    vector<int> myans;
    for(int i = 1; i <= 4; i++)
    {
        bool f = false;
        for(int j = left; j <= right; j++)
        {
            for(auto elem : color[j])
            {
                if(elem == i)
                {
                    myans.push_back(j);
                    f = true;
                    break;
                }
            }
            if(f == true) break;
        }
    }
    for(auto elem : myans) cout << elem << " "; cout << endl;

}

int main()
{
    solve();
}
