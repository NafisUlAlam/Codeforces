#include<bits/stdc++.h>
#define ll long long
using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;



bool check(ll mid, ll esz, ll odds_unused)
{
    ll numofeven = (esz - mid + 1) / 2 + 1;
    ll numofodd = numofeven * 1ll * 2;
    ll lastodd = odds_unused + (numofodd - 1) * 1ll * 2;
    return lastodd < mid;

}
ll findlastodd(ll mid, ll esz, ll odds_unused)
{
    ll numofeven = (esz - mid + 1) / 2 + 1;
    ll numofodd = numofeven * 1ll * 2;
    ll lastodd = odds_unused + (numofodd - 1) * 2;
    return lastodd;
}

void solve4()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n),ansvec;
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    for(int k = 1; k <= 3; k++)
    {

        ll odds_unused = 1;
        ll even = 0;

        if(k == 2)
        {
            a[n - 1] += 1;
            odds_unused = 3;
        }
        if(k == 3)
        {
            a[n - 1] += 1;
            even = 1;
        }


        for(int i = 0; i < n; i++) b[i] = a[n - 1] - a[i];
        //if(k == 1)for(auto elem : b) cout << elem << " "; cout << endl;



        for(int i = 0; i < n; i++)
        {
            if(b[i] % 2 == 1)
            {
                odds_unused += 2;
                b[i] = b[i] - 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(b[i] > 1)
            {
                even += b[i] / 2;
                b[i] -= (b[i] / 2) * 2;
            }
        }

        //for(auto elem : b) cout << elem << " ";
        //cout << odds_unused;
        //for(int i = 2; i <= even * 2; i += 2) evens.push_back(i);
        //for(int i = odds_unused; i <= even * 2; i += 2) odds.push_back(i);
        ll esz = even * 2;
        ll osz;
        if(odds_unused > esz) osz = 0;
        else osz = (esz - odds_unused + 1) / 2;

        //if(k == 3)cout << esz << " " << osz << endl;

        /*cout << "unused odd :"<<odds_unused << endl;
        cout << "odds: ";for(auto elem : odds) cout << elem << " " ; cout << endl;
        cout << "evens: ";for(auto elem : evens) cout << elem << " " ; cout << endl;*/

        if(esz == 0)
        {
            //if(odds_unused > 1) odds_unused -= 2;
            //else odds_unused -= 1;
            //cout << "ans ";
            //cout << odds_unused << endl;
            //return;
            if(odds_unused > 1)ansvec.push_back(odds_unused - 2);
            else ansvec.push_back(odds_unused - 1);
        }
        else
        {
            if(osz < 2)
            {
                //odds_unused -= 2;
                //cout << "ans ";
                //cout <<max(odds_unused, evens.back()) << endl;
                //return;
                ansvec.push_back(max(odds_unused - 2, esz));
            }
            else
            {
                //cout << "else" << endl;
                //int last_even_index = esz - 1;
                //int last_even = esz;
                //int first_odd_index = 0;
                //int first_odd = odds_unused;
                //int second_odd_index = 1;
                //int second_odd = odds_unused + 2;
                //int ans = 0;
                //while(second_odd < last_even)
                //{
                    //cout << first_odd << " " << second_odd << " " << last_even << endl;
                    //last_even_index--;
                    //last_even -= 2;
                    //first_odd_index += 2;
                    //first_odd += 4;
                    //second_odd_index += 2;
                    //second_odd += 4;

                    /*if(first_odd_index >= osz || second_odd_index >= osz)
                    {
                        break;
                    }*/
                    //last_even = evens[last_even_index];
                    //first_odd = odds[first_odd_index];
                    //second_odd = odds[second_odd_index];
                //}


                //second_odd -= 4;
                //ans = max(last_even, second_odd);

                //cout << "ans ";
                //cout << ans << endl;
                //ansvec.push_back(ans);


                ll hi = esz, lo = 2;
                while(hi - lo > 2)
                {
                    ll mid = (hi + lo) / 2;
                    if(mid % 2 == 1) mid -= 1;
                    if(check(mid, esz, odds_unused) == false) lo = mid + 2;
                    else hi = mid;
                }


                ll ans, ans2;
                if(check(lo, esz, odds_unused) == true)
                {
                    ans = findlastodd(lo,esz,odds_unused);
                    ans2 = lo - 2;
                    ans = max(ans, ans2);
                }
                else if(check(hi, esz, odds_unused) == true)
                {
                    ans = findlastodd(hi,esz,odds_unused);
                    ans2 = lo;
                    ans = max(ans, ans2);
                }
                else ans = hi;
                ansvec.push_back(ans);
                //cout << ans;

            }
        }

    }
    //for(auto elem : ansvec) cout << elem << " "; cout << endl;
    cout << min(ansvec[0], min(ansvec[1], ansvec[2])) << endl;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve4();

}
