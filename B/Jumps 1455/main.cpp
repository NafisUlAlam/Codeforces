#include <bits/stdc++.h>

using namespace std;

vector<int> a(int(1e6 + 1), 0);
void fillup()
{
    int i = 1, sum = 2;
    a[1] = 1;
    while(i < a.size())
    {
        int j = i + sum;
        for(int k = j; k >= j - sum + 1; k--)
        {
            if(k == j - 1) a[k] = sum + 1;
            else a[k] = sum;
        }
        i = j;
        sum++;
    }
    //for(int i = 0; i <= 21; i++) cout << a[i] << " "; cout << endl;
}

void solve()
{
    int x;
    cin >> x;
    cout << a[x] << endl;
}

void solve2()
{
    int s = 0, curr = 1, x;
    cin >> x;
    while(s < x)
    {
        s += curr++;
    }
    if(x == s - 1) cout << curr << endl;
    else cout << curr - 1 << endl;

}
int main()
{
   fillup();
   int t = 1;
   cin >> t;
   while(t--)
   {
       solve2();
   }
}
