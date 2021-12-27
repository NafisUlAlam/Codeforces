#include<bits/stdc++.h>
#define ull unsigned long long


using namespace std;

vector<ull> p;
vector<ull> q;
set<ull> r;
ull n;








void solve()
{


    cin >> n;
    p.clear(); r.clear();
    for (int i = 1; i <= n; i++) r.insert(i);

    for(int i = 1; i <= n; i++)
    {
        ull v;
        cin >> v;
        if(r.find(v) != r.end()) r.erase(v);
        else p.push_back(v);
    }

    if (p.size() > 0)sort(p.begin(),p.end());
    if (p.size() > 0)reverse(p.begin(), p.end());


    bool flag  = true;
    if(p.size() > 0)
    {
        for (auto& pelem : p)
        {
            auto it = r.end();
            it--;
            ull relem = (*it);

            if(pelem <= 2 * relem)
            {
                flag = false; break;
            }
            else r.erase(it);
        }
    }
    if(flag == false ) cout << - 1 << endl;
    else cout << p.size() << endl;




}

int main()
{
    int t;
    cin >> t;
    while(t--) {solve();}


}
