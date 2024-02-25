#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;
const int mod = (int)1e9 + 7;
const int maxn = (int) 1e5 + 10;

vector<int> a(2e5 + 10, 0);
void pre()
{
    for(int i = 1; i < a.size(); i++)
    {
        int n = i;
        int sum = 0;
        while(n)
        {
            sum += n % 10;
            n /= 10;
        }
        a[i] = a[i - 1] + sum;
    }
}

void solve1926C()
{
    int n;
    cin >> n;
    cout << a[n] << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   cin >> t;
   pre();
   while(t--)
   {
      solve1926C();
   }
}
