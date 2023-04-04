#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll x, vector<ll>& agiven, vector<ll>& abox, vector<ll>& a)
{
    vector<ll> box = abox;
    vector<ll> given = agiven;
    for(auto elem : a) box[elem] = x;
    //for(auto elem : given) cout << elem << " "; cout << endl;
    //for(auto elem : box) cout << elem << " "; cout << endl;
    for(ll i = 30; i >= 0; i--)
    {
        //cout << i << " " << box[i] << " " << given[i] << endl;
        if(box[i] < given[i]) return false;
        box[i] -= given[i];
        if(i >= 1)box[i - 1] += box[i] * 2ll;
        //for(auto elem : box) cout << elem << " "; cout << endl;
    }
    return true;
}

void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> a, given(31, 0), box(31, 0);
    ll i = 1, j = 0;
    while(i <= w)
    {
        if(i & w) a.push_back(j);
        j++;
        i = (i << 1);
    }
    //for(auto elem : a) cout << elem << " "; cout << endl;
    for(ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        ll p = (ll)log2(x);
        given[p]++;
    }
    //for(auto elem : given) cout << elem << " "; cout << endl;
    //for(auto elem : box) cout << elem << " "; cout << endl;
    ll l = 0, r = n, ans = r;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        //cout << "mid " << mid << endl;
        if(check(mid, given, box, a))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}

void solveGreedy()
{
    int n, W;
    cin >> n >> W;
    vector<int> a(20, 0);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[log2(x)]++;
    }
    //for(auto elem : a) cout << elem << " "; cout << endl;
    int height = 1, width = W;
    for(int i = 1; i <= n; i++)
    {
        bool found = false;
        int idx = -1;
        for(int j = 19; j >= 0; j--)
        {
            if(a[j] > 0 && (1 << j) <= width)
            {
                idx = j;
                found = true;
                break;
            }
        }

        if(found == false)
        {
            //cout << "cant put anymore remaining " << endl;
            height++;
            width = W;
            for(int j = 19; j >= 0; j--)
            {
                if(a[j] > 0 && (1 << j) <= width)
                {
                    idx = j;
                    found = true;
                    break;
                }
            }
        }
        a[idx]--;
        width -= (1 << idx);
        //cout << "found largest possible " << (1 << idx) << endl;
        //cout << "width remaining " << width << endl;
    }
    cout << height << endl;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}
