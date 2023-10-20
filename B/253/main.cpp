#include <bits/stdc++.h>

using namespace std;

void solve()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    if(!out.is_open())
    {
        std::cerr << "Error: Unable to open the output file." << std::endl;
        return;
    }
    int n, cnt = 0, i = 0;
    vector<int> a;
    while(in >> n)
    {
        if(cnt == 0) a.resize(n);
        else {a[i] = n; i++;}
        cnt++;
    }
    in.close();
    int ans = INT_MIN;
    sort(a.begin(), a.end());
    //for(auto e : a) cout << e << " "; cout << endl;
    for(int j = 0; j < i; j++)
    {
      int rr = upper_bound(a.begin(), a.end(), a[j] * 2) - a.begin();
      ans = max(ans, rr - j);
    }
    out << i - ans << endl;;
    out.close();
}

int main()
{
    solve();
}
