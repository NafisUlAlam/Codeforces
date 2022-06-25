#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;
const int mod = (int)1e9 + 7;
const int maxn = (int) 1e5 + 10;


int knapsack(vector<int>& wt, vector<int>& val, int w, int n, vector<vector<int>>&ans)
{
    if(n == 0 || w == 0) return 0;
    if(ans[n][w] != -1) return ans[n][w];
    
    if(wt[n - 1] <= w)
    {
        return ans[n][w] = max (val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, ans), 
        0 + knapsack(wt, val, w - 0, n - 1, ans));
    }
    else return ans[n][w] = 0 + knapsack(wt, val, w - 0, n - 1, ans);
}


int knapsackDP(vector<int>& wt, vector<int>& val, int capacity, int n, vector<vector<int>>& ans)
{
    //if(n == 0 || capacity == 0) return 0;
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
        {
            if(i == 0 || j == 0) ans[i][j] = 0;
        }
    }
    //if(ans[n][capacity] != -1) return ans[n][capacity];
    for(int i = 1; i < ans.size(); i++)
    {
        for (int j = 1; j < ans[0].size(); j++)
        {
            if(wt[i - 1] <= j)
            {
                //return ans[n][capacity] = max(val[n - 1] + knapsack(wt, val, capacity - wt[n - 1], n - 1, ans)
                //0 + knapsack(wt, val, capacity - 0, n - 1, ans));
                ans[i][j] = max(val[i - 1] + ans[i - 1][j - wt[i - 1]], 
                                        0 + ans[i - 1][j]);
            }
            else 
            {
                //return ans[n][capacity] = 0 + knapsack(wt, val, capacity - 0, n - 1, ans);
                ans[i][j] = 0 + ans[i - 1][j];
            }
            
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return ans[n][capacity];
}

void subsetgenerator2(vector<int>& given, int n, vector<int> subset, vector<vector<int>>& ans)
{
    if(n == 0)
    {
        ans.push_back(subset);
        return;
    }
    subsetgenerator2(given, n - 1, subset, ans);
    subset.push_back(given[n - 1]);
    subsetgenerator2(given, n - 1, subset, ans);
}

void subsetgenerator3withbacktrack(vector<int>& given, int n, vector<int>& subset, vector<vector<int>>& ans)
{
    if(n == 0)
    {
        ans.push_back(subset);
        return;
    }
    subsetgenerator3withbacktrack(given, n - 1, subset, ans);
    subset.push_back(given[n - 1]);
    subsetgenerator3withbacktrack(given, n - 1, subset, ans);
    subset.pop_back();
}



void subsetWithKElements(vector<int>&given, int k, vector<vector<int>>& ans)
{
    int n = given.size();
    for(int i = 1; i < pow(2, n); i++)
    {
        int z = i;
        vector<int> binary;
        while(z > 0)
        {
            int rem = z % 2;
            binary.push_back(rem);
            z = z / 2;
        }
        int p = n - binary.size();

        for(int j = 1; j <= p; j++) binary.push_back(0);
        reverse(binary.begin(), binary.end());

        //for(auto elem : binary) cout << elem << " "; cout << endl;
        int cnt = 0;

        for(int j = 0; j < binary.size(); j++)
        {
            if(binary[j] == 1) cnt++;
        }
        //cout << cnt << endl;
        if(cnt == k)
        {
            vector<int> subset;
            for(int j = 0; j < binary.size(); j++)
            {
                if(binary[j] == 1) subset.push_back(given[j]);
            }
            ans.push_back(subset);
        }
        //binary.clear();
    }
}
void power(int a, int n)
{
    int res = 1;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            res *= a;
            n--;
        }
        else 
        {
            a = a * a;
            n = n / 2;
        }
    }
    cout << res << endl;
}

void power(ll a, ll n, ll p)
{
    ll res = 1;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            res = (res * a) % p;
            n--;
        }
        else
        {
            a = (a * a) % p;
            n /= 2;
        }
    }
    cout << res << endl;
}


bool isPrime(int n)
{
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

void primefact(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            int cnt = 0;
            while(n % i == 0)
            {
                n = n / i;
                cnt++;
            }
            cout << i << " ^ " << cnt << endl;
        }
    }
    if(n > 1) cout << n << " ^ " << 1 << endl;
}


void eulertotientfunction(int n)
{
    int res = n;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res /= i;
            res *= (i - 1);
        }
        while(n%i == 0) n /= i;
    }
    if(n > 1)
    {
        res /= n;
        res *= n - 1;
    }
    cout << res << endl;
}


void sieveprimefact()
{
    vector<int> a(51, -1);
    a[0] = a[1] = 0;
    for(int i = 2; i < 51; i++)
    {
        if(a[i] == -1)
        {
            for(int j = i; j < 51; j += i)
            {
                if(a[j] == -1) a[j] = i;
            }
        }
    }
    
    
    int n = 40;
    while(n > 1)
    {
        cout << a[n] << " ";
        n /= a[n];
    }
}

void matrixmultiplication()
{
    int a[2][5] = {{1,2,3,4,5}, {4,5,6,7,8}};
    int b[5][3] = {{15,14,13}, {12,11,10}, {9,8,7}, {6,5,4}, {3,2,1}};
    int c[2][3] = {0};
    
    for(int arow = 0; arow < 2; arow++)
    {
        for(int bcol = 0; bcol < 3; bcol++)
        {
            for(int common = 0; common < 5; common++)
            {
                c[arow][bcol] += a[arow][common] * b[common][bcol];
            }
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++) cout << c[i][j] << " ";
        cout << endl;
    }
    
}

void matrixpower(int a[2][5], int n)
{
    int I[2][2];
    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if(i == j) I[i][j] = 1;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        matrixmultiplication();
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) a[i][j] = I[i][j];
    }
    
}


void gcdquery()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0), suf(n + 2, 0);
    for(int i = 1; i < n + 1; i++) cin >> a[i];
    for(int i = 1; i < n + 1; i++) pre[i] = __gcd(pre[i - 1], a[i]);
    for(int i = n; i >= 1; i--) suf[i] = __gcd(suf[i + 1], a[i]);
    for(auto elem : pre) cout << elem << " "; cout << endl;
    for(auto elem : suf) cout << elem << " "; cout << endl;
    
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << __gcd(pre[l - 1], suf[r + 1]) << endl;
    }
    
}


ll maxmin(ll n)
{
    ll maxi = 0, mini = 10;
    while(n > 0)
    {
        ll curr = n % 10;
        maxi = max(maxi, curr);
        mini = min(mini, curr);
        n /= 10;
    }
    return maxi * 1ll * mini;
}

int get_bit_count(ll n)
{
    return __builtin_popcountll(n);
}


int get_first_bit_index(ll n)
{
    return 63 - __builtin_clzll(n);
}
struct stack
{
    vector<char> a;
    vector<int> flags = vector<int> (3, 0);
    void reset()
    {
        a.clear();
        flags.clear();
    }
    bool empty()
    {
        return a.empty();
    }
    int size()
    {
        return a.size();
    }
    void push(char c)
    {
        a.push_back(c);
        flags[(c - '0') - 1]++;
    }
    
    char pop()
    {
        if(a.size() > 0)
        {
            char c = a.back();
            flags[(c - '0') - 1]--;
            a.pop_back();
            return c;
        }
    }
    
};



bool good(::stack& s1, ::stack& s2)
{
    bool flag = true;
    for(int i = 0; i <s2.flags.size(); i++)
    {
        flag &= s1.flags[i] || s2.flags[i];
    }
    return flag;
}

void add(char c, ::stack& s1, ::stack& s2 )
{
    s2.push(c);
}

void remove(char c, ::stack& s1, ::stack& s2 )
{
    if(s1.size() == 0)
    {
        while(!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}


vector<ll> fact;
vector<ll> po;



void fill()
{
    fact.push_back(1);
    po.push_back(1);
    int i = 1;
    while(fact.back() <  1e13)
    {
        fact.push_back(fact.back() * i * 1ll);
        i++;
    }
    while(po.back() <  1e13)
    {
        po.push_back(po.back() * 2 * 1ll);
    }
    fact.pop_back();
    po.pop_back();
    //cout << fact.back() << " " << po.back() << endl;
}

bool sortbysec(pair<pair<int, int>,int> a, pair<pair<int, int>, int> b)
{
    return a.first.second < b.first.second;
}

int bestCandidate(vector<int>&b, int curr)
{
    int bst = INF + 10, pos = -1;
    for(int i = 0; i < b.size(); i++)
    {
        if(bst > abs(curr - b[i]))
        {
            bst = abs(curr - b[i]); pos = i;
        }
    }
    return pos;
}


void dfs(int root, vector<int>& d, vector<bool>& visited, vector<vector<int>>& a)
{
    visited[root] = true;
    for(auto child : a[root])
    {
        d[child] = d[root] + 1;
        dfs(child, d, visited, a);
    }
}


void solve()
{
   int n;
   cin >> n;
   vector<vector<int>> a;
   a.resize(n + 1);
   vector<int> d(n + 1, 0);
   vector<bool> visited(n + 1, false);
   for(int i = 1; i <= n; i++)
   {
       int x; cin >> x;
       if(x == -1) continue;
       a[x].push_back(i);
   }
   
   for(int i = 1; i <= n; i++)
   {
       if(visited[i] == false) dfs(i, d, visited, a);
   }
   
   sort(d.begin(), d.end());
   cout << d.back() + 1 << endl;
}




void solve2()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0, seg = -1;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += a[j];
            if(sum % x != 0)
            {
                seg = max(seg, (ll)j - i + 1);
            }
            
        }
    }
    cout << seg << endl;
}

void solve3()
{
    int n, gr = 0;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int curr = 0;
    for(int i = 0; i < n; i++)
    {
        curr++;
        if(curr == a[i])
        {
            gr++; curr = 0;
        }
    }
    cout << gr << endl;
}


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

void search()
{
    int esz = 20, odds_unused = 21;
    int hi = esz, lo = 2;
    while(hi - lo > 2)
    {
        int mid = (hi + lo) / 2;
        if(mid % 2 == 1) mid -= 1;
        if(check(mid, esz, odds_unused) == false) lo = mid + 2;
        else hi = mid;
    }
    
    int ans, ans2;
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
    cout << ans;

}


void solve4()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> c(26, 0);
    for(int i = 0; i < k; i++) 
    {
        char ch;
        cin >> ch;
        c[ch - 'a'] = 1;
    }
    
    std:: stack<char> st;
    
    int spcnt = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(c[s[i] - 'a']) spcnt++;
    }
    
    string s2 = "";
    int cnt = 0;
    while(spcnt > 1)
    {
        
        for(int i = 0; i < s.size(); i++)
        {
            if(st.empty() || c[s[i] - 'a'] == 0) st.push(s[i]);
            else
            {
                st.pop();
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            s2 += st.top(); st.pop();
        }
        reverse(s2.begin(), s2.end());
        s = s2;
        spcnt = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(c[s[i] - 'a']) spcnt++;
        }
        cnt++;
    }
}

ll merge(vector<ll>& a, vector<ll>& temp, ll left, ll mid, ll right)
{
    ll cnt = 0, i = left, j = mid, k = left;
    while(i <= mid - 1 && j <= right)
    {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else { cnt += mid - i; temp[k++] = a[j++];}
    }
    
    while(i <= mid - 1) temp[k++] = a[i++];
    while(j <= right) temp[k++] = a[j++];
    
    for(ll i = left; i <= right; i++) a[i] = temp[i];
    return cnt;
}




ll mergesort(vector<ll>& a, vector<ll>& temp, ll left, ll right)
{
    ll mid, cnt = 0;
    if(right - left > 0)
    {
        mid = (right + left) / 2;
        cnt += mergesort(a, temp, left, mid);
        cnt += mergesort(a, temp, mid + 1, right);
        cnt += merge(a, temp, left, mid + 1, right);
    }
    return cnt;
    
}


ll countInversions(vector<ll>&a, ll n)
{
    ll cnt = 0;
    vector<ll> temp(n);
    cnt = mergesort(a, temp, 0, n - 1);
    return cnt;
}

bool check(ll mid, vector<ll>& a, ll k)
{
    for(ll i = 0; i < a.size(); i++)
    {
        ll sum = 0;
        for(ll j = i; j < i + mid; j++)
        {
            sum += a[j];
        }
        if(sum <= k) return true;
    }
    return false;
}




vector<vector<int>>g;
vector<pair<int, int>> color;

void dfs(int v, int par = -1)
{
    //cout << "dfs";
    for(auto child : g[v])
    {
        //cout << child << " " << v << " "; cout << endl;
        if(child == par || child == v) continue;
        dfs(child, v);

        color[v].first += color[child].first;
        color[v].second += color[child].second;
    }
}


void graphproblem()
{
    int n;
    cin >> n;
    g.clear();
    g.assign(n + 1, {});
    color.clear();
    color.assign(n + 1, {0 , 0});
    for(int i = 2; i <= n ; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

//    for(auto elem : g)
//    {
//        for(auto e : elem) cout << e << " ";
//        cout << endl;
//    }

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'W') color[i + 1].first = 1;
        else color[i + 1].second = 1;
    }

    //for(auto e : color) cout << "( "<<e.first << " " << e.second <<" )"; cout << endl;

    dfs(1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(color[i].first == color[i].second) cnt++;
    }
    cout << cnt << endl;
}


vector<int> parent(maxn), sizes(maxn), ranks(maxn);


void makeset(int v)
{
    parent[v] = v;
    ranks[v] = 0; 
    //sizes[v] = 1;
}

int findparent(int v)
{
    if(parent[v] == v) return v;
    return parent[v] = findparent(parent[v]);
}

void unionset(int u, int v)
{
    u = findparent(u);
    v = findparent(v);
    if(u == v) return;
    if(ranks[u] < ranks[v]) swap(u, v);
    parent[v] = u;
    if(ranks[u] == ranks[v]) ranks[u]++;
    
    /*
    if(sizes[u] < sizes[v]) swap(u, v);
    parent[v] = u;
    sizes[u] += sizes[v];
    */
    
}


void solve5()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    
    vector<int> bad;
    
    for(int i = 0; i < n; i++)
    {
        vector<int> b = a[i];
        sort(b.begin(), b.end());
        for(int j = 0; j < m; j++)
        {
            if(b[j] != a[i][j]) bad.push_back(j);
        }
        
        if(bad.size() > 0) break;
    }
    
    
    if(bad.size() == 0) 
    {
        cout << 1 << " " << 1 << endl;
        return;
    }
    
    if(bad.size() >= 3)
    {
        cout << -1 << endl;
        return;
    }
    
    
    if(bad.size() < 3)
    {
        for(int i = 0; i < n; i++) swap(a[i][bad[0]], a[i][bad[1]]);
    }
    
    
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(a[i][j] < a[i][j - 1])
            {
                cout << -1 <<endl;
                return;
            }
        }
    }
    
    cout << bad[0] + 1 << " " << bad[1] + 1 << endl;
    return;
}





int bubblesort(vector<int>& a, vector<int>& b, vector<pair<int, int>>& ans)
{
    int moves = 0;
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(a[j] > a[j + 1] || b[j] > b[j + 1]) 
            {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                ans.push_back({j, j + 1});
                moves++;
            }
        }
    }
    return moves;
}


void solve7()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    vector<pair<int, int>> ans;
    int moves = bubblesort(a, b, ans);
    bool flag = true;
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i + 1] || b[i] > b[i + 1]) flag &= false;
        else flag &= true;
    }
    
    if(flag == false) cout << -1 << endl;
    else
    {
        cout << moves << endl;
        for(auto elem : ans)
        {
            cout << elem.first + 1<< " " << elem.second + 1<< endl;
        }
    }
}



int merge2(vector<pair<int, int>>&c,int left, int mid, int right, vector<pair<int, int>>& temp, vector<pair<int,int>>& ans)
{
    //cout <<"merge2 "<< left<<" " << right << endl;
    int i, j, k, moves = 0;
    i = left, j = mid, k = left;
    while(i <= mid - 1 && j <= right)
    {
        if(c[i].first > c[j].first || (c[i].first == c[j].first && c[i].second > c[j].second ))
        {
            for(int p = j; p >= k + 1; p--)
            {
                ans.push_back({p, p - 1});
                moves++;
            }
            temp[k++] = c[j++];
        }
        else 
        {
            temp[k++] = c[i++];
        }
    }
    while(i <= mid - 1) temp[k++] = c[i++];
    while(j <= right) temp[k++] = c[j++];
    
    for(int i = left; i <= right; i++) c[i] = temp[i];
    return moves;
}

int mergesort2(vector<pair<int, int>>&c,int left, int right, vector<pair<int, int>>& temp, vector<pair<int,int>>& ans)
{
    //cout <<"sort2 "<< left <<" " << right  << endl;
    int moves = 0, mid;
    if(right - left > 0)
    {
        mid = (left + right) / 2;
        moves += mergesort2(c, left, mid, temp, ans);
        moves += mergesort2(c, mid + 1, right,temp, ans);
        moves += merge2(c, left, mid + 1, right, temp, ans);
    }
    return moves;
}

int mergesort2util(vector<pair<int, int>>&c, vector<pair<int,int>>& ans)
{
    //cout <<"util" << endl;
    int n = c.size();
    vector<pair<int, int>> temp(n);
    return mergesort2(c, 0, n - 1, temp, ans);
}


void solve1685B()
{
    ll n, a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    if(count(s.begin(), s.end(), 'A') != a + c + d)
    {
        cout <<"NO" << endl; return;
    }
    
    n = a + b + 2 * c + 2 * d;
    s += string(1, s[n - 1]);
    
    string curr = string(1, s[0]);
    vector<ll> AB, BA;
    ll commoncount = 0;
    
    for(ll i = 1; i <= n; i++)
    {
        if(s[i] == s[i - 1])
        {
            if(curr.size() == 1)
            {
                
            }
            else if(curr.size() & 1)
            {
                commoncount += curr.size() / 2;
            }
            else
            {
                if(curr[0] == 'A') AB.push_back(curr.size() / 2);
                else BA.push_back(curr.size() / 2);
            }
            curr = "";
        }
        curr.push_back(s[i]);
    }
    
    sort(AB.begin(), AB.end());
    sort(BA.begin(), BA.end());
    
    ll cntAB = 0, cntBA = 0, commoncountleft = commoncount;
    
    
    for(auto &x : AB)
    {
        ll req = c - cntAB;
        if(req >= x)
        {
            cntAB += x;
            x = 0;
        }
        else
        {
            cntAB += req;
            x -= req;
        }
    }
    
    for(auto &x : BA)
    {
        ll req = d - cntBA;
        if(req >= x)
        {
            cntBA += x;
            x = 0;
        }
        else
        {
            cntBA += req;
            x -= req;
        }
    }
    
    if(cntAB < c)
    {
        ll required = c - cntAB;
        cntAB += min(required, commoncountleft);
        commoncountleft -= min(required, commoncountleft);
        required = c - cntAB;
        if(required > 0)
        {
            for(auto &x : BA)
            {
                if(x == 0) continue;
                ll req = c - cntAB;
                if(req >= x - 1)
                {
                    cntAB += x - 1;
                    x -= x;
                }
                else
                {
                    cntAB += req;
                    x -= req + 1;
                }
            }
        }
    }
    
    if(cntBA < d)
    {
        ll required = d - cntBA;
        cntBA += min(required, commoncountleft);
        commoncountleft -= min(required, commoncountleft);
        
        required = d - cntBA;
        if(required > 0)
        {
            for(auto &x : AB)
            {
                if(x == 0) continue;
                ll req = d - cntBA;
                if(req >= x - 1)
                {
                    cntBA += x - 1;
                    x -= x;
                }
                else
                {
                    cntBA += req;
                    x -= req + 1;
                }
            }
        }
    }
    if(cntAB >= c && cntBA >= d) cout << "YES" << endl;
    else cout << "NO" << endl;
}


void solve1697C()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string s2, t2;
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] != 'b') s2.push_back(s[i]);
        if(t[i] != 'b') t2.push_back(t[i]);
    }
    //cout << s2 << endl << t2 <<endl;
    if(s2 != t2) {cout << "NO" << endl; return;}
    
    vector<int>saindx, taindx;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'a') saindx.push_back(i);
        if(t[i] == 'a') taindx.push_back(i);
    }
    //for(auto elem : saindx) cout << elem <<" "; cout << endl;
    //for(auto elem : taindx) cout << elem <<" "; cout << endl;
    
    for(int i = 0; i < saindx.size(); i++)
    {
        if(saindx[i] > taindx[i])
        {
            cout << "NO" << endl; return;
        }
    }
    
    vector<int>scindx, tcindx;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'c') scindx.push_back(i);
        if(t[i] == 'c') tcindx.push_back(i);
    }
    //for(auto elem : scindx) cout << elem <<" "; cout << endl;
    //for(auto elem : tcindx) cout << elem <<" "; cout << endl;
    
    for(int i = 0; i < scindx.size(); i++)
    {
        if(scindx[i] < tcindx[i])
        {
            cout << "NO" << endl; return;
        }
    }
    cout << "YES" << endl;
}

bool targetsum(vector<int>& a, int sum, int n, vector<vector<int>>& ans) 
{
    if(sum == 0) return true;
    if(n == 0 && sum > 0) return false;
    
    if(ans[n][sum] != -1) return ans[n][sum];
    
    if(a[n - 1] <= sum)
    {
        return ans[n][sum] = targetsum(a, sum - a[n - 1], n - 1, ans) || targetsum(a, sum, n - 1, ans);
    }
    else
    {
        return ans[n][sum] = targetsum(a, sum, n - 1, ans);
    }
}


void solve1527B1()
{
    int n;
    cin >> n; 
    string s;
    cin >> s;
    ll cnt = count(s.begin(), s.end(), '0');
    if(cnt == 1 || cnt % 2 == 0) cout << "BOB" << endl;
    else cout << "ALICE" << endl;
    
}

void solve1674E()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    int ans = INF;
    for(int i = 0; i <= n - 3; i++)
    {
       int currans = (a[i] + a[i + 2] + 1) / 2;
       ans = min(ans, currans);
    }
    
    for(int i = 0; i <= n - 2; i++)
    {
       int x = max(a[i], a[i + 1]);
       int y = min(a[i], a[i + 1]);
       if(2 * y <= x)
       {
          int currans = (x + 1) / 2;
          ans = min(currans, ans);
       }
       else
       {
          int currans = x - y;
          x = 2 * y - x;
          y = x;
          currans += (x * 2 + 2) / 3;
          ans = min(ans, currans);
       }
    }
    sort(a.begin(), a.end());
    int currans = (a[0] + 1) / 2 + (a[1] + 1) / 2;
    ans = min(currans, ans);
    cout << ans << endl;

}


void solve1406B()
{
   ll n;
   cin >> n;
   vector<int> a(n);
   for(auto &e : a) cin >> e;
   sort(a.begin(), a.end());
   ll ans = -1e18;
   for(int i = 0; i <= 5; i++)
   {
      int ee = (n - 1 + i) % n;
      int dd = (n - 2 + i) % n;
      int cc = (n - 3 + i) % n;
      int bb = (n - 4 + i) % n;
      int aa = (n - 5 + i) % n;
      ll curr = a[ee] * 1ll * a[dd] * a[cc] * a[bb] * a[aa];
      ans = max(ans, curr);
   }
   cout << ans << endl;

}

void solve1692F()
{
   int n; 
   cin >> n;
   vector<int> cnt(10, 0);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      cnt[x % 10]++;
   }
   
   vector<int> a;
   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < min(3, cnt[i]); j++) a.push_back(i);
   }
   
   int sz = a.size();
   for(int i = 0; i < sz; i++)
   {
      for(int j = i + 1; j < sz; j++)
      {
         for(int k = j + 1; k < sz; k++)
         {
            if((a[i] + a[j] + a[k]) % 10 == 3) 
            {
               cout << "YES" << endl;
               return;
            }
         }
      }
   }
   cout <<"NO" << endl;
}

void solve1692G()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n), b(n - 1, 0), pref(n - 1, 0);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i <= n - 2; i++)
   {
      if(a[i] < 2 * a[i + 1]) b[i] = 1;
      else b[i] = 0;
   }
   
   //prefix sum
   pref[0] = b[0];
   for(int i = 1; i <= n - 2; i++) pref[i] = pref[i - 1] + b[i];
   
   int ans = 0;
   for(int i = 0; i <= n - k - 1; i++)
   {
      if(i == 0 && pref[i + k - 1] == k) ans++; 
      else if(pref[i + k - 1] - pref[i - 1] == k) ans++;
   }
   
   cout << ans << endl;
   
   //sliding window
   /*int curr = 0, res = 0;
   for(int i = 0; i < k; i++)
   {
      curr += b[i];
   }
   
   if(curr == k) res++;
   for(int i = k, j = 0; i <= n - 2; i++)
   {
      curr += b[i];
      curr -= b[j++];
      if(curr == k) res++;
   }
   cout << res << endl;*/
}

void solve1694B()
{
   int n;
   cin >> n;
   vector<int> a;
   string s;
   cin >> s;
   for(int i = 0; i <= n - 2; i++)
   {
      if(s[i] != s[i + 1]) a.push_back(1);
      else a.push_back(0);
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   ll cnt = ((n + 1) * 1ll * n) / 2;
   
   for(int i = 0; i < a.size(); i++)
   {
      if(a[i] == 1) continue;
      cnt--;
      cnt = cnt - i;
   }
   cout << cnt << endl;
}

void solve1694A()
{
   int zeros, ones;
   cin >> zeros >> ones;
   string s;
   int diff = abs(zeros - ones);
   if(diff > min(zeros, ones))
   {
      if(zeros < ones)
      {
         s += string(zeros, '0');
         s += string(ones, '1');
      }
      else
      {
         s += string(ones, '1');
         s += string(zeros, '0');
      }
   }
   else if(diff == 0)
   {
      for(int i = 1; i <= zeros + ones; i++)
      {
         if(i % 2 == 1) s += '1';
         else s += '0';
      }
   }
   else
   {
     while(zeros > 0 && ones > 0)
      {
         if(zeros >= diff)
         {
            s += string(diff, '0');
            zeros -= diff;
         }
         else
         {
            s += string(zeros, '0');
            zeros = 0;
         }
         
         if(ones >= diff)
         {
            s += string(diff, '1');
            ones -= diff;
         }
         else
         {
            s += string(ones, '1');
            ones = 0;
         }
         
      }
      if(zeros > 0) {s+= string(zeros, '0');}
      if(ones > 0) {s += string(ones, '1');}
   }
   cout << s << endl;
}
void solve1695B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   int mn = INT_MAX;
   int mnindx = -1;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] < mn)
      {
         mn = a[i];
         mnindx = i;
      }
   }
   if(n % 2 == 0)
   {
      if(mnindx % 2 == 0) cout << "Joe" << endl;
      else cout << "Mike" << endl;
   }
   else cout << "Mike" << endl;
}

void solve1692H()
{
   int n;
   cin >> n;
   vector<int>a(n);
   for(auto& e : a) cin >> e;
   vector<int>dp(n, 1);
   map<int, int> pos;
   int idx = -1, ma = 0;
   for(int i = 0; i < n; i++)
   {
      if(pos.count(a[i]))
      {
         dp[i] = max(dp[i], dp[pos[a[i]]] + 1 - (i - pos[a[i]] - 1));
      }
      if(dp[i] > ma)
      {
         ma = dp[i];
         idx = i;
      }
      pos[a[i]] = i;
   }
   
   int r = idx;
   int l = idx;
   int p = a[l];
   
   /*while(ma)
   {
      if(a[l] == p) ma--;
      else ma++;
      l--;
   }
   cout << p << " " << l + 2 << " " << r + 1 << endl;*/
   for(; l>= 0; l--)
   {
      if(dp[l] == 1 && a[l] == p) break;
   }
   
   cout << p << " " << l + 1 << " " << r + 1 << endl;
}

void solve1694C()
{
   ll n;
   cin >> n;
   vector<ll> a(n), pref(n, 0);
   int mark = -1;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] != 0) mark = i;
      if(i == 0) pref[i] = a[i];
      else pref[i] = pref[i - 1] + a[i];
   }
   for(int i = 0; i < n; i++)
   {
      if(pref[i] < 0) 
      {
         cout << "NO" << endl; 
         return;
      }
      if(pref[i] == 0)
      {
         while(i < n)
         {
            if(pref[i] != 0)
            {
               cout << "NO" << endl; return;
            }
            i++;
         }
      }
   }
   if(mark == -1 || pref[mark] == 0)cout << "YES" << endl;
   else cout << "NO" << endl;
   
}

void solve1700B()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   n = s.size();
   string fir = string(n, '9');
   //cout << fir << endl;
   string sec = string(n + 1, '1');
   string num1, num2;
   for(int i = n - 1; i >= 0; i--)
   {
      num1 += to_string((fir[i] - '0') - (s[i] - '0'));
   }
   reverse(num1.begin(), num1.end());
   int i = 0;
   while(num1[i] == '0')
   {
      i++;
   }
   if(i == 0) {cout << num1 << endl; return;}
   string s1 = "0";
   s1 += s;
   s = s1;
   n++;
   //cout << s << endl;
   int carry = 0;
   for(int i = n - 1; i >= 0; i--)
   {
      int fn = sec[i] - '0';
      int sn = (s[i] - '0') + carry;
      int add = 0;
      if(fn < sn)
      {
         fn += 10;
         add = fn - sn;
         carry = 1;
      }
      else
      {
         add = fn - sn;
         carry = 0;
      }
      num2 += to_string(add);
   }
   reverse(num2.begin(), num2.end());
   i = 0;
   while(num2[i] == '0') i++;
   num2 = num2.substr(i);
   cout << num2 << endl;
   
}

void solve1692E()
{
   int n, s;
   cin >> n >> s;
   vector<int> a;
   int sum = 0, mov = 0;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x == 1) a.push_back(i);
      sum += x;
   }
   //cout << "sum : " << sum << " s :"<< s << endl;
   //for(auto elem : a) cout << elem << " "; cout << endl;
   if(sum < s) cout << -1 << endl; 
   else if (sum == s) cout << 0 << endl;
   else
   {
      int left = 0, right = n - 1;
      int p = a.size();
      int i = 0, j = p - 1;
      int cleft = a[i], cright = a[j];
      while(sum > s)
      {
         if(left > right) break;
         
         int lmov = cleft - left + 1;
         int rmov = right - cright + 1;
         
         //cout << "right : "<< right << " cright :" << cright << endl;
         
         if(lmov < rmov)
         {
            mov += lmov;
            left = cleft + 1;
            cleft = a[++i];
         }
         else 
         {
            mov += rmov;
            right = cright - 1;
            cright = a[--j];
         }
         sum--;
      }
      cout << mov << endl;
   }
}

void solve1360D()
{
   int n, k;
   cin >> n >> k;
   vector<int> divisors;
   for(int i = 1; i * i<= n; i++)
   {
      if(n % i == 0) 
      {
         divisors.push_back(i);
         if(i != n / i) divisors.push_back(n / i);
      }
   }
   sort(divisors.begin(), divisors.end());
   //for(auto elem : divisors) cout << elem << " "; cout << endl;
   if(binary_search(divisors.begin(), divisors.end(), k))
   {
      cout << n / k << endl;
   }
   else
   {
      int indx = lower_bound(divisors.begin(), divisors.end(), k) - divisors.begin();
      k = divisors[--indx];
      cout << n / k << endl;
   }
}

void solve1647B()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> a(n, vector<int>(m));
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < m; j++) 
      {
         if(s[j] == '0') a[i][j] = 0;
         else a[i][j] = 1;
      }
   }
   
   for(int i = 0; i <= n - 2; i++)
   {
      for(int j = 0; j <= m - 2; j++)
      {
         int cnt = 0;
         for(int curr = i; curr <= i + 1; curr++)
         {
            for(int curr2 = j; curr2 <= j + 1; curr2++)
            {
               //cout << curr << " " << curr2 << endl;
               if(a[curr][curr2] == 1) cnt++;
               //cout << "cnt :" << cnt << endl;
            }
         }
         if(cnt == 3) 
         {
            cout << "NO" << endl;
            return;
         }
      }
   }
   cout << "YES" << endl;
}

void solve1637C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   bool allones = true;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   for(int i = 1; i <= n - 2; i++)
   {
      if(a[i] > 1) allones &= false;
   }
   if(allones == true || (n == 3 && a[1] % 2 == 1))
   {
      cout << -1 << endl;
      return;
   }
   
   ll mov = 0;
   for(int i = 1; i <= n - 2; i++)
   {
      mov += (a[i] + 1) / 2;
   }
   cout << mov << endl;
}

void solve1690E()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      ans += a[i] / k;
      a[i] %= k;
   }
   
   sort(a.begin(), a.end());
   int l = 0, r = n - 1;
   while(r - l > 0)
   {
      if(a[l] + a[r] >= k)
      {
         ans++; r--; l++;
      }
      else l++;
   }
   cout << ans << endl;
}


void solve1696B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   a.push_back(0);
   int l = 0, r = 0;
   int segs = 0;
   for(r = 0; r <= n; r++)
   {
      //cout << "entering r "<< r << endl;
      if(a[r] == 0)
      {
         if(a[l] != 0)
         {
            segs++;
         }
         while(r <= n && a[r] == 0)
         {
            r++;
         }
         //cout << r << endl;
         if(r > n) break;
         l = r;
         //r--;
      }
      
   }
   //if(l < n) segs++;
   //cout << segs << endl;
   cout << min(segs, 2) << endl;
}


void solve1696A()
{
   int n, z;
   cin >> n >> z;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   
   ll maxi = 0;
   ll prevmaxi = -1;
   ll prevz = -1;
   ll ind = -1;
   while(prevmaxi != maxi)
   {
      for(int i = 0; i < n; i++)
      {
         //cout << "maxi" << maxi << endl;
         //cout << "or : " << (a[i] | z) << endl;
         if((a[i] | z) > maxi)
         {
            maxi = a[i] | z;
            ind = i;
         }
      }
      //prevz = z;
      z = a[ind] & z;
      a[ind] = maxi;
      prevmaxi = maxi;
   }
   cout << maxi << endl;
}

int main()
{ 
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) 
    {
       //solve1692EFromPC();
       //solve1690E();
    }
}
