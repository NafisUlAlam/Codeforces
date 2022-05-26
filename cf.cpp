#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;
const int mod = (int)1e9 + 7;
const int maxn = (int) 1e5 + 10;

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



void solve6()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<int> maxi, mini;

    for(int i = 0; i < (n + 1) / 2; i++) mini.push_back(a[i]);
    for(int i = (n + 1) / 2; i < n; i++) maxi.push_back(a[i]);

    vector<int> ans(n + 1);
    vector<bool> where(n + 1);
    int last = -1;
    for(int i = 2; i <= n; i += 2)
    {
        ans[i] = maxi[(i - 2) / 2];
        where[i] = true;
        last = i;
    }

    for(int i = 1; i <= n; i += 2)
    {
        ans[i] = mini[(i - 1) / 2];
        where[i] = false;
    }

    if(last == n) last -= 2;
    bool cur = true;

    for(int i = 2; i <= last; i+= 2)
    {
        if(ans[i - 1] < ans[i] && ans[i] > ans[i + 1]) cur &= true;
        else cur &= false;
    }
    if(ans[n - 1] < ans[n] && ans[n] > ans[1]) cur &= true;
    else cur &= false;
    if(ans[n] > ans[1] && ans[1] < ans[2]) cur &= true;
    else cur &= false;
    if(cur == false || (where[1] == false && where[n] == false))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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


void solve8()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> c(n);
    for(auto &e : a) cin >> e;
    for(auto &e : b) cin >> e;
    for(int i = 0; i < n; i++) c[i] = {a[i], b[i]};
    vector<pair<int, int>> ans;
    int moves = mergesort2util(c, ans);
    bool flag = true;
    
    //for(auto elem : c) cout << "( "<< elem.first << " "<< elem.second <<" )"; cout << endl;
    for(int i = 0; i < n - 1; i++)
    {
        if(c[i].first > c[i + 1].first || c[i].second > c[i + 1].second) flag &= false;
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




int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {solve8();}

}

