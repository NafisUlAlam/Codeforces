#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;
const int mod = (int)1e9 + 7;
const int maxn = (int) 1e5 + 10;


int longestCommonSubstr(string x, string y, int n, int m, int cnt)
{
   if(n == 0 || m == 0) return cnt;
   if(x[n - 1] == y[m - 1])
   {
      cnt = longestCommonSubstr(x, y, n - 1, m - 1, cnt + 1); 
   }
   
   int cnt1 = longestCommonSubstr(x, y, n, m - 1, 0);
   int cnt2 = longestCommonSubstr(x, y, n - 1, m , 0);
   cnt = max({cnt, cnt1, cnt2});
   return cnt;
}

int unboundKnapsack(vector<int>& wt, vector<int>& val, int w, int n)
{
   if(n == 0 || w == 0) return 0;
   if(wt[n - 1] <= w)
   {
      return max(val[n - 1] + unboundKnapsack(wt, val, w - wt[n - 1], n),
      0 + unboundKnapsack(wt, val, w - 0, n - 1));
   }
   else return 0 + unboundKnapsack(wt, val, w, n - 1);
}

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

void generateUniquePermutations(set<vector<int>>& ans, vector<int>& perm, int n, vector<int>& a)
{
    
   if(perm.size() == n)
   {
       vector<int> temp;
       for(int i = 0; i < n; i++)
       {
           temp.push_back(a[perm[i]]);
       }
       ans.insert(temp);
       return;
   }
   
   for(int i = 0; i < n; i++)
   {
       if(find(perm.begin(), perm.end(), i) == perm.end())
       {
           perm.push_back(i);
           generateUniquePermutations(ans, perm, n, a);
           perm.pop_back();
       }
       else continue;
   }
}
void generatePermutations(vector<vector<int>>& ans, vector<int>& perm, int n, vector<int>& a)
{
    
   if(perm.size() == n)
   {
       vector<int> temp;
       for(int i = 0; i < n; i++)
       {
           temp.push_back(a[perm[i]]);
       }
       ans.push_back(temp);
       return;
   }
   
   for(int i = 0; i < n; i++)
   {
       if(find(perm.begin(), perm.end(), i) == perm.end())
       {
           perm.push_back(i);
           generatePermutations(ans, perm, n, a);
           perm.pop_back();
       }
       else continue;
   }
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
         if(r > n) break;
         //cout << r << endl;
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

void solve1689B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), b(n + 1);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      b[a[i]] = i;
   }
   //for(auto elem : b) cout << elem << " "; cout << endl;
   
   sort(a.begin(), a.end());
   for(int i = 1; i <= n; i++)
   {
      if(i < n && b[a[i]] == i)
      {
         //cout << "if swap" << endl;
         swap(a[i], a[i + 1]);
      }
      else if(i == n && b[a[i]] == i)
      {
         //cout << "else swap" << endl;
         //cout << a[i] << " " << a[i - 1] << endl;
         swap(a[i], a[i - 1]);
      }
      //for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
   }
   if(n == 1){cout << -1 << endl; return;}
   for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
}



void solve1689C()
{
   int n;
   cin >> n;
   vector<vector<int>> g(n + 1);
   for(int i = 1; i <= n - 1; i++)
   {
      int u, v;
      cin >> u >> v;
      if(u < v) g[u].push_back(v);
      else g[v].push_back(u);
   }
   
}

void solve1535B()
{
   int n;
   cin >> n;
   vector<int>a(n);
   for(auto& e : a) cin >> e;
   sort(a.begin(), a.end(), [](int x, int y) {return x  % 2 < y % 2;});
   for(auto elem : a) cout << elem << " "; cout << endl;
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      for(int j = i + 1; j < n; j++)
      {
         if(__gcd(a[i], 2 * a[j]) > 1) ans++;
      }
   }
   //cout << ans << endl;
}

void solve1350A()
{
   int n, k;
   cin >> n >> k;
   int mini = n;
   for(int i = 2; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         mini = i;
         break;
      }
   }
   ll ans = 0;
   ans = n + mini + (2 * 1ll * (k - 1));
   cout << ans << endl;
}

void solve567A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++)
   {
      int mini = INT_MAX;
      int maxi = INT_MIN;
      if(i > 0 && i < n - 1)
      {
         mini = min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]));
         maxi = max(abs(a[i] - a[0]), abs(a[i] - a[n - 1]));
      }
      else if(i == 0)
      {
         mini = abs(a[0] - a[1]);
         maxi = abs(a[0] - a[n - 1]);
      }
      else
      {
         mini = abs(a[n - 1] - a[n - 2]);
         maxi = abs(a[0] - a[n - 1]);
      }
      cout << mini << " " << maxi << endl;
   }
}


bool check2(ll mid, ll x, ll k)
{
   ll sum = 0, rem = 2 * k - 1 - mid; 
   if(mid < k) sum = (mid * 1ll * (mid + 1)) / 2;
   else sum = (k * 1ll * k) - ((rem * 1ll * (rem + 1)) / 2);
   return sum <= x;
}
ll check3(ll mid, ll x, ll k)
{
   ll sum = 0, rem = 2 * k - 1 - mid;
   if(mid < k) sum = (mid * 1ll * (mid + 1)) / 2;
   else sum = (k * 1ll * k) - ((rem * 1ll * (rem + 1)) / 2);
   return x - sum;
}
void solve1612C()
{
   ll k, x, ans;
   cin >> k >> x;
   ll lo = 1, hi = 2 * k - 1;
   while(hi - lo > 1)
   {
      ll mid = (hi + lo) / 2;
      if(check2(mid, x, k)) lo = mid;
      else hi = mid;
   }
   
   if(lo != hi && check2(lo, x, k) && check3(lo, x, k) > 0ll) ans = lo + 1;
   else ans = lo;
   cout << ans << endl;
}

void solve268B()
{
   int n;
   cin >> n;
   ll sum = n;
   for(int i = n - 1; i >= 1; i--)
   {
      sum += i * 1ll * (n - i);
   }
   cout << sum << endl;
}

void solve1433C()
{
   int n, maxi = 0;
   cin >> n;
   vector<int> a(n), b;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a[i] = x;
      maxi = max(maxi, a[i]);
   }
   int cnt = 0;
   for(int i = 0; i < n; i++)
   {
      if(a[i] == maxi) cnt++;
      else a[i] = 0;
   }
   if(cnt == n) cout << -1 << endl;
   else
   {
      for(int i = 0; i < n; i++)
      {
         if(a[i] == maxi)
         {
            if(i >= 1 && i <= n - 2 && a[i - 1] == 0 || a[i + 1] == 0)
            {
               cout << i + 1 << endl;
               break;
            }
            else if(i == 0 && a[i + 1] == 0)
            {
               cout << i + 1 << endl;
               break;
            }
            else if(i == n - 1 && a[i - 1] == 0)
            {
               cout << i + 1 << endl;
               break;
            }
         }
      }
   }
}

void solve1324A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e: a) cin >> e;
   bool fl = true;
   for(int i = 0; i < n - 1; i++)
   {
      if( (abs(a[i] - a[i + 1])) % 2 != 0) fl = false;
   }
   if(fl) cout << "YES" << endl;
   else cout << "NO" << endl;
}


void solveEduCourse2Lesson93PracticeE()
{
   int n, s;
   cin >> n >> s;
   vector<int> w(n), c(n);
   for(int i = 0; i < n; i++) cin >> w[i];
   for(int i = 0; i < n; i++) cin >> c[i];
   
   int l = 0, r = 0;
   ll ans = 0, weight = 0, cost = 0;
   for(r = 0; r < n; r++)
   {
      weight += w[r];
      cost += c[r];
      while(weight > s)
      {
         weight -= w[l];
         cost -= c[l];
         l++;
      }
      //cout << cost << endl;
      ans = max(ans, cost);
   }
   cout << ans << endl;
}

void solve1702D()
{
   string s;
   cin >> s;
   ll w, sum = 0;
   cin >> w;
   vector<int>a(27, 0);
   for(int i = 0; i < s.size(); i++)
   {
      a[s[i] - 'a' + 1]++;
      sum += s[i] - 'a' + 1;
   }
   //cout << sum << endl;
   //for(auto elem : a) cout << elem << " " ; cout << endl;
   if(w >= sum) 
   {
      cout << s << endl;
      return;
   }
   string ans;
   while(sum > w)
   {
      ll need = 26;
      while(need >= 1 && a[need] == 0) need--;
      if(need >= 1)
      {
         sum -= need;
         a[need]--;
      }
      else break;
      
   }
   //for(auto elem : a) cout << elem << " " ; cout << endl;
   for(int i = 0; i < s.size(); i++)
   {
      if(a[s[i] - 'a' + 1] > 0) 
      {
         a[s[i] - 'a' + 1]--;
         ans += s[i];
      }
   }
   cout << ans << endl;
}

void solve1702A()
{
   int s;
   cin >> s;
   int zeroes = log10(s);
   cout << s - (int) pow(10, zeroes) << endl;
}

void solve1702B()
{
   string s;
   cin >> s;
   int n = s.size();
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      vector<int>f(26, 0);
      int cnt = 0, j = i;
      while(j < n && cnt <= 3)
      {
         
         //cout << s[j] << endl;
         if(j < n && f[s[j] - 'a'] == 0)
         {
            f[s[j] - 'a']++;
            cnt++;
            if (cnt > 3) break;
            j++;
         }
         else if(j < n && f[s[j] - 'a'] > 0)
         {
            j++;
         }
      }
      if(cnt > 3 || j >= n) ans++;
      i = j - 1;
   }
   cout << ans << endl;
}

void solve1702C()
{
   int n, q;
   cin >> n >> q;
   map<int, vector<int>> b;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      b[x].push_back(i);
   }
   
   while(q--)
   {
      int u, v;
      cin >> u >> v;
      if(b[u].size() == 0 || b[v].size() == 0)
      {
         cout << "NO" << endl;
         continue;
      }
      if(b[u].front() < b[v].back())
      {
         cout << "YES" << endl;
         continue;
      }
      else
      {
         cout << "NO" << endl;
         continue;
      }
   }
}

void solve1703D()
{
   int n;
   cin >> n;
   vector<string>a(n);
   set<string>st;
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      a[i] = s;
      st.insert(s);
   }
   
   string ans;
   for(int i = 0; i < n; i++)
   {
      string curr = a[i];
      int n = curr.size();
      bool found = false;
      for(int i = 0; i <= n - 2; i++)
      {
         string fi = curr.substr(0, i + 1);
         string se = curr.substr(i + 1);
         if(st.find(fi) != st.end() && st.find(se) != st.end())
         {
            found = true;
            break;
         }
      }
      if(found) ans += '1';
      else ans += '0';
   }
   cout << ans << endl;
   
}

void solve1703A()
{
   string s;
   cin >> s;
   if( (s[0] == 'y' || s[0] == 'Y' ) && (s[1] == 'e' || s[1] == 'E') && (s[2] == 's' || s[2] == 'S') )
   {
      cout << "YES" << endl;
   }
   else cout << "NO" << endl;
}

void solve1703B()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   set<char> st;
   int ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(st.find(s[i]) == st.end())
      {
         ans += 2;
      }
      else ans += 1;
      st.insert(s[i]);
   }
   cout << ans << endl;
}

void solve1703C()
{
   int n;
   cin >> n;
   vector<int>a(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   
   for(int i = 0; i < n; i++)
   {
      int t;
      cin >> t;
      string s;
      cin >> s;
      
      for(int j = 0; j < t; j++)
      {
         if(s[j] == 'D')
         {
            a[i] = (a[i] + 1) % 10;
         }
         else 
         {
            a[i] = (a[i] - 1 + 10) % 10;
         }
      }
      
   }
   
   for(int i = 0; i < n; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

void solve1703F()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   vector<pair<int, int>> b;
   for(int i = 1; i <= n; i++) 
   {
      cin >> a[i];
      if(a[i] < i)
      {
         b.push_back({a[i], i});
      }
   }
   
   sort(b.begin(), b.end());
   
   //for(auto elem : b) cout <<"(" << elem.first << " " << elem.second <<")"; cout << endl;
   
   int sz = b.size();
   ll ans = 0;
   for(int i = 0; i < sz; i++)
   {
      int lo = i + 1, hi = sz - 1, x = -1;
      
      while(lo <= hi)
      {
         int mid = (lo + hi) / 2;
         if(b[i].second >= b[mid].first || b[i].second >= b[mid].second)
         {
            lo = mid + 1;
         }
         else
         {
            x = mid;
            hi = mid - 1;
            //if(i == 5)cout << x << endl;
         }
      }
      if(x != -1)
      {
         //cout << sz - x << endl;
         ans += sz - x;
      }
   }
   cout << ans << endl;
}

void solve1703E()
{
   int n;
   cin >> n;
   vector<vector<int>> a(n, vector<int> (n));
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < n; j++)
      {
         if(s[j] == '0') a[i][j] = 0;
         else a[i][j] = 1;
      }
   }
   int i = 0, j = n - 1;
   ll ans = 0;
   while(i < j)
   {
      //cout << i << " i and j " << j << endl;
      for(int k = 0; i + k < j; k++)
      {
         //cout << i << " " << i + k << endl;
         //cout << i + k << " " << j << endl;
         //cout << j - k << " " << i << endl;
         //cout << j << " " << j - k << endl;
         int cnt1 = 0;
         if(a[i][i + k] == 1) cnt1++;
         if(a[i + k][j] == 1) cnt1++;
         if(a[j - k][i] == 1) cnt1++;
         if(a[j][j - k] == 1 ) cnt1++;
         
         //cout << cnt1 << endl;
         ans += min(cnt1, 4 - cnt1);
      }
      i++, j--;
   }
   cout << ans << endl;
   
}

void solve1097B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   vector<vector<int>> dp(n + 1);
   dp[0].push_back(0);
   
   for(int i = 1; i <= n; i++)
   {
      int curr = a[i - 1];
      for(auto elem : dp[i - 1])
      {
         dp[i].push_back((elem + curr) % 360);
      }
      for(auto elem : dp[i - 1])
      {
         dp[i].push_back((elem - curr + 360) % 360);
      }
   }
   
   //for(auto elem : dp)
   {
      //for(auto e : elem) cout << e << " "; cout << endl;
   }
   
   for(int i = 0; i < dp[n].size(); i++)
   {
      //cout << dp[n][i] << " "; 
      if(dp[n][i] == 0 || dp[n][i] == 360) 
      {
         cout << "YES" << endl;
         return;
      }
   }
   cout << "NO" << endl;
}


void solve1294C()
{
   int n, n1;
   cin >> n;
   n1 = n;
   set<int> a;
   int cnt = 0;
   for(int i = 2; i * i <= n1; i++)
   {
      //cout << "i " << i << endl;
      if(n % i == 0 && a.find(i) == a.end())
      {
         a.insert(i);
         n /= i;
         cnt++;
      }
      if(cnt == 2) break;
   }
   if(n > 1) a.insert(n);
   
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //cout << n << endl;
   if(a.size() == 3) 
   {
      cout << "YES" << endl;
      for(auto elem : a) cout << elem << " "; cout << endl;
   }
   else cout << "NO" << endl;
}

void solve1705B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   ll ans = 0;
   ll moves = 0;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(i < n - 1)
      {
         ans += a[i];
         if(a[i] == 0) 
         {
            if(i >= 1 && a[i - 1] != 0)
            {
               moves++;
               a[i]++;
               a[i - 1]--;
            }
         }
         
      }
   }
   ans += moves;
   cout << ans << endl;
}

void solve1705C()
{
   ll n, c, q;
   cin >> n >> c >> q;
   string s;
   cin >> s;
   vector<pair<ll,ll>>len(c), query(c);
   
   ll curr = n;
   for(ll i = 0; i < c; i++)
   {
      ll l, r;
      cin >> l >> r;
      ll qlen = r - l + 1;
      query[i].first = l;
      query[i].second = r;
      
      len[i].first = curr + 1;
      len[i].second = curr + qlen;
      curr = curr + qlen;
      
   }
   //for(auto elem : query) cout <<"(" << elem.first <<" " << elem.second <<")"; cout << endl;
   
   //for(auto elem : len) cout <<"(" << elem.first <<" " << elem.second <<")"; cout << endl;
   while(q--)
   {
      ll idx;
      cin >> idx;
      for(ll i = c - 1; i >= 0; i--)
      {
         //cout <<i << " "<<  idx << " " << len[i].first << " " << len[i].second << endl;
         if(idx >= len[i].first && idx <= len[i].second)
         {
            ll gap = idx - len[i].first;
            idx = gap + query[i].first;
            
         }
      }
      cout << s[--idx] << endl;
   }
}


void solve1708B()
{
   int n, l, r;
   //cout << "HI" << endl;
   cin >> n >> l >> r;
   vector<ll> a(n + 1, 0);
   a[1] = l;
   
   for(int i = 2; i < n + 1; i++)
   {
      //cout << "for" << endl;
      if((l % i) == 0)
      {
          //cout << "divisibel";
         a[i] = l;
      }
      else
      {
         ll k = ((l / i) + 1) * 1ll * i;
         //cout << k << endl;
         if(k >= l && k <= r) 
         {
             //cout << "not";
             a[i] = k;
         }
      }
   }
   for(int i = 1; i < n + 1; i++)
   {
       if(a[i] == 0) 
       {
           cout << "NO" << endl;
           return;
       }
   }
   cout << "YES" << endl;
   for(int i = 1; i < n + 1; i++) cout << a[i] << " "; cout << endl;
}


void solve1708A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   bool fl = false;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      
   }
   for(int i = 1; i < n; i++)
   {
      a[i] = a[i] % a[0];
   }
   for(int i = 1; i < n; i++)
   {
      if(a[i] != 0) 
      {
         cout <<"NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
}


void solve1698C()
{
   int n;
   cin >> n;
   vector<int> pos, neg, a;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x > 0) pos.push_back(x);
      
      else if(x < 0) neg.push_back(x);
      else
      {
         if(a.size() < 2) a.push_back(x);
      }
   }
   
   if(pos.size() > 2 || neg.size() > 2) 
   {
      cout <<"NO" << endl;
      return;
   }
   
   for(auto elem : pos) a.push_back(elem);
   for(auto elem : neg) a.push_back(elem);
   int sz = a.size();
   
   for(int i = 0; i < sz; i++)
   {
      for(int j = i + 1; j < sz; j++)
      {
         for(int k = j + 1; k < sz; k++)
         {
            int sum = a[i] + a[j] + a[k];
            bool fl = false;
            for(int l = 0; l < sz; l++)
            {
               if(a[l] == sum)
               {
                  fl = true;
               }
            }
            if(fl == false) 
            {
               cout << "NO" << endl;
               return;
            }
         }
      }
   }
   cout << "YES" << endl;
}

void solve1708C()
{
   int n, q;
   cin >> n >> q;
   vector<int> v(n),good, bad;
   for(int i = 0; i < n; i++) cin >> v[i];
   
   for(int i = 0; i < n; i++)
   {
      if(v[i] > q) bad.push_back(i);
      else good.push_back(i);
   }
   
   ll low = 0, high = (int)bad.size() - 1, ans = n;
   
   while(low <= high)
   {
      ll mid = (low + high) / 2;
      ll ok = 1, curr_iq = q;
      
      for(int i = bad[mid]; i < n; i++)
      {
         if(curr_iq == 0) ok = 0;
         if(v[i] > curr_iq) curr_iq--;
      }
      if(ok == 1)
      {
         ans = bad[mid];
         high = mid - 1;
      }
      else low = mid + 1;
   }
   
   for(int i = 0; i < ans; i++)
   {
      if(v[i] <= q) cout << 1;
      else cout << 0;
   }
   for(int i = ans; i < n; i++)
   {
      cout << 1;
   }
   cout << endl;
   
}

void solve1667A()
{
   int n;
   cin >> n;
   vector<int> a(n), b(n, 0);
   for(int i = 0; i < n; i++) cin >> a[i];
   ll ans = (int)1e9 + 7;
   for(int i = 0; i < n; i++)
   {
      ll moves = 0;
      ll curr = 0;
      for(int j = i - 1; j >= 0; j--)
      {
         //cout << a[j] << " ";
         if(a[j] >= curr)
         {
            if(curr == 0) 
            {
               curr = a[j] * (-1);
               moves += 1;
            }
            else
            {
               
               ll divi = curr / a[j];
               if (divi > 0) divi++;
               else divi--;
               
               curr = divi * a[j];
               moves += abs(curr / a[j]);
            }
         }
         else {curr = a[j]; moves++;}
      }
      
      curr = 0;
      for(int j = i + 1; j < n; j++)
      {
         if(a[j] <= curr)
         {
            if(curr == 0) 
            {
               curr = a[j] * (-1);
               moves += 1;
            }
            else
            {
               ll divi = curr / a[j];
               if(divi > 0) divi++;
               else divi--;
               curr = divi * a[j];
               moves += abs(curr / a[j]);
            }
         }
         else {curr = a[j]; moves++;} 
      }
      ans = min(moves, ans);
   }
   cout << ans << endl;
}


void solve1706B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), ans(n + 1, 0);
   vector<vector<int>> b(n + 1);
   
   
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      b[a[i]].push_back(i);
   }
   
   /*for(auto elem : b)
   {
      for (auto e : elem) cout << e << " ";
      cout << endl;
   }*/
   for(int i = 1; i <= n; i++)
   {
      if(b[i].size() == 0) continue;
      //cout << b[i].size() << endl;
      int cnt = 0;
      for(int j = 0; j < b[i].size() - 1; j++)
      {
         //cout << b[i][j + 1] << " " << b[i][j] << endl;
         if((b[i][j + 1] - b[i][j] - 1) % 2 == 0) 
         {
            cnt++;
         }
      }
      ans[i] = cnt + 1;
   }
   
   
   for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}


void solve1706A()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   for(int i = 0; i < n; i++) {int x; cin >> x; x--; a[i] = x;}
   string s(m, 'B');
   
   for(int i = 0; i < n; i++)
   {
      int first = a[i];
      int second = m - 1 - a[i];
      if(first < second)
      {
         if(s[first] == 'B') s[first] = 'A';
         else s[second] = 'A';
      }
      else
      {
         if(s[second] == 'B') s[second] = 'A';
         else s[first] = 'A';
      }
   }
   cout << s << endl;
   
}

void solve1706C()
{
   ll n; 
   cin >> n;
   vector<ll> a(n);
   for(auto &e : a) cin >> e; 
   ll ans = 1e18;
   
   if(n % 2 == 1)
   {
      ans = 0;
      for(ll i = 1; i < n; i += 2)
      {
         ans += max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
      }
   }
   
   else
   {
      vector<ll> pref(n + 1, 0), suff(n, 0);
      
      for(ll i = 1; i + 1 < n; i += 2)
      {
         pref[i + 1] = pref[i - 1] + max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
      }
      
      for(ll i = n - 2; i - 1 >= 0; i -= 2)
      {
         suff[i - 1] = suff[i + 1] + max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
      }
      
      for(ll i = 0; i < n; i += 2)
      {
         ans = min(ans, pref[i] + suff[i + 1]);
      }
   }
   cout << ans << endl;
}

void solve1699B()
{
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < n; i++)
   {
      bool z = false, o = false;
      if(i % 4 == 0 || i % 4 == 3) z = true;
      else o = true;
      for(int j = 0; j < m; j++)
      {
         if(z == true)
         {
            if(j % 4 == 0 || j % 4 == 3) cout << 0 << " ";
            else cout << 1 << " ";
         }
         else if(o == true)
         {
            if(j % 4 == 0 || j % 4 == 3) cout << 1 << " ";
            else cout << 0 << " ";
         }
      }
      cout << endl;
      z = false;
      o = false;
   }
}




void solve1709B()
{
   ll n, m;
   cin >> n >> m;
   vector<ll> a(n + 1), pref(n + 1, 0), suff(n + 1, 0);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
   }
   
   for(int i = 1; i + 1 <= n; i++)
   {
      if(a[i + 1] < a[i]) pref[i + 1] = pref[i] + abs(a[i] - a[i + 1]);
      else pref[i + 1] = pref[i];
   }
   
   for(int i = n; i - 1 >= 1; i--)
   {
      if(a[i - 1] < a[i]) suff[i - 1] = suff[i] + abs(a[i] - a[i - 1]);
      else suff[i - 1] = suff[i];
   }
   
   //for(int i = 1; i <= n; i++) cout << pref[i] << " "; cout << endl;
   //for(int i = 1; i <= n; i++) cout << suff[i] << " "; cout << endl;
   
   for(int k = 0; k < m; k++)
   {
      int i, j;
      cin >> i >> j;
      if(i < j)
      {
         cout << pref[j] - pref[i] << endl;
      }
      else
      {
         cout << suff[j] - suff[i] << endl;
      }
   }
}

void solve1709A()
{
   int x;
   cin >> x;
   vector<int>a(4);
   int cnt = 0;
   for(int i = 1; i < 4; i++) cin >> a[i];
   while(a[x] != 0)
   {
      cnt++;
      x = a[x];
   }
   if(cnt == 2) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1709C()
{
   string s;
   cin >> s;
   ll buffer = 0, cnt = 0;
   for(auto x : s)
   {
      if(x == ')') cnt++;
      else if(x == '(') cnt--;
      else buffer++;
   }
   
   ll open = (buffer + cnt) / 2;
   ll close = (buffer - cnt) / 2;
   
   if(open == 0 || close == 0)
   {
      cout << "YES" << endl;
      return;
   }
   
   string check = string(open - 1, '(') + string(1, ')') + string(1, '(') + string(close - 1, ')');
   ll ptr = 0;
   
   for(auto & x : s)
   {
      if(x == '?') x = check[ptr++];
   }
   cnt = 0;
   for(auto x : s)
   {
      if(x == '(') cnt++;
      else cnt--;
      if(cnt < 0) {cout << "YES" << endl; return;}
   }
   
   cout << "NO" << endl;
   
}

void solve1335D()
{
   vector<vector<int>> a(10, vector<int>(10));
   for(int i = 0; i < 9; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < 9; j++)
      {
         a[i + 1][j + 1] = s[j] - '0';
      }  
   }
   
   int start = 0;
   int mul = 0;
   for(int i = 1; i <= 9; i++)
   {
      if(i % 3 == 1) 
      {
         start++;
         mul = 0;
      }
      else mul++;
      
      for(int j = 1; j <= 9; j++)
      {
         if(j == start + 3 * mul)
         {
            //cout << i << " " << j << endl;
            int curr = a[i][j];
            for(int k = 1; k <= 9; k++)
            {
               if(k != curr) {a[i][j] = k; break;}
            }
         }
         cout << a[i][j];
      }
      cout << endl;
   }
}

void solve476B()
{
   string s1, s2;
   cin >> s1 >> s2;
   int n = s1.size();
   int sum = 0;
   for(int i = 0; i < n; i++) sum += (s1[i] == '+') ? 1 : -1;
   
   vector<vector<int>>dp(n);
   if(s2[0] == '+') dp[0].push_back(1);
   else if (s2[0] == '-') dp[0].push_back(-1);
   else {dp[0].push_back(-1); dp[0].push_back(1);}
   
   
   for(int i = 1; i < n; i++)
   {
      auto curr = s2[i];
      if(curr == '+')
      {
         for(auto elem : dp[i - 1])
         {
            dp[i].push_back(elem + 1);
         }
      }
      else if(curr == '-')
      {
         for(auto elem : dp[i - 1])
         {
            dp[i].push_back(elem - 1);
         }
      }
      else
      {
         for(auto elem : dp[i - 1])
         {
            dp[i].push_back(elem - 1);
            dp[i].push_back(elem + 1);
         }
      }
   }
   
   int p = dp[n - 1].size();
   int q = 0;
   for(auto elem : dp[n - 1])
   {
      if(elem == sum) q++;
   }
   
   cout << setprecision(12) << fixed <<  q / (p * 1.0) << endl;
}

void solve1711B()
{
   ll n, m;
   cin >> n >> m;
   vector<vector<ll>>a(n + 1);
   vector<ll> cost(n + 1);
   vector<pair<ll, ll>> edges(m);
   for(ll i = 0; i < n; i++) cin >> cost[i + 1];
   for(ll i = 0; i < m; i++)
   {
      ll x, y;
      cin >> x >> y;
      edges[i] = {x, y};
      a[x].push_back(y);
      a[y].push_back(x);
   }
   ll ans = 1e18;
   
   if(m % 2 == 0) 
   {
      cout << 0 << endl;
      return;
   }
   for(ll i = 1; i <= n; i++)
   {
      if(a[i].size() % 2 == 1) ans = min(ans, cost[i]);
      
   }
   for(ll i = 0; i < m; i++)
   {
      ll p = edges[i].first;
      ll q = edges[i].second;
      if((a[p].size() % 2 == 0) && (a[q].size() % 2 == 0)) ans = min(ans, cost[p] + cost[q]);
   }
   cout << ans << endl;
}

void solve1711C()
{
   ll n, m, k;
   cin >> n >> m >> k;
   vector<ll> v(k);
   for(ll i = 0; i < k; i++) cin >> v[i];
   
   ll cols = 0, oddc = 0, okc = 0, rows = 0, oddr = 0, okr = 0;
   
   for(ll i = 0; i < k; i++)
   {
      ll canc = v[i] / n; ll canr = v[i] / m;
      if(canc > 1)
      {
         cols += canc;
         if(canc >= 3) okc = 1;
         if(canc & 1) oddc = 1;
      }
      if(canr > 1)
      {
         rows += canr;
         if(canr >= 3) okr = 1;
         if(canr & 1) oddr = 1;
      }
   }
   
   if(cols >= m)
   {
      if(m % 2 == 0)
      {
         cout << "YES" << endl;
         return;
      }
      if(oddc > 0)
      {
         cout << "YES" << endl;
         return;
      }
      else
      {
         if(okc > 0)
         {
            cols--;
            if(cols >= m)
            {
               cout << "YES" << endl;
               return;
            }
         }
      }
   }
   
   if(rows >= n)
   {
      if(n % 2 == 0)
      {
         cout << "YES" << endl;
         return;
      }
      
      if(oddr > 0)
      {
         cout << "YES" << endl;
         return;
      }
      else
      {
         if(okr > 0)
         {
            rows--;
            if(rows >= n)
            {
               cout << "YES" << endl;
               return;
            }
         }
      }
   }
   cout << "NO" << endl;
   
}

void solve1711B()
{
   ll n, m;
   cin >> n >> m;
   vector<vector<ll>>a(n + 1);
   vector<ll> cost(n + 1);
   vector<pair<ll, ll>> edges(m);
   for(ll i = 0; i < n; i++) cin >> cost[i + 1];
   for(ll i = 0; i < m; i++)
   {
      ll x, y;
      cin >> x >> y;
      edges[i] = {x, y};
      a[x].push_back(y);
      a[y].push_back(x);
   }
   ll ans = 1e18;
   
   if(m % 2 == 0) 
   {
      cout << 0 << endl;
      return;
   }
   for(ll i = 1; i <= n; i++)
   {
      if(a[i].size() % 2 == 1) ans = min(ans, cost[i]);
      
   }
   for(ll i = 0; i < m; i++)
   {
      ll p = edges[i].first;
      ll q = edges[i].second;
      if((a[p].size() % 2 == 0) && (a[q].size() % 2 == 0)) ans = min(ans, cost[p] + cost[q]);
   }
   cout << ans << endl;
}


void solve1672C()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(auto &e : a) cin >> e;
   int l = -1, r = -1;
   for(int i = 0; i + 1 < n; i++)
   {
      if(a[i] == a[i + 1])
      {
         if(l == -1)
         {
            l = i;
         }
         r = i;
      }
   }
   if(l == r) cout << 0 << endl;
   else cout << max(1, r - l - 1) << endl;
}

void solve1703G()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(n);
   for(auto & e: a) cin >> e;
   ll sum = 0, ans = 0;
   
   for(ll i = -1; i < n; i++)
   {
      if(i >= 0) sum += a[i] - k;
      ll now = 0;
      now += sum;
      //ll now = sum;
      for(ll j = i + 1; j < min(n, i + 32); j++)
      {
         ll copy = a[j];
         copy >>= j - i;
         now += copy;
      }
      ans = max(ans, now);
      
      //if(i + 1 < n) sum += a[i + 1] - k;
      
   }
   cout << ans << endl;
   
}
void solve1702F()
{
   ll n;
   cin >> n;
   vector<ll> a(n), b(n);
   map<ll, ll> freq;
   
   for(ll i = 0; i < n; i++)
   {
      cin >> a[i];
      while(a[i] % 2 == 0) a[i] = a[i] / 2;
      freq[a[i]]++;
   }
   
   for(ll i = 0; i < n; i++)
   {
      cin >> b[i];
      while(b[i] % 2 == 0) b[i] = b[i] / 2;
   }
   
   for(ll i = 0; i < n; i++)
   {
      bool flag = false;
      while(b[i] > 0)
      {
         if(freq[b[i]] > 0)
         {
            freq[b[i]]--;
            flag = true;
            break;
         }
         else b[i] /= 2;
      }
      if(flag == false)
      {
         cout << "NO" << endl;
         return;
      }
     /* while(b[i] > 0 && freq[b[i]] <= 0)
      {
         b[i] /= 2;
      }
      if(freq[b[i]] == 0)
      {
         cout << "NO" << endl;
         return;
      }
      else freq[b[i]]--;*/
   }
   cout << "YES" << endl;
   
}
void solve1472C()
{
   ll n;
   cin >> n;
   vector<ll> a(n + 1), pref(n + 1, 0);
   for(ll i = 1; i <= n; i++)
   {
      cin >> a[i];
      pref[i] = a[i];
   }
   
   for(ll i = 1; i <= n; i++)
   {
      if(i + a[i] <= n)pref[i + a[i]] = max(pref[i + a[i]], pref[i] + a[i + a[i]]);
   }
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   cout << *max_element(pref.begin(), pref.end()) << endl;
}

void solve1365B()
{
   int n, cnta = 0, cntb = 0;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++) 
   {
      int x;
      cin >> x;
      if(x == 0) cnta++;
      else cntb++;
   }
   
   if(cnta > 0 && cntb > 0)
   {
      cout << "YES" << endl;
      return;
   }
   
   for(int i = 0; i + 1< n; i++)
   {
      if(a[i] > a[i + 1])
      {
         cout << "NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
   
   
}

void solve1704B()
{
   ll n, x;
   cin >> n >> x;
   vector<ll> a(n);
   vector<pair<ll, ll>> b(n);
   for(ll i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++)
   {
      ll f = max(0ll, a[i] - x);
      ll s = min((ll)1e9, a[i] + x);
      b[i] = {f, s};
   }
   ll cnt = 0;
   pair<ll, ll> curr = {b[0].first, b[0].second};
   for(ll i = 0; i < n; i++)
   {
      if((b[i].first >= curr.first && b[i].first <= curr.second)
      || (b[i].second >= curr.first && b[i].second <= curr.second)
      || (b[i].first <= curr.first &&  b[i].second >= curr.second))
      {
         curr.first = max(curr.first, b[i].first);
         curr.second = min(curr.second, b[i].second);
      }
      else
      {
         //cout << i << "Changed" << endl;
         cnt++;
         curr.first = b[i].first;
         curr.second = b[i].second;
      }
      //cout << curr.first << " " << curr.second << endl;
   }
   cout << cnt << endl;
}

void solve1704A()
{
   int n, m;
   cin >> n >> m;
   string a, b;
   cin >> a; cin >> b;
   bool flag = true, zero = false, one = false;
   int p = (int)a.size() - 1, q =(int) b.size() - 1;
   for(int j = 1; j <= m - 1; j++)
   {
      //cout << "HI" << endl;
      if(a[p] != b[q]) flag = false;
      p--, q--;
   }
   for(int i = 0; i <= p; i++)
   {
      if(a[i] == '1') one = true;
      if(a[i] == '0') zero = true;
   }
   //cout << p <<" "<< b[q] <<" "<< zero << " " << one <<  endl;
   if(flag == false)
   {
      cout << "NO" << endl;
      return;
   }
   if(b[q] == '0' && zero == true)
   {
      cout << "YES" << endl;
      return;
   }
   if(b[q] == '1' && one == true)
   {
      cout << "YES" << endl;
      return;
   }
   cout << "NO" << endl;
}

void solve1714B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   set<int>st;
   int mark = -1;
   for(int i = n - 1; i >= 0; i--)
   {
      if(st.empty() || st.find(a[i]) == st.end())
      {
         st.insert(a[i]);
      }
      else
      {
         mark = i;
         break;
      }
   }
   if(mark == -1) cout << 0 << endl;
   else cout << mark + 1 << endl;
}

void solve1714C()
{
   int n;
   cin >> n;
   string s;
   int p = 9;
   while(n > 0)
   {
      if(n - p >= 0)
      {
         s.push_back(p + '0');
         n -= p;
         p--;
      }
      else
      {
         s.push_back(n + '0');
         n = 0;
      }
   }
   reverse(s.begin(), s.end());
   cout << s << endl;
}

void solve1714A()
{
   int n, h, m;
   cin >> n >> h >> m;
   pair<int, int> my = {h, m};
   bool flag = true;
   vector<pair<int, int>> a(n);
   for(int i = 0; i < n; i++) 
   {
      int x, y;
      cin >> x >> y;
      if(x == h && y == m) flag = false;
      a[i] = {x, y};
   }
   
   if(flag == false) 
   {
      cout << 0 <<" " << 0<< endl;
      return;
   }
   
   pair<int, int> closest = {INT_MAX, INT_MAX};
   int divi1 = h / 12;
   int rem1 = h % 12;
   for(int i = 0; i < n; i++)
   {
      if(m > a[i].second)
      {
         a[i].second += 60;
         a[i].first -= 1;
      }
      int diff, diff2;
      diff2 = a[i].second - m;
      int divi2 = a[i].first / 12;
      int rem2 = a[i].first % 12;
      if(divi1 != divi2)
      {
         diff = 12 - rem1 + rem2;
      }
      else
      {
         if(rem2 >= rem1) diff = rem2 - rem1;
         else diff = 24- (rem1 - rem2);
      }
      pair<int,int> curr = {diff, diff2};
      //cout << curr.first << " " << curr.second << endl;
      closest = min(curr, closest);
   }
   
   cout << closest.first << " " << closest.second << endl;
}
void solve1372B()
{
   ll n;
   cin >> n;
   ll n1 = n;
   if(!(n & 1))
   {
      cout << n / 2 << " " << n / 2 << endl;
      return;
   }
   
   vector<ll> divisors;
   for(ll i = 1; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         divisors.push_back(i);
         if(n / i != n) divisors.push_back(n / i);
         n /= i;
      }
   }
   //for(auto elem : divisors) cout << elem << " "; cout << endl;
   ll a = *max_element(divisors.begin(), divisors.end());
   ll b = n1 - a;
   cout <<a << " "<<  b << endl;
}

bool isPalindrome(vector<int>& a, int n)
{
   if(n % 2 == 0)
   {
      for(int i = 0; i < a.size(); i++)
      {
         if(a[i] % 2 == 1) return false;
      }
   }
   else
   {
      int oddc = 0;
      for(int i = 0; i < a.size(); i++)
      {
         if(a[i] % 2 == 1) oddc++;
      }
      if(oddc > 1) return false;
   }
   return true;
}
void solve276B()
{
   string s;
   cin >> s;
   int n = s.size();
   vector<int> a(26, 0);
   for(int i = 0; i < n; i++) a[s[i] -'a']++;
   
   int oddc = 0;
   for(int i = 0; i < 26; i++)
   {
      if(a[i] % 2 == 1) oddc++;
   }
   if(n % 2 == 0)
   {
      if(oddc == 0)
      {
         cout << "First" << endl;
         return;
      }
      else cout << "Second" << endl;
   }
   else
   {
      cout << "First" << endl;
   }
}
void solve450B()
{
   int x, y, n, mod = (int)1e9 + 7;
   cin >> x >> y;
   cin >> n;
   n--;
   vector<int>a(6);
   a[0] = (x + mod) % mod, a[1] = (y + mod) % mod;
   for(int i = 2; i < 6; i++)
   {
      if(a[i - 1] - a[i - 2] >= 0)a[i] = (a[i - 1] - a[i - 2]) % mod;
      else a[i] = (a[i - 1] - a[i - 2] + mod) % mod;
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   cout << a[(n % 6)] << endl;
}
void solve1538C()
{
   int n, l, r;
   cin >> n >> l >> r;
   vector<int> a(n);
   map<int, pair<int, int>>mp;
   for(auto & e : a) {cin >> e; mp[e].first++, mp[e].second = 0;}
   sort(a.begin(), a.end());
   
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      int f = l - a[i];
      //if(f <= 0) f = l;
      int s = r - a[i];
      //if(s <= 0) s = r;
      //cout << f << " " << s << endl;
      if(s < a[i])
      {
         ans += 0;
         continue;
      }
      else if(f > a[i])
      {
         int ff = lower_bound(a.begin(), a.end(), f) - a.begin();
         int ss = upper_bound(a.begin(), a.end(), s) - a.begin();
         ans += (ss - ff);
         //cout <<"else if "<< ans << endl;
      }
      else
      {
         int ff = lower_bound(a.begin(), a.end(), a[i] + 1) - a.begin();
         int ss = upper_bound(a.begin(), a.end(), s) - a.begin();
         //if(a[i] == 8) cout << ff << " " << ss << endl;
         ans += (ss - ff);
         //cout << ans << endl;
         mp[a[i]].second = 1;
         /*int cnt = mp[a[i]];
         cout << cnt << endl;
         mp[a[i]]--;
         ans += ((cnt * 1ll * (cnt - 1)) / 2);*/
         
      }
   }
   /*for(auto elem : mp)
   {
      cout << elem.first << " " << elem.second.first << " " << elem.second.second << " ";
   }*/
   for(auto elem : mp)
   {
      if(elem.second.second == 1)
      {
         int cnt = elem.second.first;
         ans += ((cnt * 1ll * (cnt - 1)) / 2);
      }
   }
   cout << ans << endl;
}
void solve1409C()
{
   ll n;
   cin >> n;
   set<ll> st;
   for(ll i = 1; i <= (ll)1e5; i++) st.insert(i * 1ll * i * i);
   for(auto it = st.begin(); (*it) <= n; it++)
   {
      ll curr = *it;
      ll need = n - curr;
      if(st.count(need))
      {
         cout << "YES" << endl;
         return;
      }
   }
   cout << "NO" << endl;
}

void solve1360E()
{
   int n;
   cin >> n;
   vector<vector<int>>a(n, vector<int>(n));
   
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < n; j++)
      {
         a[i][j] = s[j] - '0';
      }
   }
   /*for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++) cout << a[i][j] << " ";
      cout << endl;
   }*/
   for(int i = n - 2; i >= 0; i--)
   {
      for(int j = n - 2; j >= 0; j--)
      {
         //cout << a[i][j] << " " << a[i][j + 1] << " " << a[i + 1][j] << endl;
         if(a[i][j] == 1 && a[i][j + 1] == 0 && a[i + 1][j] == 0) 
         {
            cout << "NO" << endl;
            return;
         }
      }
   }
   cout << "YES" << endl;
}

void solve1367C()
{
   int n, k;
   cin >> n >> k;
   string s, s1 = string(k, '0'), s2 = "1";
   cin >> s;
   s = s2 + s1 + s + s1 + s2;
   //cout << s << endl;
   n = s.size();
   vector<int> ones;
   for(int i = 0; i < n; i++)
   {
      if(s[i] == '1') ones.push_back(i);
   }
   int n1 = ones.size();
   ll ans = 0;
   //for(auto elem : ones) cout << elem << " "; cout << endl;
   for(int i = 0; i + 1 < n1; i++)
   {
      int cnt = ones[i + 1] - ones[i] - 1;
      int rem = max(0 , cnt - (k * 2));
      ans += (rem + k) / (k + 1);
   }
   cout << ans << endl;
}
void solve1324B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   map<int, int> cnt;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      cnt[a[i]]++;
   }
   for(int i = 0; i + 1 < n; i++)
   {
      if(a[i] == a[i + 1] && cnt[a[i]] == 2) cnt[a[i]]--;
   }
  /* for(auto elem : cnt)
   {
      cout << "("<<elem.first <<" "<<elem.second << ") ";
   }
   cout << endl;*/
   for(auto elem : cnt)
   {
      if(elem.second > 1)
      {
         cout << "YES" << endl;
         return;
      }
   }
   cout << "NO" << endl;
}
void solve1714D()
{
   string text;
   cin >> text;
   int n;
   cin >> n;
   vector<string> a(n);
   
   for(int i = 0; i < n; i++) 
   {
      string s;
      cin >> s;
      a[i] = s;
   }
   
   vector<pair<int, int>> ans;
   int p = text.size(), moves = 0, start = 0, end = 0;
   int maxi = -1;
   
   for(int i = 0; i < n; i++)
   {
      int curr = 0;
      int k = 0;
      for(; k < a[i].size(); k++)
      {
         if(curr < p && text[curr] == a[i][k]) curr++;
         else break;
      }
      if(k == a[i].size())
      {
         if(k > end)
         {
            end = k;
            maxi = i;
         }
      }
   }
   if(maxi != -1) 
   {
      moves++; 
      ans.push_back({maxi, 0});
      
   }
   else {cout << -1 << endl; return;}
   start++;
   while(end < p)
   {
      //cout << "end < p " << end << endl;
      int maxforall = -1, currstr = -1, curridx = -1;
      for(; start <= min(end, p - 1); start++)
      {
         //cout << start << " " << end << endl;
         maxi = -1; 
         int currstr2 = -1, curridx2 = -1;
         for(int i = 0; i < n; i++)
         {
            int k = 0;
            int newend = start;
            for(; k < a[i].size(); k++)
            {
               if(newend < p && text[newend] == a[i][k]) newend++;
               else break;
            }
            //cout << newend << endl;
            if(k == a[i].size())
            {
               //cout << "matched string for "<< text[start] <<" " << a[i] << endl;
               //cout << "for this my newend " << newend <<" and end " << end << endl;
               if(newend > end)
               {
                  //maxi = max(maxi, newend);
                  if(newend > maxi)
                  {
                     maxi = newend;
                     currstr2 = i;
                     curridx2 = start;
                  }
               }
            }
         }
         if(maxforall < maxi)
         {
            maxforall = maxi;
            currstr = currstr2;
            curridx = curridx2;
         }
         //cout << "maxi " << maxi << " currstr2 " <<currstr2<<" curridx2 " << curridx2 << endl;
         //cout << "maxFA " << maxforall << " currstr " <<currstr<<" curridx " << curridx << endl;
      }
      if(maxforall != -1)
      {
         moves++;
         //cout << "push back " << curridx <<": curridx currstr: " << currstr <<endl;
         //cout << a[currstr] << " " << curridx << endl;
         ans.push_back({currstr, curridx});
         end = maxforall;
      }
      else
      {
         cout << -1 << endl;
         return;
      }
   }
   
   cout << moves << endl;
   for(auto elem : ans) cout << elem.first + 1 << " " << elem.second + 1 << endl;
   
}
void solve1401C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   vector<int> b(a);
   sort(b.begin(), b.end());
   int mini = b[0];
   
   for(int i = 0; i < n; i++)
   {
      if((a[i] == b[i]) || ((a[i] % mini) == 0)) continue;
      else
      {
         cout << "NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
}

void solve600B()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n), b(m);
   for(auto & e : a) cin >> e;
   for(auto & e : b) cin >> e;
   sort(a.begin(), a.end());
   for(int i = 0; i < m; i++)
   {
      int x = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
      cout << x << " ";
   }
   cout << endl;
}

void solve1712B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++) a[i] = i;
   for(int i = n; i - 1 >= 1; i = i - 2)
   {
      swap(a[i], a[i - 1]);
   }
   
   for(int i = 1; i <= n; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

void solve1712A()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1);
   //int sum1 = 0, sum2 = (k * (k + 1)) / 2;
   int moves = 0;
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      if(i <= k && a[i] > k) moves++;
   }
   cout << moves << endl;
}

solve1712C()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), cnt(n + 1, 0);
   vector<pair<int, int>> b(n + 1, {-1, -1});
   for(int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      a[i] = x;
      cnt[a[i]]++;
      if(b[a[i]].first == -1)  b[a[i]].first = i;
      b[a[i]].second = i;
   }
   
   //for(auto elem : b) cout <<"(" << elem.first << " " << elem.second <<")"; cout << endl
   int left = n, right = n;
   for(int i = n; i - 1 >= 1; i--)
   {
      if(a[i] >= a[i - 1])
      {
         left = i - 1;
         continue;
      }
      else
      {
         left = i;
         break;
      }
   }
   //if(left == n) left = 1;
   
   int marked = -1;
   for(int i = left; i <= right; i++)
   {
      if(b[a[i]].first < left)
      {
         marked = i;
      }
   }
   int moves = 0;
   cout << left << " " << right << " " << marked << endl;
   if(marked == -1) marked = left - 1;
   
   for(int i = 1; i <= marked; i++)
   {
      if(cnt[a[i]] > 0) 
      {
         moves++;
         cnt[a[i]] = 0;
      }
   }
   cout << moves << endl;
   
}

void solve1454C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   vector<vector<pair<int, int>>> b(n + 1);
   for(int i = 0; i < n; i++) cin >> a[i];
   
   for(int i = 0; i < n; i++)
   {
      int curr = a[i];
      int start = i;
      int end = i;
      int j = i;
      while(j < n && curr == a[j])
      {
         j++;
      }
      end = j - 1;
      b[curr].push_back({start, end});
      i = j - 1;
   }
   for(int i = 0; i <= n; i++)
   {
      //cout << i << " ";
      for(int j = 0; j < b[i].size(); j++)
      {
         //cout << "(" << b[i][j].first << " " << b[i][j].second << ")";
      }
      //cout << endl;
   }
   
   vector<int> cnt(n + 1, 0);
   for(int i = 1; i <= n; i++)
   {
      cnt[i] = (b[i].size() > 0 ? b[i].size() : INT_MAX);
      if(b[i].size() > 0 && b[i][0].first == 0) cnt[i]--;
      if(b[i].size() > 0 && b[i][b[i].size() - 1].second == n - 1) cnt[i]--;
   }
   int mini = INT_MAX;
   for(int i = 1; i <= n; i++)
   {
      mini = min(mini, cnt[i]);
      //cout << cnt[i] << " ";
   }
   cout << mini + 1 <<  endl;
}
void solve349A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e : a) cin >> e;
   
   int curr25 = 0, curr50 = 0;
   for(int i = 0; i < n; i++)
   {
      if(a[i] == 25) curr25++;
      else if(a[i] == 50)
      {
         if(curr25 > 0)
         {
            curr25--;
            curr50++;
         }
         else
         {
            cout << "NO" << endl;
            return;
         }
      }
      else
      {
         if(curr50 > 0)
         {
            curr50--;
            if(curr25 > 0)
            {
               curr25--;
            }
            else
            {
               cout << "NO" << endl;
               return;
            }
         }
         else
         {
            if(curr25 >= 3)
            {
               curr25 -= 3;
            }
            else
            {
               cout << "NO" << endl;
               return;
            }
         }
      }
      //cout << curr25 << " hey " << curr50 << endl;
   }
   cout << "YES" << endl;
}

void solve1420B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e : a) cin >> e;
   sort(a.begin(), a.end());
   
   int left = 1, right = 1;
   ll ans = 0;
   for(int i = 0; i <= 30; i++)
   {
      if(i > 0)
      {
         left = left * 2;
         right = right * 2 + 1;
      }
      int lbound = lower_bound(a.begin(), a.end(), left) - a.begin();
      int rbound = upper_bound(a.begin(), a.end(), right) - a.begin();
      int total = rbound - lbound;
      ans += (total * (total - 1)) / 2;
   }
   cout << ans << endl;
}

void solve1719B()
{
   int n, k;
   cin >> n >> k;
   vector<int> a, b;
   for(int i = 1; i <= n; i++)
   {
      if(i % 4 == 0) a.push_back(i);
      else
      {
         if((i + k) % 4 == 0) a.push_back(i);
         else b.push_back(i);
      }
   }
   if(k == 0 || k % 4 == 0)
   {
      cout << "NO" << endl;
      return;
   }
   
   if(a.size() != b.size())
   {
      cout << "YES" << endl;
      if(a.size() > b.size())
      {
         cout << a[0] << " " << a[1] << endl;
         for(int i = 0; i < a.size(); i++)
         {
            if(i % 2 == 0)
            {
               cout << a[i + 2] << " " << b[i] << endl;
            }
            else  cout << b[i] << " " << a[i + 2] << endl;
         }
      }
      else 
      {
         cout << b[0] << " " << b[1] << endl;
         for(int i = 0; i < a.size(); i++)
         {
            if(i % 2 == 0)
            {
               cout << a[i] << " " << b[i + 2] << endl;
            }
            else  cout << b[i + 2] << " " << a[i] << endl;
         }
      }
   }
   else
   {
      cout << "YES" << endl;
      for(int i = 0; i < a.size(); i++)
      {
         if(i % 2 == 0)
         {
            cout << a[i] << " " << b[i] << endl;
         }
         else  cout << b[i] << " " << a[i] << endl;
      }
   }
}

void solve1334B()
{
   ll n, x;
   cin >> n >> x;
   vector<ll> a(n), pref(n);
   for(auto & e : a) cin >> e;
   sort(a.begin(), a.end(), greater<ll> ());
   ll sum = 0, ans = 0;
   for(int i = 0; i < n; i++)
   {
      sum += a[i];
      if(sum / (i + 1) >= x) ans++;
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   cout << ans << endl;
}

void solve1719C()
{
   int n, q;
   cin >> n >> q;
   list<pair<int, int>> a;
   vector<vector<int>> b(n + 1);
   int maxi = 0;
   for(int id = 1; id <= n; id++)
   {
      int strength;
      cin >> strength;
      if(strength == n) maxi = id;
      a.push_back({strength, id});
   }
   //for(auto elem : a) cout << "("  << elem.first << " " << elem.second <<")"; cout << endl;
   for(int i = 1; i <= n; i++)
   {
      auto it1 = a.begin();
      auto it2 = a.begin();
      advance(it2, 1);
      //cout << (*it1).first << " " << (*it2).first <<  endl;
      
      int strength1 = (*it1).first;
      int id1 = (*it1).second;
      
      int strength2 = (*it2).first;
      int id2 = (*it2).second;
      if(strength1 > strength2)
      {
         b[id1].push_back(i);
         a.push_back({strength2, id2});
         a.erase(it2);
      }
      else if(strength1 < strength2)
      {
         b[id2].push_back(i);
         a.push_back({strength1, id1});
         a.erase(it1);
      }
      //for(auto elem : a) cout << elem.first << " "; cout << endl;
   }
   
   /*for(int i = 1; i <= n; i++)
   {
      cout << "id " << i << " rounds ";
      for(int j = 0; j < b[i].size(); j++) cout << b[i][j] << " "; cout << endl;
   }*/
   while(q--)
   {
      int i, k;
      cin >> i >> k;
      int t = upper_bound(b[i].begin(), b[i].end(), k) - b[i].begin();
      //cout << t << endl;
      if(i != maxi) cout << t << endl;
      else
      {
         if(k <= b[maxi].back()) cout << t << endl;
         else cout << k - b[maxi][0] + 1 << endl;
      }
   }
}

void solve1345B()
{
   ll n;
   cin >> n;
   ll cnt = 0;
   while(n >= 2)
   { 
      ll low = 0, high = 100000, ans = -1;
      while(low <= high)
      {
         ll mid = (low + high) / 2;
         if( (3 * 1ll * mid * mid + 7 * mid + 4) <= (2 * 1ll * n) )
         {
            ans = mid;
            low = mid + 1;
         }
         else if( (3 * 1ll * mid * mid + 7 * mid + 4) > (2 * 1ll * n) )
         {
            high = mid - 1;
         }
      }
      //cout << "ans " << ans << endl;
      cnt++;
      ll need = ((3 * 1ll * ans * ans + 7 * ans + 4)) / 2;
      n -= need;
      //cout << n << endl;
   }
   cout << cnt << endl;
}


void solve1715B()
{
   ll n, k, b, s;
   cin >> n >> k >> b >> s;
   
   ll mini = b * 1ll * k;
   ll maxi = mini + (k - 1) + ((n - 1) * (k - 1));
   if(s < mini || s > maxi)
   {
      cout << -1 << endl;
      return;
   }
   
   vector<ll> a(n);
   for(int i = 0; i < n; i++)
   {
      ll low = b * 1ll * k;
      ll high = b * 1ll * k + (k - 1);
      ll ans = -1;
      
      while(low <= high)
      {
         ll mid = (low + high + 0ll) / 2;
         if(s - mid >= 0)
         {
            ans = mid;
            low = mid + 1;
         }
         else
         {
            high = mid - 1;
         }
      }
      //cout << ans << " ";
      a[i] = ans;
      s -= ans;
      b = 0;
   }
   
   for(auto elem : a) cout << elem << " "; cout << endl;
}

void solve1715A()
{
   int n, m;
   cin >> n >> m;
   int moves = 0;
   
   if(n == 1 && m == 1)
   {
      cout << moves << endl;
      return;
   }
   else if(m == 1)
   {
      cout << n << endl;
      return;
   }
   else if (n == 1)
   {
      cout << m << endl;
      return;
   }
   else
   {
      int maxi = max(n, m);
      int mini = min(n, m);
      cout << maxi - 1 + mini - 1 + mini << endl;;
   }
   
}

void solve1713C()
{
   int n; 
   cin >> n;
   vector<int> a(1001), ans(n);
   for(int i = 0;  i < a.size(); i++) a[i] = i * i;
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //int tofind = upper_bound(a.begin(), a.end(), 2 * (n - 1)) - a.begin();
   //tofind--;
   
   for(int i = n - 1; i >= 0; i--)
   {
      int tofind = upper_bound(a.begin(), a.end(), 2 * i) - a.begin();
      tofind--;
      int st = i;
      int en = a[tofind] - st;
      int toput = en;
      
      for(int j = st; j >= en; j--) 
      {
         ans[j] = toput++;
      }
      
      i = en;
   }
   for(auto elem : ans) cout << elem << " "; cout << endl;
}

void solve1433D()
{
   int n;
   cin >> n;
   vector<int> a(n);
   vector<pair<int, int>> ans;
   unordered_map<int, vector<int>> mp;
   for(int i = 0; i < n; i++) 
   {
      cin >> a[i];
      mp[a[i]].push_back(i + 1);
   }
   
   /*for(auto elem : mp)
   {
      cout << elem.first << " ";
      for(auto e : elem.second)
      {
         cout << e << " ";
      }
      cout << endl;
   }*/
   
   if(mp.size() <= 1) 
   {
      cout << "NO" << endl;
      return;
   }
   
   unordered_map<int, vector<int>> :: iterator it;
   it = mp.begin();
   
   vector<int> :: iterator it2 = it->second.begin();
   
   int ff = *it2;
   it++;
   
   for(; it != mp.end(); it++)
   {
      for(it2 = it->second.begin(); it2 != it->second.end(); it2++)
      {
         int ss = *it2;
         ans.push_back({ff, ss});
      }
   }
   
   it = mp.begin();
   it++;
   it2 = it->second.begin();
   
   ff = *it2;
   
   it = mp.begin();
   it2 = it->second.end();
   --it2;
   for(; it2 > it->second.begin(); --it2)
   {
      int ss = *it2;
      ans.push_back({ff, ss});
   }
   
   cout << "YES" << endl;
   for(auto elem : ans) cout << elem.first << " " << elem.second << endl;   
}

void solve478A()
{
   int sum = 0;
   for(int i = 0; i < 5; i++)
   {
      int x;
      cin >> x;
      sum += x;
   }
   
   int fd = sum / 5;
   int cd = (sum + 4) / 5;
   if(fd > 0 && fd == cd) cout << fd << endl;
   else cout << -1 << endl;
}

void solve1365A()
{
   int n, m;
   cin >> n >> m;
   vector<bool> row(n, false), col(m, false);
   int t = n + m, cr = n, cc = m;
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < m; j++)
      {
         int x;
         cin >> x;
         if(x == 1) 
         {
            if(row[i] == false && col[j] == false)
            {
               cr--; cc--;
               row[i] = true;
               col[j] = true;
            }
            else if(col[j] == true && row[i] == false)
            {
               cr--;
               row[i] = true;
            }
            else if(row[i] == true && col[j] == false)
            {
               cc--;
               col[j] = true;
            }
         }
      }
   }
   
   int moves = min(cc, cr);
   if(moves % 2 == 1) cout << "Ashish" << endl;
   else cout << "Vivek" << endl;
}

void solve1497C1()
{
   int n, k;
   cin >> n >> k;
   int ans1, ans2, ans3;
   if(n % 3 == 0)
   {
      ans1 = n / 3;
      ans2 = ans3 = ans1;
      //cout << ans1 << " " << ans1 << " " << ans1 << endl;
      //return;
   }
   else if (n % 3 == 1)
   {
      if(n % 2 == 1)
      {
         ans1 = 1;
         ans2 = (n - 1) / 2;
         ans3 = (n - 1) / 2;
      }
      else if(n % 2 == 0)
      {
         int divi = n / 2;
         int rem = n - divi;
         if(rem % 2 == 0)
         {
            ans1 = divi;
            ans2 = rem / 2;
            ans3 = rem / 2;
         }
         else if(rem % 2 == 1)
         {
            ans1 = 2;
            ans2 = divi - 1;
            ans3 = divi - 1;
         }
      }
   }
   else if(n % 3 == 2)
   {
      if(n % 2 == 1)
      {
         ans1 = 1;
         ans2 = (n - 1) / 2;
         ans3 = (n - 1) / 2;
      }
      else if(n % 2 == 0)
      {
         int divi = n / 2;
         int rem = n - (n / 2);
         if(rem % 2 == 0)
         {
            ans1 = divi;
            ans2 = rem / 2;
            ans3 = rem / 2;
         }
         else if (rem % 2 == 1)
         {
            ans1 = 2;
            ans2 = divi - 1;
            ans3 = divi - 1;
         }
      }
   }
   cout << ans1 << " " << ans2 << " " << ans3 << endl;
}

void solve4B()
{
   int d, sum, minisum = 0, maxisum = 0;
   cin >> d >> sum;
   vector<pair<int, int>> a(d);
   for(int i = 0; i < d; i++)
   {
      int x, y;
      cin >> x >> y;
      minisum += x;
      maxisum += y;
      a[i] = {x, y};
   }
   if(sum < minisum || sum > maxisum)
   {
      cout << "NO" << endl;
      return;
   }
   cout << "YES" << endl;
   int diff;
   if(sum - minisum < maxisum - sum)
   {
      diff = sum - minisum;
      for(int i = 0; i < d; i++)
      {
         if(diff == 0) break;
         int take = min(a[i].second - a[i].first, diff);
         a[i].first += take;
         diff -= take;
      }
      
      for(auto elem : a) cout << elem.first <<" "; cout << endl;
   }
   
   else
   {
      diff = maxisum - sum;
      for(int i = 0; i < d; i++)
      {
         if(diff == 0) break;
         int take = min(a[i].second - a[i].first, diff);
         a[i].second -= take;
         diff -= take;
      }
      
      for(auto elem : a) cout << elem.second <<" "; cout << endl;
   }
}

void solve1721A()
{
   string s1, s2;
   cin >> s1;
   cin >> s2;
   map<char, int> mp;
   for(int i = 0; i < 2; i++)
   {
      mp[s1[i]]++;
      mp[s2[i]]++;
   }
   
   int cnt = 0;
   for(auto elem : mp)
   {
      if(elem.second == 1) cnt++;
   }
   
   cout << mp.size() - 1 << endl;
}

void solve1721B()
{
   int n, m, x, y, d;
   cin >> n >> m >> x >> y >> d;
   int top = max(x - d, 1);
   int bot = min(x + d, n);
   int left = max(y - d, 1);
   int right = min(y + d, m);
   
   if(top == 1 && bot == n || left == 1 && right == m || bot == n && right == m || top == 1 && left == 1)
   {
      cout << -1 << endl;
      return;
   }
   cout << n + m - 2 << endl;
   
}


void solve1206B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   ll sum = 0, cntp = 0, cntn = 0, cntz = 0;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x < 0) 
      {
         sum += -1 - x;
         a[i] = -1;
         cntn++;
      }
      else if(x > 0)
      {
         sum += x - 1;
         a[i] = 1;
         cntp++;
      }
      else cntz++;
   }
   
   if(n % 2 == 0)
   {
      if(cntz == 0)
      {
         if(cntn % 2 == 1) sum += 2;
      }
      else
      {
         sum += cntz;
      }
   }
   else 
   {
      if(cntz == 0)
      {
         if(cntn % 2 == 1) sum += 2;
      }
      else
      {
         sum += cntz;
      }
   }
   cout << sum << endl;
}

void solve1721C()
{
   int n;
   cin >> n;
   vector<int> a(n), b(n), dmx(n);
   for(auto & e : a) cin >> e;
   for(auto & e : b) cin >> e;
   
   int j = 0;
   for(int i = 0; i < n; i++)
   {
      while(b[j] < a[i]) j++;
      cout << b[j] - a[i] <<" ";
   }
   
   int curr = n - 1;
   for(int i = n - 1; i >= 0; i--)
   {
      if(i == n - 1) {dmx[i] = b[i] - a[i]; continue;}
      
      if(b[i] >= a[i + 1])
      {
         dmx[i] = b[curr] - a[i];
      }
      else
      {
         dmx[i] = b[i] - a[i];
         curr = i;
      }
   }
   cout << endl;
   for(auto elem : dmx) cout << elem << " "; cout << endl;
}


void solve1722C()
{
   int n;
   cin >> n;
   map<string, int> mp;
   vector<vector<string>> a(3, vector<string>(n));
   for(int i = 0; i <= 2; i++)
   {
      for(int j = 0; j < n; j++)
      {
         string s;
         cin >> s;
         a[i][j] = s;
         mp[s]++;
         
      }
   }
   
   for(int i = 0; i < 3; i++)
   {
      ll points = 0;
      for(int j = 0; j < n; j++)
      {
         if(mp[a[i][j]] == 1) points += 3;
         else if (mp[a[i][j]] == 2) points += 1;
      }
      cout << points << " ";
      
   }
   cout << endl;
}



void solve1722B()
{
   int n;
   cin >> n;
   string s1, s2;
   cin >> s1;
   cin >> s2;
   
   for(int i = 0; i < n; i++)
   {
      if(s1[i] == 'G') s1[i] = 'B';
      if(s2[i] == 'G') s2[i] = 'B';
   }
   
   for(int i = 0; i < n; i++)
   {
      if(s1[i] != s2[i])
      {
         cout << "NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
}

void solve1722A()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   //cout << n << s << endl;
   
   if(n != 5)
   {
      cout << "NO" << endl;
      return;
   }
   
   map<char, int> mp; 
   int cnt = 0;
   string s1 = "Timur";
   for(int i = 0; i < s1.size(); i++)
   {
      mp[s1[i]]++;
      if(mp[s1[i]] == 1) cnt++;
   }
   
   
   for(int i = 0; i < n; i++)
   {
      mp[s[i]]--;
      if(mp[s[i]] == 0) cnt--;
   }
   
   if(cnt == 0) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1722D()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   
   ll sum = 0;
   for(int i = 0; i < n; i++)
   {
      if(s[i] == 'L') sum += i;
      else sum += n - i - 1;
   }
   
   vector<int> l, r;
   for(int i = 0; i < n / 2; i++)
   {
      if(s[i] == 'L') l.push_back(i);
   }
   
   for(int i = n - 1; i >= (n - (n / 2)); i--)
   {
      if(s[i] == 'R') r.push_back(i);
   }
   
   //for(auto elem : l) cout << elem << " "; cout << endl;
   //for(auto elem : r) cout << elem << " "; cout << endl;
   //cout << sum << endl;
   int i = 0, j = 0;
   
   int ls = l.size(), rs = r.size();
   
   int k = 0;
   
   while(i < ls && j < rs)
   {
      int x = l[i];
      int y = r[j];
      
      if(x <= n - 1 - y)
      {
         //choosing i
         sum -= x;
         sum += n - 1 - x;
         i++;
         cout << sum << " ";
         k++;
      }
      
      else
      {
         //choosing j
         sum -= n - 1 - y;
         sum += y;
         j++;
         cout << sum << " ";
         k++;
      }
   }
   
   while(i < ls)
   {
      int x = l[i];   
      sum -= x;
      sum += n - 1 - x;
      i++;
      cout << sum << " ";
      k++;
   }
   
   while(j < rs)
   {
      int y = r[j];   
      sum -= n - 1 - y;
      sum += y;
      j++;
      cout << sum << " ";
      k++;
   }

   while(k < n) {cout << sum << " "; k++;}
   cout << endl;
}

void solve285C()
{
   int n;
   cin >> n;
   set<int> us;
   multiset<int> a;
   for(int i = 1; i <= n; i++) us.insert(i);
   ll moves = 0;
   
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(us.find(x) != us.end()) us.erase(x);
      else a.insert(x);
   }
   
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //for(auto elem : us) cout << elem << " "; cout << endl;
   
   multiset<int> :: iterator it1;
   set<int> :: iterator it2;
   it1 = a.begin();
   it2 = us.begin();
   
   while(it1 != a.end() && it2 != us.end())
   {
      moves += abs(*it1 - *it2);
      it1++;
      it2++;
   }
   
   cout << moves << endl;
}
void solve1722E()
{
   ll n, q, k = 1000;
   cin >> n >> q;
   vector<vector<ll>> pref(k + 1, vector<ll>(k + 1, 0));
   
   for(ll i = 1; i <= n; i++)
   {
      ll x, y;
      cin >> x >> y;
      pref[x][y] += x * 1ll * y;
   }
   
   for(int i = 1; i <= k; i++)
   {
      for(int j = 2; j <= k; j++) pref[i][j] = pref[i][j] + pref[i][j - 1];
   }
   
   for(int j = 1; j <= k; j++)
   {
      for(int i = 2; i <= k; i++) pref[i][j] = pref[i][j] + pref[i - 1][j];
   }
   
   while(q--)
   {
      int h1, w1, h2, w2;
      cin >> h1 >> w1 >> h2 >> w2;
      h1++, w1++, h2--, w2--;
      cout << pref[h2][w2] - pref[h1 - 1][w2] - pref[h2][w1 - 1] + pref[h1 - 1][w1 - 1] << endl;
   }
}

void solve1512D()
{
   int n;
   cin >> n;
   vector<int> b(n + 2);
   for(auto & e : b) cin >> e;
   sort(b.begin(), b.end());
   
   ll ts = 0;
   for(int i = 0; i < n; i++)
   {
      ts += b[i];
   }
   
   if(ts == b[n])
   {
      for(int i = 0; i < n; i++) cout << b[i] << " "; 
      cout << endl;
      return;
   }
   
   ts += b[n];
   
   int mark = -1;
   for(int i = 0; i <= n; i++)
   {
      if(ts - b[i] == b[n + 1])
      {
         mark = i; 
         break;
      }
   }
   
   if(mark == -1)
   {
      cout << -1 << endl;
   }
   
   else
   {
      for(int i = 0; i <= n; i++)
      {
         if(i != mark) cout << b[i] << " ";
      }
      cout << endl;
   }
}

void solve1717C()
{
   int n;
   cin >> n;
   vector<int>a(n + 1), b(n + 1);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++) cin >> b[i];
   a[n] = a[0], b[n] = b[0];
   
   for(int i = 0; i < n; i++)
   {
      if(a[i] > b[i]) 
      {
         cout << "NO" << endl;
         return;
      }
   }
   
   for(int i = n - 1; i >= 0; i--)
   {
      if(a[i] == b[i]) continue;
      if(b[i] - 1 > b[i + 1])
      {
         cout << "NO" << endl;
         return;
      }
   }
   
   cout << "YES" << endl;
}

void solve1725B()
{
   int n, d;
   cin >> n >> d;
   vector<ll> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   int ans = 0;
   
   if(d < a[0]) ans = n;
   else
   {
      int x = upper_bound(a.begin(), a.end(), d) - a.begin();
      int l = 0, r = x - 1;
      ans += n - x;
      for(; l < r; r--)
      {
         int sum = a[r];
         while(l < r && sum <= d)
         {
            sum += a[r];
            l++;
         }
         if(sum > d) ans++;
         //cout <<  sum << endl;
      }
      
      if(l == r && a[r] > d) ans++;
      //cout << l << " " << r << " "<< endl;
   }
   cout << ans << endl;
}



void solve1725A()
{
   int n, m;
   cin >> n >> m;
   if(m == 1) cout << n - 1 << endl;
   else cout << (m - 1) * 1ll * n << endl;
}

void solve839A()
{
   int n, k;
   cin >> n >> k;
   vector<int> pref(n), a(n);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a[i] = x;
      
   }
   
   int curr = 0;
   for(int i = 0; i < n; i++)
   {
      if(a[i] >= 8)
      {
         k -= 8;
         curr += a[i] - 8;
      }
      else
      {
         a[i] += curr;
         k -= min(8, a[i]);
         curr = max(0, a[i] - 8);
      }
      if(k <= 0)
      {
         cout << i + 1 << endl;
         return;
      }
   }
   cout << -1 << endl;
   
}

void solve1726C()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   vector<int>a;
   for(int i = 0; i < 2 * n; i++)
   {
      if(s[i] == '(') a.push_back(i + 1);
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   int ans = n;
   for(int i = 0; i + 1 < n; i++)
   {
      if(a[i + 1] - a[i] > 1) ans--;
   }
   cout << ans << endl;
}

void solve1006C()
{
   ll n;
   cin >> n;
   vector<ll> pref(n), suff(n);
   for(int i = 0; i < n; i++)
   {
      ll x;
      cin >> x;
      pref[i] = x;
      suff[i] = x;
   }
   
   for(ll i = 1; i < n; i++) pref[i] += pref[i - 1];
   for(ll i = n - 2; i >= 0; i--) suff[i] += suff[i + 1];
   
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   //for(auto elem : suff) cout << elem << " "; cout << endl;
   ll l = 0, r = n - 1, ans = 0;
   
   while(l < r)
   {
      if(pref[l] == suff[r])
      {
         ans = pref[l];
         l++;
         r--;
      }
      else if(pref[l] > suff[r])
      {
         r--;
      }
      else l++;
      
   }
   cout << ans << endl;
}

void solve1728B()
{
   int n;
   cin >> n;
  
   
   if(n % 2 == 0)
   {
      for(int i = n - 2; i >= 1; i--) cout << i << " ";
      cout << n - 1 << " " << n << endl;
      
   }
   else
   {
      for(int i = 1; i <= n; i++)
      {
         if(i == 1 || i >= n - 1) cout << i << " ";
         else if(i % 2 == 0) cout << i + 1 << " ";
         else if(i % 2 == 1) cout << i - 1 << " ";
      }
      cout << endl;
   }
   
}

void solve6C()
{
   int n;
   cin >> n;
   vector<int> pref(n), suff(n);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      pref[i] = suff[i] = x;
   }
   for(int i = 1; i < n; i++) pref[i] += pref[i - 1];
   for(int i = n - 2; i >= 0; i--) suff[i] += suff[i + 1];
   
   int diff = INT_MAX, mark = -1;
   for(int i = 0; i < n; i++)
   {
      if(abs(pref[i] - suff[i]) < diff)
      {
         diff = abs(pref[i] - suff[i]);
         mark = i;
      }
   }
   int alice , bob;
   if(pref[mark] <= suff[mark]) {alice = mark + 1; bob = n - mark - 1;}
   else {alice = mark; bob = n - mark;}
   
   cout << alice << " " << bob << endl;
}


void solve1729A()
{
   int a, b, c;
   cin >> a >> b >> c;
   int ss = abs(b - c) + abs(c - 1);
   int ff = a - 1;
   if(ss == ff) cout << 3 << endl;
   else if(ff < ss) cout << 1 << endl;
   else cout << 2 << endl;
}

void solve1729B()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   unordered_map<int, char>mp;
   for(int i = 1; i <= 26; i++) mp[i] = 'a' + i - 1;
   //for(auto elem : mp) cout << "(" <<elem.first << " " << elem.second<<")"; cout << endl;
   
   int n1 = s.size();
   string output;
   for(int i = n1 - 1; i >= 0; i--)
   {
      if(s[i] == '0')
      {
         string curr;
         curr.push_back(s[i - 2]);
         curr.push_back(s[i - 1]);
         int cu = stoi(curr);
         output += mp[cu];
         i -= 2;
      }
      else
      {
         string curr;
         curr.push_back(s[i]);
         int cu = stoi(curr);
         output += mp[cu];
      }
   }
   reverse(output.begin(), output.end());
   cout << output << endl;
}

void solve1729C()
{
   string s;
   cin >> s;
   int n = s.size();
   int jumps = abs(s[0] - s[n - 1]);
   
   vector<vector<int>> ans(26);
   for(int i = 0; i < n; i++)
   {
      ans[s[i] - 'a'].push_back(i);
   }
   vector<char> a;
   a.push_back(s[0]);
   a.push_back(s[n - 1]);
   sort(a.begin(), a.end());
   vector<int> ans2;
   int st = s[0] - 'a';
   int en = s[n - 1] - 'a';
   if(st > en)
   {
      for(int i = st; i >= en; i--)
      {
         for(auto elem : ans[i]) ans2.push_back(elem + 1);
      }
   }
   else
   {
      for(int i = st; i <= en; i++)
      {
         for(auto elem : ans[i]) ans2.push_back(elem + 1);
      }
   }
   cout << jumps << " " << ans2.size() << endl;
   for(auto elem : ans2) cout << elem << " "; cout << endl;
}

void solve1539C()
{
   ll n, k, x;
   cin >> n >> k >> x;
   vector<ll> a(n);
   for(auto &e : a) cin >> e;
   sort(a.begin(), a.end());
   
   vector<ll> diff(n - 1);
   for(int i = 0; i < n - 1; i++) diff[i] = a[i + 1] - a[i];
   sort(diff.begin(), diff.end());
   
   ll ans = 0;
   for(int i = 0; i < n - 1; i++)
   {
      if(diff[i] <= x) continue;
      else
      {
         ll need = (diff[i]  - 1)/ x;
         //cout << "NEED " << need << endl;
         if(k >= need)
         {
            k -= need;
         }
         else ans++;
      }
   }
   cout << ans + 1 << endl;
}

void solve1327B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   vector<bool> b(n + 1, false);
   int mark = -1, mark2 = -1;
   for(int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      bool found = false;
      for(int j = 1; j <= x; j++)
      {
         int y;
         cin >> y;
         if(found == false)
         {
            if(b[y] == false)
            {
               b[y] = true;
               found = true;
            }
         }
         else continue;
      }
      if(found == false)
      {
         mark = i;
      }
   }
   
   for(int i = 1; i <= n; i++) 
   {
      if(b[i] == false) mark2 = i;
   }
   if(mark == -1)
   {
      cout << "OPTIMAL" << endl;
   }
   else 
   {
      cout << "IMPROVE" << endl;
      cout << mark << " " << mark2 << endl;
   }
}

void solve1256A()
{
   ll a, b, n, s;
   cin >> a >> b >> n >> s;
   if((a * 1ll * n + b) < s) cout << "NO" << endl;
   else if((a * 1ll * n + b) == s) cout << "YES" << endl;
   else
   {
      ll diff = (a * 1ll * n + b) - s;
      if(b >= diff) cout << "YES" << endl;
      else
      {
         ll divi = min(diff / n, a);
         ll rem = min(diff - (divi * n), b) ;
         if((divi * 1ll * n + rem) == diff) cout << "YES" << endl;
         else cout << "NO" << endl;
      }
   }
}

void solve1476A()
{
   int n, k;
   cin >> n >> k;
   if(n <= k)
   {
      int divi = k / n;
      int rem = k % n;
      if(rem == 0) cout << divi << endl;
      else cout << divi + 1 << endl;
   }
   else
   {
      int rem = n % k;
      if(rem == 0) cout << 1 << endl;
      else cout << 2 << endl;
   }
}

void solve1520C()
{
   int n;
   cin >> n;
   if(n == 2) {cout << - 1 << endl; return;}
   vector<vector<int>> a(n, vector<int>(n));
   a[0][n - 1] = n * n - 1;
   a[n - 1][0] = n * n;
   int row = 0, col = 0, put = 1;
   while(col <= n - 2)
   {
      int i = row, j = col;
      while(i <= n - 1 && j <= n - 1)
      {
         a[i][j] = put++;
         i++;
         j++;
      }
      col++;
   }
   row++, col = 0;
   while(row <= n - 2)
   {
      int i = row, j = col;
      while(i <= n - 1 && j <= n - 1) 
      {
         a[i][j] = put++;
         i++;
         j++;
      }
      row++;
   }
   
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++) cout << a[i][j] << " "; cout << endl;
   }
   cout << endl;
}

void solve1326A()
{
   int n;
   cin >> n;
   if(n == 1) {cout << -1 << endl; return;}
   string s(n, '3');
   s[0] = '2';
   cout << s << endl;
}

void solve1473B()
{
   string s, t;
   cin >> s >> t;
   if(s.size() < t.size()) swap(s, t);
   
   int flag = 0;
   if(s.find(t) != std::string::npos) flag = 1;
   cout << flag << endl;
}

void sove1733A()
{
   ll n, k, sum = 0;
   cin >> n >> k;
   vector<ll> maxi(k, 0);
   for(ll i = 1; i <= n; i++)
   {
      ll x;
      cin >> x;
      maxi[i % k] = max(maxi[i % k], x);
   }
   
   for(auto elem : maxi) sum += elem + 0ll;
   cout << sum << endl;
}

void solve1733B()
{
   int n, x, y;
   cin >> n >> x >> y;
   if( (x == 0 && y == 0) || (x > 0 && y > 0) )
   {
      cout << -1 << endl;
      return;
   }
   else
   {
      int total_match = n - 1;
      int k = max(x, y);
      if(total_match % k != 0)
      {
         cout << -1 << endl;
      }
      else
      {
         int i = 1, p = 1;
         bool first = false;
         while(p <= n - 1)
         {
            for(int j = 1; j <= k; j++)
            {
               cout << i << " ";
            }
            
            if(first == false) {i += k + 1; first = true;}
            else i += k;
            p += k;
         }
         cout << endl;
      }
   }
}


void solve450A()
{
   int n, m, maxi = INT_MIN, idx = -1;
   cin >> n >> m;
   vector<int> a(n);
   for(int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      if(maxi <= (x + m - 1) / m)
      {
         maxi = (x + m - 1) / m;
         idx = i;
      }
   }
   int ans = (idx == -1) ? n : idx;
   cout << ans  << endl;
}

void solve1733C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   int odds = 0, evens = 0;
   for(int i = 0; i < n; i++) 
   {
      cin >> a[i];
      if(a[i] % 2 == 0) evens++;
      else odds++;
   }
   
   /*if(odds == n || evens == n)
   {
      cout << n - 1 << endl;
      for(int i = 1; i <= n - 1; i++)
      {
         if(i == idx) continue;
         else cout << i << " " << idx << endl;
      }
      return;
   }*/
   if(n == 1)
   {
      cout << 0 << endl;
      return;
   }
   vector<pair<int, int>> ans;
   ans.push_back({1, n});
   bool odd = (a[0] % 2 == 1) ? true : false;
   if(!odd)
   {
      for(int i = 1; i <= n - 2; i++)
      {
         if(a[i] % 2 == 0) ans.push_back({i + 1, n});
         else ans.push_back({1, i + 1});
      }
      
   }
   else
   {
      for(int i = 1; i <= n - 2; i++)
      {
         if(a[i] % 2 == 0) ans.push_back({1, i + 1});
         else ans.push_back({i + 1, n});
      }
   }
   
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem.first << " " << elem.second << endl;
}

void solve545D()
{
   ll n; 
   cin >> n;
   vector<ll>a(n), pref(n + 1, 0);
   for(ll i = 0; i < n; i++)
   {
      cin >> a[i];
      
   }
   sort(a.begin(), a.end());
   for(ll i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   ll ans = 0, mark = -1;
   for(int i = 0; i < n; i++)
   {
      if(a[i] >= pref[i]) ans++;
      else {mark = i; break;}
   }
   
   int searched = -1;
   while(searched < n)
   {
      
      ll curr = pref[mark];
      ll st = 0, en = n - 1, idx = -1;
      while(st <= en)
      {
         ll mid = (st + en) / 2;
         if(a[mid] >= curr)
         {
            idx = mid;
            en = mid - 1;
         }
         else st = mid + 1;
      }
      searched = st;
      if(idx != -1)
      {
         ans++;
         pref[mark + 1] = pref[mark] + a[idx];
         mark = mark + 1;  
      }
      //else break;
      
   }
   cout << ans << endl;
}

void solve545DEasy()
{
   ll n; 
   cin >> n;
   vector<ll>a(n);
   for(ll i = 0; i < n; i++)
   {
      cin >> a[i];
      
   }
   sort(a.begin(), a.end());
   ll currwait = 0, ans = 0;
   for(ll i = 0; i < n; i++)
   {
      if(currwait <= a[i])
      {
         ans++;
         currwait += a[i];
      }
      else continue;
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   cout << ans << endl;
  
}
void solve1734A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   
   sort(a.begin(), a.end());
   int ans = INT_MAX;
   for(int i = 0; i <= n - 3 ; i++)
   {
      int ff = a[i + 1] - a[i];
      int ss = a[i + 2] - a[i + 1];
      if(ff + ss < ans)
      {
         ans = ff + ss;
      }
   }
   cout << ans << endl;
}

void solve1734B()
{
   int n;
   cin >> n;
   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= i; j++)
      {
         if(j == 1 || j == i) cout << 1 << " ";
         else cout << 0 << " ";
      }
      cout << endl;
   }
   cout << endl;
}

void solve508B()
{
   string s;
   cin >> s;
   int n = s.size();
   vector<int> possible;
   char maxi = '0', anothermaxi = '0'; int idx = -1, idx2 = -1;
   for(int i = 0; i < n; i++)
   {
      if(s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8') possible.push_back(i);
      if(s[i] >= maxi) {maxi = s[i]; idx = i;}
      if(s[i] >= anothermaxi && i < n - 1) {anothermaxi = s[i]; idx2 = i;}
   }
   
   //for(auto elem : possible) cout << elem << " "; cout << endl;
   //cout << maxi << " " << idx <<  endl;
   //cout << anothermaxi << " " << idx2 << endl;
   if(possible.size() == 0)
   {
      cout << -1 << endl;
      return;
   }
   if(possible.size() == 1)
   {
      swap(s[possible.back()], s[n - 1]);
      cout << s << endl;
      return;
   }
   
   if(s[n - 1] != '0' && s[n - 1]  != '2' && s[n - 1] != '4' && s[n - 1]  != '6' && s[n - 1] != '8')
   {
      //cout << "IF" << endl;
      int smaller = -1, greater = -1;
      for(int i = 0; i < n - 1; i++)
      {
         if(s[i] < s[n - 1] && (s[i] == '0' || s[i]  == '2' || s[i] == '4' || s[i]  == '6' || s[i] == '8'))
         {
            smaller = i;
            swap(s[i], s[n - 1]);
            break;
         }
         if(s[i] > s[n - 1] && (s[i] == '0' || s[i]  == '2' || s[i] == '4' || s[i]  == '6' || s[i] == '8'))
         {
            greater = i;
         }
      }
      
      if(smaller == -1) swap(s[greater], s[n - 1]);
      cout << s << endl;
   }
   else
   {
      string one = s;
      string two = s;
      bool swapped1 = false, swapped2 = false;;
      for(int i = 0; i < idx; i++)
      {
         if(one[i] < one[idx]) {swap(one[idx], one[i]); swapped1 = true; break;}
      }
      for(int i = 0; i < idx2; i++)
      {
         if(two[i] < two[idx2]) {swap(two[idx2], two[i]); swapped2 = true; break;}
      }
      
      if(one[n - 1]  == '2' || one[n - 1] == '4' || one[n - 1]  == '6' || one[n - 1] == '8')
      {
         cout << one << endl;
      }
      else cout  << two << endl;
      
   }
   
}

void solve1734C()
{
   ll n;
   cin >> n;
   string s;
   cin >> s;
   string t = "-";
   t += s;
   s = t;
   //cout << s << endl;
   vector<ll>a(n + 1);
   for(ll i = 1; i <= n; i++) a[i] = i;
   
   for(ll i = n; i >= 1; i--)
   {
      if(s[i] == '1') continue;
      else
      {
         ll cost = i;
         ll j = i;
         while(j <= n && s[j] == '0')
         {
            a[j] = cost;
            j += i;
         }
         //for(auto elem : a) cout << elem << " "; cout << endl;
         
      }
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   ll ans = 0;
   for(int i = 1; i <= n; i++)
   {
      if(s[i] == '0') ans += a[i];
   }
   cout << ans << endl;
}

void solve1730A()
{
   int n, c;
   cin >> n >> c;
   map<int, int> mp;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      mp[x]++;
   }
   int ans = 0;
   for(auto elem : mp)
   {
      ans += min(elem.second, c);
   }
   cout << ans << endl;
   
}

void solve275A()
{
   vector<vector<int>>  a(3, vector<int>(3)), sum(3, vector<int>(3 , 0));
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++) {cin >> a[i][j];}
   }
   
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         int top = (i - 1 >= 0) ? a[i - 1][j] : 0;
         int bot = (i + 1 < 3) ? a[i + 1][j] : 0;
         int left = (j - 1 >= 0)? a[i][j - 1] : 0;
         int right = (j + 1 < 3)? a[i][j + 1] : 0;
         sum[i][j] += a[i][j] + top + bot + left + right;
      }
   }
   
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         //cout << sum[i][j] << " ";
         if(sum[i][j] % 2 == 0) cout << 1;
         else cout << 0;
      }
      cout << endl;
   }
   
}


void solve1285B()
{
   ll n, sum = 0;
   cin >> n;
   vector<ll> a(n);
   bool allpos = true, allneg = true;
   for(ll i = 0; i < n; i++)
   {
      ll x;
      cin >> x;
      a[i] = x;
      if(x <= 0) allpos = false;
      else allneg = false;
      sum += x;
   }
   
   if(allpos)
   {
      cout << "YES" << endl;
      return;
   }
   if(allneg)
   {
      cout << "NO" << endl;
      return;
   }
   else
   {
      ll l = 0, r = 0, currsum = 0, maxisum = 0, lm = -1, rm = -1;
      for(r = 0; r < n; r++)
      {
         currsum += a[r];
         if(currsum > maxisum)
         {
            maxisum = currsum;
            lm = l;
            rm = r;
         }
         if(currsum <= 0)
         {
            l = r + 1;
            currsum = 0;
         }
         //cout << currsum << " " << maxisum << endl;
      }
      //cout << maxisum << " " << lm << " " << rm << endl;
      if(maxisum >= sum)
      {
         if(lm > 0 || rm < n - 1)
         {
            cout << "NO" << endl;
         }
         else cout << "YES" << endl;
      }
      else cout << "YES" << endl;
   }
}

void solve1371C()
{
   ll a, b, n, m;
   cin >> a >> b >> n >> m;
   if(n + m > a + b)
   {
      cout << "NO" << endl;
      return;
   }
   ll bigger, smaller;
   bigger = max(a, b);
   smaller = min(a, b);
   ll diff = bigger - smaller;
   if(diff > a)
   {
      if(smaller < m) cout << "NO" << endl;
      else cout << "YES" << endl;
      return;
   }
   if(diff <= a)
   {
      a -= diff;
      bigger -= diff;
      if(smaller < m)
      {
         cout << "NO" <<endl;
      }
      else cout << "YES" << endl;
   }
} 

void solve490A()
{
   int n;
   cin >> n;
   vector<int> f, s, t;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x == 1) f.push_back(i + 1);
      else if(x == 2) s.push_back(i + 1);
      else t.push_back(i + 1);
   }
   int i = 0, j = 0, k = 0;
   
   vector<pair<int, pair<int,int>>> ans;
   for(i = 0; i < min(f.size(), min(s.size(), t.size() )); i++)
   {
      ans.push_back({f[i], {s[i], t[i]}});
   }
   
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem.first << " " << elem.second.first << " "<< elem.second.second << endl;
}

void flip(string& s, int x)
{
   for(int i = 0; i < x; i++)
   {
      if(s[i] == '1') s[i] = '0';
      else s[i] = '1';
   }
   reverse(s.begin(), s.begin() + x);
}

void solve1381A()
{
   int n;
   cin >> n;
   string s1, s2;
   cin >> s1 >> s2;
   vector<int> ans;
   for(int i = n - 1; i >= 0; i--)
   {
      if(s1[i] == s2[i]) continue;
      else
      {
         //cout << s1 << " " << s2 << endl;
         if(s1[0] == s2[i])
         {
            flip(s1, 1);
            ans.push_back(1);
            //cout << "first if " << s1 << endl;
            if(i > 0)
            {
               flip(s1, i + 1);
               ans.push_back(i + 1);
            }
            //cout << "second if " << s1 << endl;
         }
         else
         {
            flip(s1, i + 1);
            ans.push_back(i + 1);
            //cout << "else " << s1 << endl;
         }
      }
   }
   cout << ans.size() << " ";
   for(auto elem : ans) cout << elem << " "; cout << endl;
}

void solve1738A()
{
   ll n;
   cin >> n;
   vector<ll> a(n), b(n), f, ice, bigger, smaller;
   for(auto & e : a) cin >> e;
   for(auto & e : b) cin >> e;
   
   for(int i = 0; i < n; i++)
   {
      if(a[i] == 0) f.push_back(b[i]);
      else ice.push_back(b[i]);
   }
   sort(f.begin(), f.end());
   sort(ice.begin(), ice.end());
   
   int diff = abs((int)f.size() - (int)ice.size());
   if(f.size() > ice.size()) {bigger = f; smaller = ice;}
   else if(f.size() < ice.size()) {bigger = ice; smaller = f;}
   else if (f.size() == ice.size())
   {
      if(f[0] >= ice[0]) {bigger = f; smaller = ice;}
      else {bigger = ice; smaller = f;}
   }
   ll ans = 0;
   
   int i = 0, j = 0;
   for(i = 0; i < diff; i++) ans += bigger[i];
   
   while(i < bigger.size())
   {
      if(i == 0) ans += smaller[j];
      else ans += smaller[j] * 1ll * 2;
      ans += bigger[i] * 1ll * 2;
      i++; j++;
   }
   cout << ans << endl;
   
}

void solve1738B()
{
   ll n, k;
   cin >> n >> k;
   vector<ll>a(k), b;
   for(int i = 0; i < k; i++) cin >> a[i];
   ll x = n + 1 - k;
   ll f = ceil(a[0] * 1.0 / x);
   b.push_back(f);
   for(int i = 0; i + 1 < k; i++)
   {
      b.push_back(a[i + 1] - a[i]);
   }
   cout << x << " "  << f << endl;
   for(auto elem : b) cout << elem << " "; cout << endl;
   for(int i = 0; i + 1 < b.size(); i++)
   {
      if(b[i] > b[i + 1])
      {
         cout << "NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
}

void solve1470A()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(n + 1), b(k + 1);
   for(ll i = 1; i <= n; i++) cin >> a[i];
   for(ll i = 1; i <= k; i++) cin >> b[i];
   sort(a.begin(), a.end());
   int k2 = 1;
   ll ans = 0;
   for(int i = n; i >= 1; i--)
   {
      if(b[a[i]] > b[k2])
      {
         ans += b[k2];
         k2++;
      }
      else ans += b[a[i]];
   }
   cout << ans << endl;
}

void solve1324C()
{
   string s;
   cin >> s;
   int n = s.size();
   int maxi = 0;
   for(int i = 0; i < n; i++)
   {
      if(s[i] == 'R') continue;
      else
      {
         int j = i;
         while(j < n && s[j] == 'L') j++;
         maxi = max(maxi, j - i);
         i = j - 1;
      }
   }
   cout << maxi + 1 << endl;
}

void solve1341B()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1), b;
   for(int i = 1; i <= n; i++) cin >> a[i];
   for(int i = 2; i <= n - 1; i++)
   {
      if(a[i] > a[i - 1] && a[i] > a[i + 1]) b.push_back(i);
   }
   
   int maxi = 0, idx = 1;
   for(int i = 1; i <= n - k + 1 ; i++)
   {
      int st = i;
      int en = i + k - 1;
      int ff = lower_bound(b.begin(), b.end(), st + 1) - b.begin();
      int ss = upper_bound(b.begin(), b.end(), en - 1) - b.begin();
      
      if(ss - ff > maxi)
      {
         maxi = ss - ff;
         idx = i;
      }
   }
   cout << maxi + 1 << " " << idx << endl;
}

void solve1341B1()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1);
   unordered_set<int> b;
   for(int i = 1; i <= n; i++) cin >> a[i];
   for(int i = 2; i <= k - 1; i++)
   {
      if(a[i] > a[i - 1] && a[i] > a[i + 1]) b.insert(i);
   }
   
   int maxi = b.size(), idx = 1;
   for(int i = k + 1; i <= n; i++)
   {
      int curr = i - 1;
      if(a[curr] > a[curr + 1] && a[curr] > a[curr - 1]) b.insert(curr);
      if(b.find(i - k) != b.end()) b.erase(i - k);
      if(b.find(i - k + 1) != b.end()) b.erase(i - k + 1);
      //cout << b.size() << endl;
      if(maxi < b.size())
      {
         maxi = b.size();
         idx = i - k + 1;
      }
   }
   
   cout << maxi + 1 << " " << idx << endl;
  
}

void solve1735B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e : a) cin >> e;
   int x = 2 * a[0] - 1, ans = 0;
   for(int i = 1; i < n; i++)
   {
      if(a[i] <= x) continue;
      int divi = a[i] / x;
      int rem = a[i] % x;
      if(rem == 0) divi--;
      ans += divi;
   }
   cout << ans << endl;
}

void solve1738C()
{
   int n;
   cin >> n;
   int odd = 0;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      odd += abs(x) % 2;
   }
   if (odd % 4 == 0 || ((odd - 1) % 4 == 0 && n % 2 == 0) || (odd + 1) % 4 == 0)
   {
      cout << "Alice\n";
   }
   else cout << "Bob\n";
 
}

void solve519C()
{
   int n, m;
   cin >> n >> m;
   int smaller, bigger;
   bigger = max(n, m);
   smaller = min(n, m);
   if(bigger >= 2 * smaller) 
   {
      cout << smaller << endl;
      return;
   }
   int teams = 0;
   teams += bigger - smaller;
   smaller -= bigger - smaller;
   smaller *= 2;
   teams += (smaller / 3);
   cout << teams << endl;
}

void solve1521B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   int mini = INT_MAX, idx = -1;
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      if(a[i] < mini)
      {
         mini = a[i];
         idx = i;
      }
   }
   vector<int> b(a.begin(), a.end());
   
   int mul = mini + 1;
   //cout << n - 1 << endl;
   for(int i = idx - 1; i >= 1; i--)
   {
      a[i] = mul;
      mul++;
      //if(mul % mini == 0) mul++;
   }
   
   mul = mini + 1;
   for(int i = idx + 1; i<= n; i++)
   {
      a[i] = mul;
      mul++;
      //if(mul % mini == 0) mul++;
   }
   
   //for(auto elem : b) cout << elem << " "; cout << endl;
   //for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
   
   cout << n - 1 << endl;
   for(int i = 1; i <= n; i++)
   {
      if(i == idx) continue;
      cout << i << " " << idx << " " << a[i] << " " << a[idx] << endl;
   }
}

void solve1366B()
{
   int n, x, m;
   cin >> n >> x >> m;
   pair<int, int> curr = {x, x};
   for(int i = 1; i <= m; i++)
   {
      int l, r;
      cin >> l >> r;
      if(curr.first > r || curr.second < l) continue;
      curr.first = min(curr.first, l);
      curr.second = max(curr.second, r);
   }
   
   cout << curr.second - curr.first + 1 << endl;
}


void solve1555C()
{
   int n = 2, m;
   cin >> m;
   vector<int> pref(m + 1, 0);
   vector<int> suff(m + 2, 0);
   for(int i = 1; i <= 2; i++)
   {
      for(int j = 1; j <= m; j++) 
      {
         if(i == 1) cin >> suff[j];
         else cin >> pref[j];
      }
   }
   for(int i = m - 1; i >= 1; i--) suff[i] += suff[i + 1];
   for(int i = 2; i <= m; i++) pref[i] += pref[i - 1];
   //for(int i = 1; i <= m; i++) cout << suff[i] << " "; cout << endl;
   //for(int i = 1; i <= m; i++) cout << pref[i] << " "; cout << endl;
   
   
   int ans = INT_MAX;
   
   for(int i = 1; i <= m; i++)
   {
      int curr = max(suff[i + 1], pref[i - 1]);
      ans = min(ans, curr);
   }
   
   cout << ans << endl;
}

void solve1736A()
{
   int n, cnt1 = 0, cnt2 = 0;
   cin >> n;
   vector<int>a(n), b(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] == 1) cnt1++;
   }
   for(int i = 0; i < n; i++)
   {
      cin >> b[i];
      if(b[i] == 1) cnt2++;
   }
   int ans = abs(cnt1 - cnt2);
   if(cnt1 > cnt2)
   {
      for(int i = 0; i < n; i++)
      {
         if(b[i] == 0 && a[i] == 1 && cnt1 - cnt2 > 0)
         {
            b[i] = 1; cnt1--;
         }
      }
   }
   else if(cnt2 > cnt1)
   {
      for(int i = 0; i < n; i++)
      {
         if(a[i] == 0 && b[i] == 1 && cnt2 - cnt1 > 0)
         {
            a[i] = 1; cnt2--;
         }
      }
   }
   for(int i = 0; i < n; i++)
   {
      if(a[i] != b[i]) {ans++; break;}
   }
   cout << ans  << endl;
}

void solve1741A()
{
   string a, b;
   cin >> a >> b;
   int n1 = a.size(), n2 = b.size();
   if(a[n1 - 1] == b[n2 - 1])
   {
      if(a[n1 - 1] == 'S')
      {
         if(n1 > n2)
         {
            cout << "<" << endl;
            return;
         }
         else if (n1 < n2)
         {
            cout << ">" << endl;
            return;
         }
         else 
         {
            cout << "=" << endl;
            return;
         }
      }
      else if(a[n1 - 1] == 'M')
      {
         cout << "=" << endl;
         return;
      }
      else
      {
         if(n1 > n2)
         {
            cout << ">" << endl;
            return;
         }
         else if (n1 < n2)
         {
            cout << "<" << endl;
            return;
         }
         else 
         {
            cout << "=" << endl;
            return;
         }
      }
   }
   
   else
   {
      if(a[n1 - 1] == 'L') cout << ">" << endl;
      else if(a[n1 - 1] == 'S') cout << "<" << endl;
      else
      {
         if(b[n2 - 1] == 'L') cout << "<" << endl;
         else cout << ">" << endl;
      }
   }
}

void solve1741B()
{
   int n;
   cin >> n;
   vector<int>a(n + 1);
   int k = (n  + 1) / 2;
   int p = 1;
   for(int i = k + 1; i <= n; i++) a[i] = p++;
   for(int i = 1; i <= k; i++) a[i] = p++;
   
   if(n == 3) {cout << -1 << endl; return;}
   for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
}

void solve1741C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   int sum = 0;
   for(int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}
   int ans = n;
   for(int i = 2; i <= n; i++)
   {
      if(sum % i != 0) continue;
      int f = sum / i;
      int cnt = 0;
      int j = 0;
      int mark = -1;
      int maxilen = INT_MIN;
      while(j < n)
      {
         int currsum = 0;
         while(j < n && currsum < f) 
         {
            currsum += a[j];
            j++;
         }
         if(currsum == f) 
         {
            cnt++;  
            maxilen = max(maxilen, j - (mark + 1)); 
            mark = j - 1;
            currsum = 0;
            
         }
         else break;
      }
      if(cnt == i) ans = min(ans, maxilen);
   }
   cout << ans << endl;
}

bool isP(ll n)
{
   for(ll i = 2; i * i <= n; i++)
   {
      if(n % i == 0) return false;
   }
   return true;
}

void solve1454D()
{
   ll n; 
   cin >> n;
   if(isP(n) == true)
   {
      cout << 1 << endl;
      cout << n << endl;
      return;
   }
   
   vector<pair<ll, ll>> a;
   for(ll i = 2; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         ll cnt = 0;
         while(n % i == 0)
         {
            n /= i;
            cnt++;
         }
         a.push_back({cnt, i});
      }
   }
   if(n > 1) a.push_back({1, n});
   
   sort(a.begin(), a.end());
   //for(auto elem : a) cout << "(" << elem.first << " " << elem.second << ")"; cout << endl;
   
   cout << a.back().first << endl;
   ll ans = 1;
   int s = a.size();
   for(int i = 0; i < s; i++)
   {
      ll cnt = a[i].first;
      if(i == s - 1) cnt = 1;
      ll p = a[i].second;
      ll m = 1;
      for(int j = 1; j <= cnt; j++) m = m * 1ll * p;
      ans = ans * 1ll * m;
   }
   for(int j = 1; j <= a[s - 1].first - 1; j++) cout << a[s - 1].second << " ";
   cout << ans << endl;
}

void solve1742A()
{
   vector<int> a(3);
   for(int i = 0; i < 3; i++) cin >> a[i];
   sort(a.begin(), a.end());
   if(a[0] + a[1] == a[2]) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1742B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(),  a.end());
   for(int i = 0; i + 1 < n; i++)
   {
      if(a[i] == a[i + 1]) 
      {
         cout << "NO" << endl;
         return;
      }
   }
   
   cout << "YES" << endl;
}

void solve1742C()
{
   vector<vector<char>> a(8, vector<char> (8));
   for(int i = 0; i < 8; i++)
   {
      string in;
      cin >> in;
      for(int j = 0; j < 8; j++)
      {
         a[i][j] = in[j];
      }
   }
   /*for(auto elem : a)
   {
      for(auto e : elem) cout << e << " "; cout << endl;
   }*/
   for(int i = 0; i < 8; i++)
   {
      int cnt = 0;
      for(int j = 0; j < 8; j++)
      {
         if(a[i][j] == 'R') cnt++;
      }
      if(cnt == 8)
      {
         cout << "R" << endl;
         return;
      }
   }
   
   for(int i = 0; i < 8; i++)
   {
      int cnt = 0;
      for(int j = 0; j < 8; j++)
      {
         if(a[j][i] == 'B') cnt++;
      }
      if(cnt == 8)
      {
         cout << "B" << endl;
         return;
      }
   }
}

void solve1742D()
{
   int n;
   cin >> n;
   vector<int> a(10007, -1);
   for(int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      a[x] = i;
   }
   
   int maxi = -1;
   
   for(int i = 1; i <= 1000; i++)
   {
      if(a[i] == -1) continue;
      for(int j = i; j <= 1000; j++)
      {
         if(a[j] != -1)
         {
            if(__gcd(i, j) == 1)
            {
               maxi = max(maxi, a[i] + a[j]);
            }
         }
      }
   }
   
   cout << maxi << endl;
}

void solve1744A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e : a) cin >> e;
   string s;
   cin >> s;
   
   map<int, char> mp;
   for(int i = 0; i < n; i++)
   {
      int key = a[i];
      char val = s[i];
      if(mp.count(key) == 0)
      {
         mp[key] = val;
      }
      else
      {
         if(mp[key] != val)
         {
            cout << "NO" << endl;
            return;
         }
      }
   }
   
   cout << "YES" << endl;
}


void solve1744B()
{
   ll n, q, evencount = 0, oddcount = 0, evensum = 0, oddsum = 0, totalsum = 0;
   cin >> n >> q;
   vector<int> a(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] % 2 == 0)
      {
         evencount++;
         evensum += a[i];
      }
      else 
      {
         oddcount++;
         oddsum += a[i];
      }
   }
   
   totalsum = evensum + oddsum;
   while(q--)
   {
      int t, x;
      cin >> t >> x;
      if(t == 0)
      {
         if(x % 2 == 0)
         {
            totalsum += evencount * 1ll * x;
            evensum = evencount * 1ll * x + evensum;
         }
         else
         {
            totalsum += evencount * 1ll * x;
            oddcount += evencount;
            evencount = 0;
            oddsum = totalsum;
            evensum = 0;
         }
      }
      else
      {
         if(x % 2 == 0)
         {
            totalsum += oddcount * 1ll * x;
            oddsum = oddcount * 1ll * x + oddsum;
         }
         else
         {
            totalsum += oddcount * 1ll * x;
            evencount += oddcount;
            oddcount = 0;
            evensum = totalsum;
            oddsum = 0;
         }
      }
      cout << totalsum << endl;
   }
}

void solve1744C()
{
   int n; char c;
   cin >> n >> c;
   string s;
   cin >> s;
   
   if(c == 'g')
   {
      cout << 0 << endl;
      return;
   }
   
   vector<int> on, g;
   for(int i = 0; i < n; i++)
   {
      if(s[i] == 'g') g.push_back(i);
      else if(s[i] == c) on.push_back(i);
   }
   
   int maxi = INT_MIN;
   int i = 0, j = 0;
   
   for(i = 0; i < on.size(); i++)
   {
      int f = on[i];
      int s = lower_bound(g.begin(), g.end(), f) - g.begin();
      int seco;
      if(s < g.size())
      {
         seco = g[s];
         maxi = max(maxi, abs(f - seco));
      }
      else 
      {
         seco = g[0] + n - f;
         maxi = max(maxi, seco);
      }
      
   }
   cout << maxi << endl;
}

void solve1746A()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1);
   bool f = false;
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      if(a[i] == 1) f = true;
   }
   
   if(f == true) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1746B()
{
   int n;
   cin >> n;
   vector<int> z, o;
   for(int i = 1; i <= n; i++)
   {
      int x; 
      cin >> x;
      if(x == 1) o.push_back(i);
      else z.push_back(i);
   }
   int ans = 0;
   int ze = z.size();
   int on = o.size();
   if(ze == 0 || on == 0)
   {
      cout << ans << endl;
      return;
   }
   int i = 0, j = ze - 1;
   for(i = 0; i < on; i++)
   {
      if(j >= 0 && o[i] < z[j]) 
      {
         ans++; z.pop_back();
         j--;
      }
   }
   cout << ans << endl;
}

void solve1743A()
{
   set<int> st;
   for(int i = 0; i <= 9; i++) st.insert(i);
   int n;
   cin >> n;
   for(int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      st.erase(x);
   }
   
   //for(auto elem : st) cout << elem << " "; cout << endl;
   
   int n1 = st.size();
   int total = (n1 * (n1 - 1)) / 2;
   cout << total * 6 << endl;
   
}

void solve1743B()
{
   int n;
   cin >> n;
   for(int i = 1; i <= n; i++)
   {
      if(i != n) cout << i + 1 << " ";
      else cout << 1 << " ";
   }
   cout << endl;
}

void solve1743C()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   vector<int> a(n), v;
   for(auto & e : a) cin >> e;
   int i = 0;
   ll ans = 0;
   n = s.size();
   while(i < n && s[i] == '1')
   {
      ans += a[i];
      i++;
   }
   while(i < n)
   {
      //cout << i << endl;
      while(i < n && s[i] != '1') i++;
      if(i < n && s[i] == '1') v.push_back(i - 1);
      while(i < n && s[i] != '0') i++;
      if((i == n && s[i - 1] == '1') || (i < n && s[i] == '0')) v.push_back(i - 1);
   }
   //for(auto elem : v) cout << elem << " "; cout << endl;
   for(int i = 0; i < v.size(); i += 2)
   {
      int f = v[i];
      int s = 0;
      if(i + 1 < v.size()) s = v[i + 1];
      int sum = 0;
      for(int j = f; s < n && j <= s; j++)
      {
         sum += a[j];
      }
      int maxi = 0;
      for(int j = f; s < n && j <= s; j++)
      {
         maxi = max(maxi, sum - a[j]);
      }
      ans += maxi;
   }
   cout << ans << endl;
}

void solve1741D()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e : a) cin >> e;
   int start = 2;
   int en = n / 2;
   while(start <= en)
   {
      for(int i = 0; i < n; i += start)
      {
         int mini = INT_MAX;
         int maxi = INT_MIN;
         for(int j = i; j < i + start; j++)
         {
            mini = min(mini, a[j]);
            maxi = max(maxi, a[j]);
         }
         if(maxi - mini > start - 1)
         {
            cout << -1 << endl;
            return;
         }
      }
      start *= 2;
   }
   start = 2;
   en = n;
   ll ans = 0;
   while(start <= en)
   {
      for(int i = 0; i < n; i += start)
      {
         int m = start / 2;
         int f = a[i];
         int s = a[i + m];
         if(f > s) 
         {
            swap(a[i], a[i + m]);
            ans++;
            
         }
      }
      start *= 2;
   }
   cout << ans << endl;
}

void solve1749A()
{
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < m; i++)
   {
      int x, y;
      cin >> x >> y;
   }
   if(n == m) cout << "NO" << endl;
   else cout << "YES" << endl;
}

void solve1749B()
{
   ll n;
   cin >> n;
   vector<int> a(n), b(n), c(n);
   ll sum = 0;
   for(auto & e : a) {cin >> e; sum += e;}
   for(auto & e : b) cin >> e;
   sort(b.begin(), b.end());
   for(int i = 0; i < n - 1; i++) sum += b[i];
   cout << sum << endl;
}

void solve1746C()
{
   ll n;
   cin >> n;
   vector<ll> a(n + 1), pref(n + 1, 0);
   vector<pair<ll, ll>> b;
   for(ll i = 1; i <= n; i++) {cin >> a[i]; pref[i] = i;}
   for(ll i = 2; i <= n; i++) pref[i] += pref[i - 1];
   for(ll i = 1; i + 1 <= n; i++)
   {
      if(a[i] > a[i + 1]) b.push_back({a[i] - a[i + 1], i + 1});
   }
   
   sort(b.begin(), b.end());
   vector<pair<ll, ll>> ans;
   
   ll l = 0, r = 0, curr = n;
   for(ll i = 0; i < b.size(); i++)
   {
      ll f = b[i].second;
      ll s = f - 1;
      ll diff = b[i].first;
      while(pref[r] - pref[l] < diff) r++;
      ans.push_back({b[i].second, r - l});
      curr -= r - l;
      l = r;
   }
   
   ans.push_back({n, curr});
   for(ll i = 0; i < ans.size(); i++)
   {
      for(ll j = 0; j < ans[i].second; j++) cout << ans[i].first << " ";
   }
   cout << endl;
}

void solve1749C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & e : a) cin >> e;
   sort(a.begin(), a.end()); 
   int ans = 0;
   int k, i, j;
   for(k = 0; 2 * k - 2 < n; k++)
   {
      for(i = 2 * k - 2, j = k; j >= 1; j--, i--)
      {
         if(a[i] > j) break;
      }
      if(j == 0) ans = k;
      else break;
   }
   
   cout << ans << endl;
}

void solve1736B()
{
   ll n;
   cin >> n;
   vector<ll> a(n), b(n + 1);
   for(ll i = 0; i < n; i++) cin >> a[i];
   b[0] = a[0], b[n] = a[n - 1];
   for(ll i = 1; i <= n - 1; i++)
   {
      b[i] = (a[i - 1] * a[i]) / __gcd(a[i - 1], a[i]);
   }
   
   //for(auto elem : b) cout << elem << " "; cout << endl;
   
   for(int i = 0; i + 1 <= n; i++)
   {
      if(__gcd(b[i], b[i + 1]) != a[i]) 
      {
         cout << "NO" << endl;
         return;
      }
   }
   
   cout << "YES" << endl;
}

void solve1364B()
{
   int n;
   cin >> n;
   vector<int> a(n), b, ans;
   for(auto &e : a) cin >> e;
   for(int i = 1; i < n; i++)
   {
      b.push_back(a[i] - a[i - 1]);
   }
   int sign = b[0] > 0 ? 1 : -1;
   ans.push_back(a[0]);
   int j = 1;
   n = b.size();
   while(j < n)
   {
      while(j < n && (b[j] / abs(b[j])) == sign) j++;
      if(j < n && (b[j] / abs(b[j])) != sign)
      {
         ans.push_back(a[j]);
         sign *= -1;
      }
   }
   ans.push_back(a.back());
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem << " "; cout << endl;
   
}

void solve1373C()
{
   string s;
   cin >> s;
   int n = s.size();
   vector<int> a(n + 1, 0);
   for(int i = 1; i <= n; i++)
   {
      a[i] = a[i - 1] + ((s[i - 1] == '+') ? 1 : -1);
   }
   //for(auto elem : a) cout << elem <<" "; cout << endl;
   int search = -1;
   ll ans = n;
   for(int i = 1; i <= n; i++)
   {
      if(a[i] == search)
      {
         ans += i;
         search--;
         //cout << "found " << i << endl;
      }
   }
   
   cout << ans << endl;
}

void solve1203C()
{
   int n;
   cin >> n;
   vector<ll> a(n);
   ll ans = 0;
   for(int i = 0; i < n; i++) 
   {
      cin >> a[i];
      ans = __gcd(ans, a[i]);
      
   }
   ll cnt = 0;
   for(ll i = 1; i * i <= ans; i++)
   {
      if(i * i != ans && ans % i == 0) cnt += 2;
      else if (i * i == ans && ans % i == 0) cnt++;
   }
   
   cout << cnt << endl;
}

void solve1740A()
{
   int n;
   cin >> n;
   cout << n << endl;
}

void solve1740B()
{
   ll n;
   cin >> n;
   vector<pair<ll, ll>> a(n);
   ll l = 0, b = 0;
   for(int i = 0; i < n; i++)
   {
      ll x, y;
      cin >> x >> y;
      if(y > x) swap(x, y);
      a[i] = make_pair(x, y);
      b += y;
   }
   
   sort(a.begin(), a.end());
   //for(auto elem : a) cout << "(" << elem.first << " " << elem.second << ")"; cout << endl; 
   b *= 2;
   l += a[0].first;
   ll curr = a[0].first;
   for(int i = 1; i < n; i++)
   {
      l += a[i].first - curr;
      curr = a[i].first;
   }
   
   l += a[n - 1].first;
   ll ans = b + l;
   //cout << l << " " << b << endl;
   cout << ans << endl;
}

void solve1037C()
{
   int n;
   cin >> n;
   string a, b;
   cin >>  a >> b;
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(a[i] != b[i])
      {
         if(a[i] == '0')
         {
            if(i + 1 < n && a[i + 1] == '1' && b[i + 1] == '0')
            {
               ans++;
               i++;
            }
            else 
            {
               ans++;
            }
         }
         else if(a[i] == '1')
         {
            if(i + 1 < n && a[i + 1] == '0' && b[i + 1] == '1')
            {
               ans++;
               i++;
            }
            else ans++;
         }
      }
   }
   
   cout << ans << endl;
}

void solve1407B()
{
   int n;
   cin >> n;
   vector<int> a(n), ans;
   unordered_set<int> st;
   int maxi = INT_MIN;
   int idx = -1;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(maxi < a[i])
      {
         maxi = a[i];
         idx = i;
      }
   }
   
   st.insert(idx);
   ans.push_back(idx);
   int curr = maxi;
   while(ans.size() != n)
   {
      int maxigc = 0;
      for(int i = 0; i < n; i++)
      {
         if(st.find(i) != st.end()) continue;
         int gc = __gcd(a[i], curr);
         if(gc > maxigc)
         {
            idx = i;
            maxigc = gc;
         }
      }
      st.insert(idx);
      ans.push_back(idx);
      curr = maxigc;
   }
   
   for(int i = 0; i < n; i++) cout << a[ans[i]] << " "; cout << endl;
}

void solve1433E()
{
   int n;
   cin >> n;
   ll ans = 0;
   ll nume = 1;
   ll den = 1;
   for(int i = n, j = 1; j <= (n / 2) ; j++, i--)
   {
      nume *= i;
      den *= j;
   }
   ans = nume / den;
   
   nume = 1;
   for(int i = 1; i <= (n / 2) - 1; i++)
   {
      nume *= i;
   }
   ans = ans * nume * nume;
   cout << ans / 2 << endl;
}

void solve1476B()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(n), pref(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(i == 0) pref[i] = a[i];
      else pref[i] = pref[i - 1] + a[i];
   }
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   
   ll ans = 0;
   //double multiply = 100.0 / k;
   for(int i = 1; i < n; i++)
   {
      ans = max(ans, (100ll * a[i] - k * pref[i - 1] + k - 1) / k);
      //ll b = ceil(a[i] * multiply);
      //ans = max(ans, b - pref[i - 1]);
      
   }
   cout << ans << endl;
}

void solve1466C()
{
   string s;
   cin >> s;
   int n = s.size();
   int ans = 0;
   vector<bool> used(n, false);
   for(int i = 1; i < n; i++)
   {
      bool need = false;
      if(s[i] == s[i - 1] && used[i - 1] == false)
      {
         need = true;
      }
      if(i - 2 >= 0 && s[i] == s[i - 2] && used[i - 2] == false)
      {
         need = true;
      }
      
      used[i] = need;
      ans += used[i];
   }
   cout << ans << endl;
}

void solve1747B()
{
   int n1;
   cin >> n1;
   n1 *= 3;
   vector<int> a, n;
   for(int i = 2; i <= n1; i += 3) a.push_back(i);
   for(int i = 3; i <= n1; i += 3) n.push_back(i);
   vector<pair<int, int>> ans;
   
   int i = 0, j = (int) n.size() - 1;
   
   while(i < a.size() && a[i] < n[j])
   {
      ans.push_back({a[i], n[j]});
      i++; j--;
   }
   
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem.first << " " << elem.second << endl;
}

void solve1420C1()
{
   int n, q;
   cin >> n >> q;
   vector<int> a(n), minima, maxima;
   for(auto &e : a) cin >> e;
   ll ans = 0;
   if(n > 1)
   {
      if(a[0] > a[1]) maxima.push_back(0);
      else minima.push_back(0);
      for(int i = 1; i <= n - 2; i++)
      {
         if(a[i] > a[i - 1] && a[i] > a[i + 1]) maxima.push_back(i);
         if(a[i] < a[i - 1] && a[i] < a[i + 1]) minima.push_back(i);
      }
      if(a[n - 1] > a[n - 2]) maxima.push_back(n - 1);
      else minima.push_back(n - 1);
      
      //for (auto elem : maxima) cout << elem << " "; cout << endl;
      //for (auto elem : minima) cout << elem << " "; cout << endl;
      
      
      int n1 = maxima.size();
      for(int i = 0; i + 1 < n1; i++)
      {
         int f = maxima[i];
         int mini = lower_bound(minima.begin(), minima.end(), f) - minima.begin();
         int mini2 = minima[mini];
         //cout << a[f] << " " << a[s] << " " << a[mini2] << endl;
         ans += a[f] - a[mini2];
         //cout << ans << endl;
      }
      ans += a[maxima.back()];
   }
   
   else ans = a[0];
   
   cout << ans << endl;
}

void solve1742E()
{
   ll n, q;
   cin >> n >> q;
   vector<ll> a(n + 1), b(n + 1, 0), pref(n + 1, 0);
   ll curr = 0;
   for(int i = 1; i <= n; i++) 
   {
      cin >> a[i];
      pref[i] += pref[i - 1] + a[i];
      if(a[i] >= curr)
      {
         b[i] = a[i];
         curr = a[i];
      }
      else b[i] = curr;
   }
   
   //for(auto elem : b) cout << elem << " "; cout << endl;
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   for(int i = 1; i <= q; i++)
   {
      ll x;
      cin >> x;
      ll ans = 0;
      ll idx = upper_bound(b.begin(), b.end(), x) - b.begin();
      idx--;
      cout << pref[idx] << " ";
   }
   cout << endl;
}

void solve1418B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), pref(n + 1, 0), locked(n + 1);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
   }
   
   bool all = true;
   for(int i = 1; i <= n; i++) 
   {
      cin >> locked[i];
      if(locked[i] == 0) all = false;
   }
   
   if(pref.back() < 0 || all == true)
   {
      for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
      return;
   }
   
   for(int i = 1; i <= n; i++)
   {
      if(locked[i] == 1) continue;
      int maxi = 1;
      int idx = -1;
      int from = a[i];
      for(int j = i + 1; j <= n; j++)
      {
         if(locked[j] == 1) continue;
         int to = a[j];
         if(to - from >= maxi)
         {
            maxi = to - from;
            idx = j;
         }
      }
      if(idx != -1) swap(a[i], a[idx]);
   }
   
   for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
   //for(int i = 1; i <= n; i++) cout << pref[i] << " "; cout << endl;
}

void solve1234B2()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n), ans(n);
   map<int, bool> mp;
   
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      mp[a[i]] = false;
   }
   
   int f = 0, s = 0;
   for(int i = 0; i < n; i++)
   {
      if(mp[a[i]] == false)
      {
         if(f - s >= k)
         {
            mp[ans[s]] = false;
            s++;
            ans[f] = a[i];
            f++;
            mp[a[i]] = true;
         }
         else
         {
            ans[f] = a[i];
            f++;
            mp[a[i]] = true;
         }
      }
   }
   cout << f - s << endl;
   for(int i = f - 1; i >= s; i--) cout << ans[i] << " "; cout << endl;
}

void solve1618D()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(n);
   ll sum = 0;
   for(auto &e : a) {cin >> e; sum += e;}
   sort(a.begin(), a.end());
   int p = n - k - 1;
   for(int j = n - 1, i = 1; i <= k; i++, j--)
   {
      //cout <<sum << " " <<  p << " " << j << endl;
      sum -= a[p] + a[j];
      sum += a[p] / a[j];
      p--;
   }
   cout << sum << endl;
}

void solve1311C()
{
   int n, m;
   cin >> n >> m;
   string s;
   cin >> s;
   vector<vector<int>> pos(26);
   vector<int> ans(26, 0);
   for(int i = 0; i < n; i++)
   {
      pos[s[i] - 'a'].push_back(i + 1);
      ans[s[i] - 'a']++;
   }
   
   /*for(int i = 0; i < 26; i++)
   {
      if(pos[i].size() > 0)
      {
         cout << (char) (i + 'a') << " ";
         for(int j = 0; j < pos[i].size(); j++) cout << pos[i][j] << " "; 
         cout << endl;
      }
   }*/
   
   for(int i = 1; i <= m; i++)
   {
      int x;
      cin >> x;
      for(int j = 0; j < 26; j++)
      {
         int idx = upper_bound(pos[j].begin(), pos[j].end(), x) - pos[j].begin();
         ans[j] += idx;
      }
   }
   
   for(int i = 0; i < 26; i++) cout << ans[i] << " "; cout << endl;
}

void solve617B()
{
   int n;
   cin >> n;
   vector<int> ones;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x == 1) ones.push_back(i);
   }
   if(ones.size() == 0) {cout << 0 << endl; return;}
   
   ll ans = 1;
   for(int i = 0; i + 1 < ones.size(); i++)
   {
      int diff = ones[i + 1] - ones[i];
      ans *= diff;
   }
   cout << ans << endl;
}

void solve486B()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> b(n, vector<int> (m)), ans(n, vector<int> (m));
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < m; j++) cin >> b[i][j];
   }
   
   vector<int> rows, cols;
   
   for(int i = 0; i < n; i++)
   {
      int cnt = 0;
      for(int j = 0; j < m; j++)
      {
         if(b[i][j] == 1) {cnt++;}
      }
      if(cnt == m) rows.push_back(i);
   }
   
   for(int i = 0; i < m; i++)
   {
      int cnt = 0;
      for(int j = 0; j < n; j++)
      {
         if(b[j][i] == 1) cnt++;
      }
      if(cnt == n) cols.push_back(i);
   }
   if(rows.size() == 0 ^ cols.size() == 0) 
   {
      cout << "NO" << endl;
      return;
   }
   for(int i = 0; i < n; i++)
   {
      if(binary_search(rows.begin(), rows.end(), i)) continue;
      for(int j = 0; j < m; j++)
      {
         if(binary_search(cols.begin(), cols.end(), j)) continue;
         if(b[i][j] == 1) 
         {
            cout << "NO" << endl;
            return;
         }
      }
   }
   //for(auto elem : rows) cout << elem << " "; cout << endl;
   //for(auto elem : cols) cout << elem << " "; cout << endl;
   
   for(auto elem : rows)
   {
      int r = elem;
      for(auto elem2 : cols)
      {
         int c = elem2;
         ans[r][c] = 1;
      }
   }
   cout << "YES" << endl;
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < m; j++) cout << ans[i][j] << " "; cout << endl;
   }
}

void solve1627B()
{
   int n, m;
   cin >> n >> m;
   vector<int> ans(n * m + 1);
   int toprow = 1, bottomrow = n, leftcol = 1, rightcol = m;
   for(int i = 1; i <= n; i++)
   {
      for(int j = 1; j <= m; j++)
      {
         int diff1 = abs(i - toprow) + abs(j - leftcol);
         int diff2 = abs(i - toprow) + abs(j - rightcol);
         int diff3 = abs(i - bottomrow) + abs(j - leftcol);
         int diff4 = abs(i - bottomrow) + abs(j - rightcol);
         int curr = max(diff1, max(diff2, max(diff3, diff4)));
         ans[ ((i - 1 ) * m ) + j] = curr;
      }
   }
   sort(ans.begin(), ans.end());
   for(int i = 1; i <= n * m; i++) cout << ans[i] << " "; cout << endl;
}

void solve570B()
{
   int n, m;
   cin >> n >> m;
   if(n == 1) 
   {
      cout << 1 << endl;
      return;
   }
   if(m - 1 < n - m)
   {
      cout << m + 1 << endl;
   }
   else cout << m - 1 << endl;
   
}

void solve573A()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      while(a[i] % 2 == 0) a[i] /= 2;
      while(a[i] % 3 == 0) a[i] /= 3;
   }
   
   for(int i = 0; i + 1 < n; i++)
   {
      if(a[i] != a[i + 1])
      {
         cout << "No" << endl;
         return;
      }
   }
   cout << "Yes" << endl;

}

void solve1326C()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1), pos;
   ll sum = 0;
   ll total = 1; 
   ll mod = 998244353;
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      if(a[i] >= n - k + 1)
      {
         pos.push_back(i);
         sum += a[i];
      }
   }
   for(int i = 0; i + 1 < pos.size(); i++)
   {
      total = ( (total % mod) * ( (pos[i + 1] - pos[i]) % mod) ) % mod;
   }
   
   cout << sum << " " << total << endl;
}

void solve330B()
{
   int n, m;
   cin >> n >> m;
   unordered_map<int, bool> candidates;
   for(int i = 1; i <= n; i++) candidates[i] = true;
   for(int i = 1; i <= m; i++)
   {
      int x, y;
      cin >> x >> y;
      candidates[x] = candidates[y] = false;
   }
   
   
   int curr = -1;
   for(int i = 1; i <= n; i++)
   {
      if(candidates[i] == true) curr = i;
   }
   
   cout << n - 1 << endl;
   for(int i = 1; i <= n; i++)
   {
      if(curr == i) continue;
      cout << i << " " << curr << endl;
   }
}


void solve1607D()
{
   int n; string s;
   cin >> n;
   vector<int> a(n);
   vector<pair<char, int>> b(n + 1);
   for(int i = 0; i < n; i++) cin >> a[i];
   cin >> s;
   int l = 1, r = n;
   for(int i = 1; i <= n; i++)
   {
      b[i] = make_pair(s[i - 1], a[i - 1]);
   }
   
   sort(b.begin() + 1, b.end());
   for(int i = 1; i <= n; i++)
   {
      if(b[i].first == 'B')
      {
         if(b[i].second < i)
         {
            cout << "NO" << endl;
            return;
         }
      }
      else if (b[i].first == 'R')
      {
         if(b[i].second > i)
         {
            cout << "NO" << endl;
            return;
         }
      }
   }
   cout << "YES" << endl;
  
   
}

void solve1574C()
{
   ll n, m, sum = 0;
   cin >> n;
   vector<pair<ll, ll>> a(n);
   for(ll i = 0; i < n; i++) 
   {
      cin >> a[i].first;
      sum += a[i].first;
      a[i].second = 0;
   }
   sort(a.begin(), a.end());
   for(ll i = 0; i < n; i++) a[i].second = sum - a[i].first;
   
   cin >> m;
   while(m--)
   {
      ll x, y, ans = 0;
      cin >> x >> y;
      pair<ll, ll> p = make_pair(x, y);
      int idx = lower_bound(a.begin(), a.end(), p) - a.begin();
      ll can1 =(ll) 2e18, can2 = (ll) 2e18;
      
      if(idx >= 1)
      can1 = max(p.first - a[idx - 1].first, 0ll) + max(p.second - a[idx - 1].second, 0ll);
      if(idx < n)
      can2 = max(p.first - a[idx].first, 0ll) + max(p.second - a[idx].second, 0ll);
      ans = min(can1, can2);
      
      cout << ans << endl;
   }
}

void solve1760D()
{
   int n;
   cin >> n;
   vector<int> a(n), b;
   for(int i = 0; i < n; i++) 
   {
      cin >> a[i];
      if(i == 0 || (i >= 1 && a[i - 1] != a[i]) ) b.push_back(a[i]);
   }
   
   int cnt = 0;
   int n1 = b.size();
   
   if(n1 >= 2 && b[0] < b[1]) cnt++;
   for(int i = 1; i <= n1 - 2; i++)
   {
      if(b[i - 1] > b[i] && b[i + 1] > b[i] ) cnt++;
   }
   if(n1 >= 2 && b[n1 - 1] < b[n1 - 2]) cnt++;
   
   if(cnt > 1) cout << "NO" << endl;
   else cout << "YES" << endl;
}

void solve1760E()
{
   int n;
   cin >> n;
   vector<int> a(n), zero, one;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] == 0) zero.push_back(i);
      else one.push_back(i);
   }
   
   int os = one.size();
   int zs = zero.size();
   
   //for(auto elem : one) cout << elem << " "; cout << endl;
   //for(auto elem : zero) cout << elem << " "; cout << endl;
   
   
   ll ans = 0;
   for(int i = 0; i < os; i++)
   {
      int idx = lower_bound(zero.begin(), zero.end(), one[i]) - zero.begin();
      ans += (zs - idx);
   }
   //cout << ans << endl;
   ll curr = 0;
   for(int i = 0; i < os - 1; i++)
   {
      int idx = lower_bound(zero.begin(), zero.end(), one[i]) - zero.begin();
      curr += (zs - idx + 1);
   }
   //cout << curr << endl;
   ans = max(ans, curr);
   curr = 0;
   if(zs >= 1)
   {
      int my = zero[0];
      one.push_back(my);
      sort(one.begin(), one.end());
      vector<int> nz(zero.begin() + 1, zero.end());
      os++;
      zs--;
      for(int i = 0; i < os; i++)
      {
         int idx = lower_bound(nz.begin(), nz.end(), one[i]) - nz.begin();
         curr += (zs - idx);
      }
      //cout << curr << endl;
      ans = max(ans, curr);
   }
   cout << ans << endl;
}

void solve1760A()
{
   vector<int> a(3);
   for(int i = 0; i < 3; i++) cin >> a[i];
   sort(a.begin(), a.end());
   cout << a[1] << endl;
}

void solve1760B()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   int maxi = -1;
   for(int i = 0; i < n; i++)
   {
      maxi = max(s[i] - 'a', maxi);
   }
   cout << maxi + 1<< endl;
}

void solve1760C()
{
   int n;
   cin >> n;
   vector<pair<int, int>> a(n), b(n);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a[i] = b[i] = {x, i};
   }
   
   sort(b.begin(), b.end());
   for(int i = 0; i < n; i++)
   {
      if(a[i].second != b[n - 1].second) cout << a[i].first - b[n - 1].first << " ";
      else cout << a[i].first - b[n - 2].first << " ";
   }
   cout << endl;
}

void solve1759D()
{
   ll n, m;
   cin >> n >> m;
   int cnt2 = 0;
   int cnt5 = 0;
   ll copyn = n;
   
   while (copyn % 2 == 0)
   {
      cnt2++;
      copyn /= 2;
   }
   
   while(copyn % 5 == 0)
   {
      cnt5++;
      copyn /= 5;
   }
   //cout << cnt2 << " " << cnt5 << " " << copyn << endl;
   
   if(cnt2 != cnt5)
   {
      while(cnt2 < cnt5 && m >= 2)
      {
         cnt2++;
         m /= 2;
      }
      while(cnt5 < cnt2 && m >= 5)
      {
         cnt5++;
         m /= 5;
      }
   }
   
   while(m >= 10)
   {
      cnt2++;
      cnt5++;
      m /= 10;
   }
   
   cout << (ll) (pow(2, cnt2) * 1ll * pow(5, cnt5) * m * copyn)<< endl;
}


void solve1603A()
{
   ll n;
   cin >> n;
   vector<ll> a(n + 1);
   for(ll i = 1; i <= n; i++) cin >> a[i];
   ll lcm = 1;
   
   for(ll i = 1; i <= n; i++)
   {
      if(i <= 22) lcm = ( lcm * 1ll * (i + 1) ) / (__gcd(lcm, i + 1));
      //cout << i << " " << lcm << endl;
      if(a[i] % lcm == 0) {cout << "NO" << endl; return;}
   }
   cout << "YES" << endl;
}

void solve479C()
{
   int n;
   cin >> n;
   vector<pair<int, int>> a(n);
   for(int i = 0; i < n; i++)
   {
      int x, y;
      cin >> x >> y;
      a[i] = make_pair(x, y);
   }
   
   sort(a.begin(), a.end());
   int ans = a[0].second;
   for(int i = 1; i < n; i++)
   {
      if(ans <= a[i].second)
      {
         ans = a[i].second;
      }
      else ans = a[i].first;
   }
   cout << ans << endl;
   
}

void solve698A()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   vector<vector<int>> dp(n + 1, vector<int>(3, 0));
   for(int i = 1; i <= n; i++) cin >> a[i];
   
   for(int i = 1; i <= n; i++)
   {
      int maxi = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
      for(int j = 0; j <= 2; j++)
      {
         if(j == 0) dp[i][j] = maxi;
         else if(j == 1 && (a[i] == 1 || a[i] == 3) )
         {
            dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
         }
         else if(j == 2 && (a[i] == 2 || a[i] == 3) )
         {
            dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
         }
         else dp[i][j] = maxi;
         //cout << i << " " << j << " "<< dp[i][j] << endl;
      }
   }
   
   /*for(int i = 0; i <= n; i++) 
   {
      for(int j = 0; j <= 2; j++) cout << dp[i][j] << " "; cout << endl;
   }*/
   
   cout << n - max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}

void solve1348B()
{
   int n, k;
   cin >> n >> k;
   set<int> st;
   vector<int> a(n);
   for(int i = 0; i < n; i++) 
   {
      cin >> a[i];
      st.insert(a[i]);
   }
   if(st.size() > k) 
   {
      cout << -1 << endl;
      return;
   }
   
   int in = 1;
   while(st.size() < k)
   {
      if(st.find(in) == st.end()) st.insert(in);
      in++;
   }
   
   cout << n * st.size() << endl;
   for(int i = 1; i <= n; i++)
   {
      for(auto elem : st) cout << elem << " ";
   }
   cout << endl;
}

void solve1526B()
{
   int n;
   cin >> n;
   while(1)
   {
      if(n % 111 == 0)
      {
         cout << "YES" << endl;
         goto done;
      }
      n -= 11;
      if(n < 0) break;
   }
   
   //cout << eleven << " " << hun << endl;
   cout << "NO" << endl;
   
   done: ;
}

void solve515C()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   sort(s.begin(), s.end());
   vector<int> pref(10, 0);
   int cnt = 0;
   for(int i = 9; i >= 2; i--)
   {
      char ch = i + '0';
      int lo = lower_bound(s.begin(), s.end(), ch) - s.begin();
      int hi = upper_bound(s.begin(), s.end(), ch) - s.begin();
      //cout << ch << " " << lo << " " << hi << endl;
      cnt += hi - lo;
      pref[i] = cnt;
   }
   
   //for(int i = 2; i <= 9; i++)cout <<"(" << i << " " << pref[i] <<")";cout << endl;
   string ans;
   for(int i = 9; i >= 0; i--)
   {
      if(pref[i] == 0) continue;
      int num = i;
      if(num >= 4 && (num % 2 == 0 || num % 3 == 0))
      {
         int cnt = 0;
         while(num % 2 == 0) {cnt++; num /= 2;}
         //cout << cnt << endl;
         pref[2] += cnt * pref[i];
         cnt = 0;
         while(num % 3 == 0) {cnt++; num /= 3;}
         pref[3] += cnt * pref[i];
         pref[i] = 0;
         continue;
      }
      
      int curr = pref[i];
      for(int j = 1; j <= curr; j++) ans.push_back(i + '0');
      for(int j = i; j >= 2; j--) pref[j] -= curr;
      
   }
   //for(int i = 2; i <= 9; i++)cout <<"(" << i << " " << pref[i] <<")";cout << endl;
   cout << ans << endl;
}

void solve919B()
{
   int k;
   cin >> k;
   int cnt = 0;
   for(int i = 19; ; i++)
   {
      int num = i;
      int digitsum = 0;
      while(num > 0)
      {
         digitsum += num % 10;
         num /= 10;
      }
      if(digitsum == 10) cnt++;
      if(cnt == k)
      {
         cout << i << endl;
         break;
      }
   }
}

void solve1370C()
{
   int n;
   cin >> n;
   string a = "Ashishgup", f = "FastestFinger";
   // who gets prime or odd wins 
   // who gets n == 2 ^ p, where p >= 2 loses 
   if(n % 2 == 1)
   {
      if(n == 1) cout << f << endl;
      else cout << a << endl;
   }
   else
   {
      bool flag = true;
      int p = n / 2;
      for(int i = 2; i * i <= p; i++)
      {
         if(p % i == 0)
         {
            flag = false;
            break;
         }
      }
      
      if(n == 2) cout << a << endl;
      else if(__builtin_popcount(n) == 1) cout << f << endl;
      else if(n % 4 == 0) cout << a << endl;
      else if(flag == true) cout << f << endl;
      else if(flag == false) cout << a << endl;
   }
}

void solve1363B()
{
   string s;
   cin >> s;
   int n = s.size();
   vector<string> a;
   for(int p = 0; p <= n; p++)
   {
      int zeroes = p;
      int ones = n - p;
      string s1;
      for(int i = 1; i <= zeroes; i++) s1.push_back('0');
      for(int i = 1; i <= ones; i++) s1.push_back('1');
      a.push_back(s1);
      if(p == 0 || p == n) continue;
      reverse(s1.begin(), s1.end());
      a.push_back(s1);
   }
   
   //for(auto elem : a) cout << elem << " "; cout << endl;
   int mini = INT_MAX;
   for(auto elem : a)
   {
      int cnt = 0;
      for(int i = 0; i < n; i++)
      {
         if(s[i] != elem[i]) cnt++;
      }
      mini = min(cnt, mini);
   }
   
   cout << mini << endl;
}

void solve1365C()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), b(n + 1), c(n + 1, 0);
   //map<int, int> mp;
   for(int i = 1; i <= n; i++) {int x; cin >> x; a[x] = i;}
   for(int i = 1; i <= n; i++) {int x; cin >> x; b[x] = i;}
   for(int i = 1; i <= n; i++)
   {
      int idx1 = a[i];
      int idx2 = b[i];
      // idx1 >= idx2
      if(idx1 < idx2) idx1 += n;
      int diff = idx1 - idx2;
      //mp[diff]++;
      c[diff]++;
   }
   
   int maxi = INT_MIN;
   for(auto elem : c)
   {
      maxi = max(elem, maxi);
      //maxi = max(elem.second, maxi);
   }
   cout << maxi << endl;
}

void solve1765M()
{
   int n;
   cin >> n;
   int c = 0;
   for(int i = 2; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         c = n / i;
         break;
      }
   }
   if(c == 0) c = 1;
   cout << c << " " << n - c << endl;
}

void solve1285C()
{
   ll n;
   cin >> n;
   //if n == 2 ^ p || n is prime then answer will be 1, n;
   
   if(n & (n - 1) == 0) 
   {
      cout << 1 << " " << n;
      return;
   }
   
   ll f, s;
   for(ll i = 1; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         ll g = __gcd(i, n / i);
         ll lcm = (i * (n / i)) / g;
         if(lcm == n)
         { 
            f = i; 
            s = n / i;
         }
      }
   }
   cout << f << " " << s << endl;
}

void solve1375C()
{
   int n; 
   cin >> n;
   int f, s;
   for(int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      if(i == 1) f = x;
      if(i == n) s = x;
   }
   if(f < s) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1350B()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), ans(n + 1, 1);
   for(int i = 1; i <= n; i++) cin >> a[i];
   for(int i = 2; i <= n; i++)
   {
      int num = i;
      for(int j = 1; j * j <= num; j++)
      {
         if(num % j == 0)
         {
            if(a[j] < a[num]) ans[num] = max(ans[num], ans[j] + 1);
            if(a[num / j] < a[num]) ans[num] = max(ans[num], ans[num / j] + 1);
         }
      }
      
   }
   int maxi = 0;
   //for(int i = 1; i <= n; i++) cout << ans[i] <<" "; cout << endl;
   for(auto elem : ans) maxi = max(elem, maxi);
   cout << maxi << endl;
}

void solve507B()
{
   int r, x, y, x1, y1;
   cin >> r >> x >> y >> x1 >> y1;
   ll dist = (x - x1) * 1ll * (x - x1) + (y - y1) * 1ll * (y - y1);
   ll jump = r * 4ll * r;
   //cout << dist << " " << jump << endl;
   cout << ceil(sqrt(ceil(dist * 1.0/ jump))) << endl;
}

void solve514B()
{
   int n, x, y;
   cin >> n >> x >> y;
   vector<pair<int, int>> a(n);
   vector<bool>b(n, true);
   for(int i = 0; i < n; i++)
   {
      int p, q;
      cin >> p >> q;
      a[i] = make_pair(p, q);
   }
   
   int cnt = 0;
   for(int i = 0; i < n; i++)
   {
      if(b[i] == true)
      {
         cnt++;
         b[i] = false;
         for(int j = i + 1; j < n; j++)
         {
            if(b[j] == true)
            {
               int x1 = a[i].first;
               int y1 = a[i].second;
               int x2 = a[j].first;
               int y2 = a[j].second;
               if( (y1 - y) *  (x2 - x)  == (y2 - y) * (x1 - x) ) b[j] = false;
            }
         }
      }
   }
   cout << cnt << endl;
}

void solve414B()
{
   ll n, k;
   cin >> n >> k;
   if(k == 1)
   {
      cout << n << endl;
      return;
   }
   ll mod = 1e9 + 7;
   vector<vector<ll>> a(k + 1, vector<ll> (n + 1, 0ll));
   
   ll sum1 = 0;
   for(int col = 1; col <= n; col++) 
   {
      a[2][col] = n / col;
      sum1 = (sum1 + a[2][col]) % mod;
   }
   for(int row = 3; row <= k; row++)
   {
      for(int col = 1; col <= n; col++)
      {
         if(col == 1)
         {
            a[row][col] = sum1;
            continue;
         }
         ll sum = 0;
         for(int c = col; c <= n; c += col)
         {
            sum = (sum + a[row - 1][c]) % mod;
         }
         a[row][col] = sum;
         sum1 = (sum + sum1) % mod;
      }
   }
   
   cout << sum1 << endl;
}

void solve1369C()
{
   int n, k;
   cin >> n >> k;
   vector<ll> a(n), b(k);
   for(auto &e : a) cin >> e;
   for(int i = 0; i < k; i++) {cin >> b[i]; b[i] -= 1;}
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   
   //for(auto elem : a) cout << elem << " "; cout << endl;
   //for(auto elem : b) cout << elem << " "; cout << endl;
   
   ll ans = 0;
   for(int i = 1; i <= k; i++) ans += a[n - i];
   //cout << ans << endl;
   
   int curr = n - k;
   for(int i = 0; i < k; i++)
   {
      int seek = b[i];
      if(seek == 0)
      {
         ans += a[n - i - 1];
         continue;
      }
      curr -= seek;
      ans += a[curr];
   }
   
   cout << ans << endl;
}

void solve1475C()
{
   ll a, b, k;
   cin >> a >> b >> k;
   vector<int> boys(a + 1, 0), girls(b + 1, 0);
   
   ll ans = (k * 1ll * (k - 1)) / 2;
   for(int i = 0; i < k; i++)
   {
      int x;
      cin >> x;
      boys[x]++;
   }
   for(int i = 0; i < k; i++)
   {
      int x;
      cin >> x;
      girls[x]++;
   }
   
   for(int i = 1; i <= a; i++)
   {
      ll curr = boys[i];
      ans = ans - (curr * (curr - 1)) / 2;
   }
    for(int i = 1; i <= b; i++)
   {
      ll curr = girls[i];
      ans = ans - (curr * (curr - 1)) / 2;
   }
   //for(auto elem : boys) cout << elem << " "; cout << endl;
   //for(auto elem : girls) cout << elem << " "; cout << endl;
   cout << ans << endl;
}

void solve1380C()
{
   ll n, x;
   cin >> n >> x;
   vector<ll> a(n);
   for(ll i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   ll ans = 0;
   ll curr = n - 1;
   for(ll i = n - 1; i >= 0; i--)
   {
      ll elements = curr - i + 1;
      if(a[i] * elements >= x)
      {
         ans++;
         curr = i - 1;
      }
   }
   cout << ans << endl;
}

void solve1506D()
{
   int n;
   cin >> n;
   map<int, int> mp;
   priority_queue<int> maxpq;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      mp[x]++;
   }
   for(auto elem : mp)
   {
      maxpq.push(elem.second);
   }
   
   int ans = n;
   
   while(maxpq.size() >= 2)
   {
      int cnt1 = maxpq.top();
      maxpq.pop();
      int cnt2 = maxpq.top();
      maxpq.pop();
      cnt1--; cnt2--; ans -= 2;
      if(cnt1 > 0) maxpq.push(cnt1);
      if(cnt2 > 0) maxpq.push(cnt2);
   }
   
   cout << ans << endl;
}

void solve401C()
{
   int zeroes, ones;
   cin >> zeroes >> ones;
   int mini = zeroes - 1;
   int maxi = (zeroes + 1) * 2;
   if(ones < mini || ones > maxi)
   {
      cout << - 1 << endl;
      return;
   }
   
   int smaller, bigger;
   char sc, bc;
   if(zeroes <= ones)
   {
      smaller = zeroes;
      sc = '0';
      bigger = ones;
      bc = '1';
   }
   else
   {
      smaller = ones;
      sc = '1';
      bigger = zeroes;
      bc = '0';
   }
   int i = 0;
   vector<int> a(smaller, 0);
   while(bigger > 1)
   {
      a[i]++;
      bigger--;
      i = (i + 1) % smaller;
   }
   
   //for(auto elem : a) cout << elem << " "; cout << endl;
   string s, first;
   bool f = false;
   for(i = 0; i < smaller; i++)
   {
      s.push_back(sc);
      int cnt = a[i];
      if(cnt > 2) f = true;
      for(int j = 1; j <= min(cnt, 2); j++) s.push_back(bc);
   }
   first.push_back(bc);
   if(f) first.push_back(bc);
   first = first + s;
   cout << first << endl;
}

void solve1520E()
{
   ll n;
   cin >> n;
   string s;
   cin >> s;
   vector<ll> a;
   for(ll i = 0; i < n; i++)
   {
      if(s[i] == '*') a.push_back(i + 1);
   }
   
   ll ans = 0;
   ll sz = a.size();
   //for(auto elem : a) cout << elem << " "; cout << endl;
   if(sz >= 2)
   {
      ll mid = sz / 2;
      ll curr = a[mid];
      for(ll i = mid; i >= 0; i--)
      {
         ans += abs(curr - a[i]);
         curr--;
      }
      curr = a[mid];
      for(ll i = mid; i < sz; i++)
      {
         ans += abs(curr - a[i]);
         curr++;
      }
      
   }
   cout << ans << endl;
}

void solve1201C()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(n);
   for(auto &e : a) cin >> e;
   sort(a.begin(), a.end());
   ll median = n / 2;
   ll medianItem = a[median];
   
   ll lo = 0, hi = k, ans = -1;
   while(hi - lo >= 0)
   {
      ll mid = lo + (hi - lo) / 2;
      ll newmedianItem = medianItem + mid;
      ll newk = k;
      for(ll i = median; i < n; i++)
      {
         if(a[i] < newmedianItem)
         {
            newk -= newmedianItem - a[i];
         }
      }
      
      if(newk >= 0)
      {
         ans = newmedianItem;
         lo = mid + 1;
      }
      else
      {
         hi = mid - 1;
      }
   }
   
   cout << ans << endl;
   
}

void solve1463B()
{
   int n = 50;
   cin >> n;
   vector<int> a(n);
   ll sum = 0;
   for(auto &e : a) {cin >> e; sum += e;}
   ll oddsame = 0, evensame = 0;
   for(int i = 1; i < n; i += 2) evensame += a[i] - 1;
   for(int i = 0; i < n; i += 2) oddsame += a[i] - 1;
   if(2 * evensame <= sum)
   {
      for(int i = 0; i < n; i++) 
      {
         int toprint = (i % 2 == 0) ? a[i] : 1;
         cout << toprint << " ";
      }
   }
   else
   {
      for(int i = 0; i < n ; i++) 
      {
         int toprint = (i % 2 == 1) ? a[i] : 1;
         cout << toprint << " ";
      }
   }
   cout << endl;
   
}

void solve1355D()
{
   int n, s;
   cin >> n >> s;
   int ones = n - 1;
   int last = s - n + 1;
   if(ones + 1 >= last)
   {
      cout << "NO" << endl;
   }
   else
   {
      cout << "YES" << endl;
      for(int i = 1; i <= n - 1; i++) cout << 1 << " ";
      cout << last << endl;
      cout << n << endl;
   }
}

void solve538B()
{
   string s;
   cin >> s;
   vector<string> ans;
   int cnt = 0;
   for(int i = 0; i < s.size(); i++)
   {
      if(s[i] != '0') cnt += (s[i] - '0');
   }
   //cout << cnt << endl;
   while(cnt > 0)
   {
      string curr;
      bool positive = false;
      for(int i = 0; i < s.size(); i++)
      {
         if(s[i] > '0')
         {
            curr.push_back('1');
            s[i] = s[i] - 1;
            cnt--;
            positive = true;
         }
         else 
         {
            if(positive != false) curr.push_back('0');
         }
      }
      ans.push_back(curr);
   }
   
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem << " "; cout << endl;
}

void solve1762B()
{
   int n, maxi = -1;
   cin >> n;
   vector<pair<int, int>> a(n);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a[i] = make_pair(x, i + 1);
   }
   
   sort(a.begin(), a.end());
   //cout << n << endl;
   vector<pair<int, int>> ans;
   for(int i = 1; i < n; i++)
   {
      int rem = a[i].first % a[i - 1].first;
      if(rem == 0) continue;
      int add = a[i - 1].first - rem;
      a[i].first += add;
      ans.push_back(make_pair(a[i].second, add));
   }
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem.first << " " << elem.second << endl;
}

void solve1362C()
{
   ll n;
   cin >> n;
   // 2 ^ (p + 1) - 1 where p is the maximum power of 2 such that 2 ^ p <= n;
   ll bit = 0;
   ll ans = 0;
   while(n > 0)
   {
      if(n & 1 == 1)
      {
         ans += (ll)pow(2, bit + 1) - 1;
      }
      n = n >> 1;
      bit++;
   }
   cout << ans << endl;
}

void solve550B()
{
   ll n, l, r, x;
   cin >> n >> l >> r >> x;
   vector<ll> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
}

void solve1731A()
{
   ll n, ans = 1ll; 
   cin >> n;
   for(ll i = 0; i < n; i++) 
   {
      ll x;
      cin >> x;
      ans = ans * x;
   }
   ans += n - 1;
   ans *= 2022;
   cout << ans << endl;
}

void solve1731B()
{
   ll mod = 1e9 + 7;
   ll n;
   cin >> n;
   ll ans = 0;
   ll ans1 = ((( (n * (n - 1)) % mod) * (4 * n + 1) % mod) * 337) % mod;
   ll ans2 = (((2022ll * n) % mod) * n ) % mod;
   ans = (ans1 + ans2) % mod;
   cout << ans % mod << endl;
   
}

void solve1393B()
{
   int n, q, sz = 1e5 + 7;
   cin >> n;
   map<int, int> a;
   for(int i = 0; i < n; i++) 
   {
      int x;
      cin >> x;
      a[x]++;
   }
   int cnt4 = 0, cnt2 = 0;
   for(auto elem : a)
   {
      if(elem.second >= 4)
      {
         cnt4 += elem.second / 4;
         if(elem.second % 4 >= 2) cnt2++;
      }
      else cnt2 += elem.second / 2;
   }
   
   //cout << cnt4 << " " << cnt2 << endl;
   cin >> q;
   while(q--)
   {
      char sign;
      cin >> sign;
      int x;
      cin >> x;
      if(sign == '+')
      {
         a[x]++;
         if(a[x] % 4 == 0) {cnt4++; cnt2--;}
         else if(a[x] % 4 == 2) cnt2++;
         
      }
      else
      {
         //cout << "minus";
         if(a[x] % 4 == 0) {cnt4--; cnt2++;}
         else if(a[x] % 4 == 2) cnt2--;
         a[x]--;
      }
      //cout << sign << " " << x <<" "<< cnt4 << " " << cnt2 << endl;
      if(cnt4 >= 2 || (cnt4 >= 1 && cnt2 >= 2)) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
}

void solve1490E()
{
   ll n, maxi = -1, sum = 0;
   cin >> n;
   vector<pair<ll, ll>> a(n);
   for(int i = 0; i < n; i++)
   {
      ll x;
      cin >> x;
      a[i] = make_pair(x, i + 1);
   }
   
   sort(a.begin(), a.end());
   vector<pair<ll, ll>> pref(n, make_pair(0, 0) );
   vector<ll> ans;
   pref[0].first = a[0].first;
   pref[0].second = a[0].second;
   for(int i = 1; i < n; i++)
   {
      pref[i].first = pref[i  - 1].first + a[i].first;
      pref[i].second = a[i].second;
   }
   ans.push_back(a.back().second);
   pair<ll, ll> curr = a.back();
   for(int i = n - 2; i >= 0; i--)
   {
      if(pref[i].first >= curr.first)
      {
         ans.push_back(pref[i].second);
         curr = a[i];
      }
   }
   
   sort(ans.begin(), ans.end());
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem << " "; cout << endl;
}


void solve977D()
{
   ll n, common = 1;
   cin >> n;
   vector<pair<ll, ll>> a(n);
   for(ll i = 0; i < n; i++)
   {
      ll x;
      cin >> x;
      ll cnt2 = 0;
      ll cnt3 = 0;
      while(x % 2 == 0)
      {
         x /= 2;
         cnt2++;
      }
      while(x % 3 == 0)
      {
         x /= 3;
         cnt3++;
      }
      a[i] = make_pair(cnt2, cnt3);
      common = x;
   }
   sort(a.begin(), a.end(), [](pair<ll, ll> a, pair<ll, ll> b)
   {
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first;
   });
   
   for(auto elem : a) 
   {
      ll pow2 = pow(2, elem.first);
      ll pow3 = pow(3, elem.second);
      ll x = pow2 * pow3 * common;
      cout << x << " ";
   }
   cout << endl;
}

void solve546C()
{
   int n, n1, n2;
   cin >> n;
   queue<int> f, s;
   cin >> n1;
   for(int i = 0; i < n1; i++)
   {
      int x;
      cin >> x;
      f.push(x);
   }
   cin >> n2;
   for(int i = 0; i < n2; i++) 
   {
      int x;
      cin >> x;
      s.push(x);
   }
   int ans = 0;
   int winner = -1;
   bool nowinner = false;
   while(f.size() > 0 && s.size() > 0)
   {
      int ff = f.front();
      int ss = s.front();
      f.pop();
      s.pop();
      if(ff > ss)
      {
         f.push(ss);
         f.push(ff);
      }
      else
      {
         s.push(ff);
         s.push(ss);
      }
      ans++;
      if(ans > int(1e7)) {nowinner = true; break;}
   }
   if(nowinner == true)
   {
      cout << -1 << endl;
      return;
   }
   if(f.size() == 0) winner = 2;
   else winner = 1;
   cout << ans << " " <<  winner<< endl;
}

void solve289B()
{
   int n, m, d;
   cin >> n >> m >> d;
   int sz = n * m;
   vector<int> a(sz);
   for(int i = 0 ; i < sz; i++) cin >> a[i];
   sort(a.begin(), a.end());
   for(int i = 1; i < sz; i++)
   {
      if(((a[i] - a[i - 1]) % d) != 0)
      {
         cout << -1 << endl;
         return;
      }
   }
   
   int mid = sz / 2;
   ll ans = 0;
   for(int i = 0; i < sz; i++)
   {
      ans += (abs(a[i] - a[mid]) / d);
   }
   cout << ans << endl;
}

void solve1779B()
{
   int n;
   cin >> n;
   if(n == 3) 
   {
      cout << "NO" << endl;
      return;
   }
   vector<int> a(n);
   if(n % 2 == 0)
   {
      for(int i = 0; i < n; i++)
      {
         if(i % 2 == 0) a[i] = -1;
         else if(i % 2 == 1) a[i] = 1;
      }
   }
   
   else
   {
      for(int i = 0; i < n; i++)
      {
         if(i % 2 == 0) a[i] = (-1) * n;
         else a[i] = 2 * n;
      }
   }
   
   cout << "YES" << endl;
   for(auto elem : a) cout << elem << " "; cout << endl;
}

void solve1382B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   
   if(a[0] > 1)
   {
      cout << "First" << endl;
      return;
   }
   
   int i = 0, cnt = 0;
   while(i < n - 1 && a[i] == 1) {cnt++; i++;}
   
   if(cnt % 2 == 0) cout << "First" << endl;
   else cout << "Second" << endl;
}

void solve1548A()
{
   int n, m;
   cin >> n >> m;
   vector<set<int>>a(n + 1);
   for(int i = 1; i <= n; i++) a[i].insert(i);
   int ans = n;
   while(m--)
   {
      int u, v;
      cin >> u >> v;
      if(u > v) swap(u, v); // u will have smaller
      if(a[u].size() == 1) ans--;
      a[u].insert(v);
   }
   
   int q;
   cin >> q;
   while(q--)
   {
      int type;
      cin >> type;
      if(type == 1)
      {
         int u, v;
         cin >> u >> v;
         if(u > v) swap(u, v);
         if(a[u].size() == 1) ans--;
         a[u].insert(v);
      }
      else if(type == 2)
      {
         int u, v;
         cin >> u >> v;
         if(u > v) swap(u, v);
         a[u].erase(v);
         if(a[u].size() == 1) ans++;
      }
      else if(type == 3)
      {
         cout << ans << endl;
      }
   }
}

void solve1182A()
{
   int n;
   cin >> n;
   if(n % 2 == 1) cout << 0 << endl;
   else cout << (int) pow(2, n / 2) << endl;
}

void solve1462D()
{
   ll n;
   cin >> n;
   vector<ll> a(n), b;
   for(int i = 0; i < n; i++) cin >> a[i];
   
   ll ans = n - 1;
   ll currsum = 0;
   for(int i = 0; i < n; i++)
   {
      currsum += a[i];
      b.push_back(currsum);
      ll sum = 0;
      ll j;
      for(j = i + 1; j < n; j++)
      {
         sum += a[j];
         if(sum < currsum) continue;
         else if (sum == currsum) 
         {
            b.push_back(sum); 
            sum = 0;
            
         }
         else 
         {
            b.clear();
            break;
         }
      }
      if(j == n)
      {
         //for(auto elem : b) cout << elem << " "; cout << endl;
         if(sum == 0)ans = min(ans, (ll)abs((ll)a.size() - (ll)b.size()));
         else ans = min(ans, n - 1);
         b.clear();
      }
   }
   cout << ans << endl;
}

void solve1783A()
{
   int n;
   cin >> n; 
   vector<int> a(n), b(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   int i = 0, j = n - 1, k;
   for(k = 0; k < n; k++)
   {
      if(k % 2 == 0) b[k] = a[j--];
      else b[k] = a[i++];
   }
   //for(auto elem : b) cout << elem << " "; cout << endl;
   int sum = 0;
   for(i = 0; i < n; i++)
   {
      if(sum == b[i])
      {
         cout << "NO" << endl;
         return;
      }
      sum += b[i];
   }
   
   cout << "YES" << endl;
   for(auto elem : b) cout << elem << " "; cout << endl;
}


void solve1141A()
{
   int n, m;
   cin >> n >> m;
   map<int, int> mp;
   for(int i = 2; i * i <= m; i++)
   {
      int cnt = 0;
      while(m % i == 0) 
      {
         cnt++; 
         m /= i;
      }
      mp[i] = cnt;
   }
   if(m > 1) mp[m] = 1;
   
   for(int i = 2; i * i <= n; i++)
   {
      int cnt = 0;
      while(n % i == 0)
      {
         cnt++;
         n /= i;
      }
      mp[i] -= cnt;
   }
   if(n > 1) mp[n] -= 1;
   int ans = 0;
   for(auto elem : mp)
   {
      if( (elem.first <= 3 && elem.second < 0) || (elem.first > 3 && elem.second != 0))
      {
         cout << -1 << endl;
         return;
      }
      ans += elem.second;
   }
   cout << ans << endl;
}

void solve118B()
{
   int n;
   cin >> n;
   for(int i = 0; i <= n; i++)
   {
      int spaces = 2 * (n - i);
      for(int j = 1; j <= spaces; j++)
      {
         cout << " ";
      }
      int cnt = 0;
      for(int numbers = 1; numbers <= 2 * i + 1; numbers++)
      {
         if(numbers < 2 * i + 1)cout << cnt << " ";
         else cout << cnt;
         
         if(numbers < i + 1)cnt++;
         else cnt--;
      }
      cout << endl;
   }
   
   for(int i = 1; i <= n; i++)
   {
      int spaces = 2 * i;
      for(int j = 1; j <= spaces; j++)
      {
         cout << " ";
      }
      int cnt = 0;
      int numbers = 2 * n - (2 * i - 1);
      for(int j = 1; j <= numbers; j++)
      {
         if(j < numbers)cout << cnt << " ";
         else cout << cnt;
         
         if(j < (numbers + 1) / 2)cnt++;
         else cnt--;
      }
      cout << endl;
   }
}

void solve1772D()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   int mini = 0, maxi = 1e9;
   
   for(int i = 0; i + 1 < n; i++)
   {
      if(a[i] < a[i + 1])
      {
         if(maxi == 1e9) maxi = (a[i] + a[i + 1]) / 2;
         else maxi = min(maxi, (a[i] + a[i + 1]) / 2);
      }
      else if (a[i] > a[i + 1]) 
      {
         if(mini == 0) mini = (a[i] + a[i + 1] + 1) / 2;
         else mini = max(mini, (a[i] + a[i + 1] + 1) / 2);
      }
   }
   if(mini <= maxi) cout << mini << endl;
   else cout << -1 << endl;
}

void solve1395A()
{
   int r, g, b, w;
   cin >> r >> g >> b >> w;
   int odds = 0;
   if(r % 2 == 1) odds++;
   if(g % 2 == 1) odds++;
   if(b % 2 == 1) odds++;
   if(w % 2 == 1) odds++;
   if(odds > 1)
   {
      if(r == 0 || g == 0 || b == 0)
      {
         cout << "No" << endl;
         return;
      }
      else
      {
         w += 3;
         r--; g--; b--;
         odds = 0;
         if(r % 2 == 1) odds++;
         if(g % 2 == 1) odds++;
         if(b % 2 == 1) odds++;
         if(w % 2 == 1) odds++;
      }
   }
   if(odds > 1) cout << "No" << endl;
   else cout << "Yes" << endl;
}


void solve1783B()
{
   int n;
   cin >> n;
   vector<int> a(n * n + 1);
   int p = n * n;
   for(int i = 1; i <= n * n; i += 2) a[i] = p--;
   p = 1;
   for(int i = 2; i <= n * n; i += 2) a[i] = p++;
   vector<vector<int>> b(n, vector<int>(n));
   p = 1;
   for(int i = 0; i < n; i++)
   {
      if(i % 2 == 0)
      {
         for(int j = 0; j < n; j++) b[i][j] = a[p++];
      }
      else
      {
         for(int j = n - 1; j >= 0; j--) b[i][j] = a[p++];
      }
   }
   for(auto elem : b)
   {
      for(auto e : elem) cout << e << " "; cout << endl;
   }
}

void solve1312C()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(n), b(100, 0);
   for(auto &e: a) cin >> e;
   for(int i = 0; i < n; i++)
   {
      if(a[i] == 0) continue;
      ll p = a[i];
      int l = 0;
      while(p > 0)
      {
         ll rem = p % k;
         b[l++] += rem;
         p /= k;
         
      }
   }
   
   //for(auto elem : b) cout << elem << " "; cout << endl;
   for(auto elem : b)
   {
      if(elem > 1) {cout << "NO" << endl; return;}
   }
   cout << "YES" << endl;
}



void solve1515C()
{
   ll n, m, x;
   cin >> n >> m >> x;
   vector<pair<ll, ll>> a(n);
   for(ll i = 0; i < n; i++)
   {
      ll x;
      cin >> x;
      a[i] = make_pair(x, i + 1);
   }
   
   sort(a.begin(), a.end());
   vector<pair<ll, ll>> b(n);
   ll f = 1;
   for(ll i = 0; i < n; i++)
   {
      ll s= a[i].second;
      b[i] = make_pair(s, f);
      f++;
      if(f > m) f = 1;
   }
   sort(b.begin(), b.end());
   cout << "YES" << endl;
   for(auto elem : b) cout << elem.second << " "; cout << endl;
}

void solve1095C()
{
   int n, k;
   cin >> n >> k;
   int n1 = n;
   priority_queue<int> pq;
   int id = 1;
   while(n > 0)
   {
      if(n & 1 == 1) pq.push(id);
      id *= 2;
      n = n >> 1;
   }
   
   if(k < pq.size() || k > n1) cout << "NO" << endl;
   else
   {
      cout << "YES" << endl;
      while(pq.size() < k)
      {
         int k = pq.top();
         pq.pop();
         pq.push(k / 2);
         pq.push(k / 2);
      }
      while(pq.size() > 0) 
      {
         cout << pq.top() << " ";
         pq.pop();
      }
      cout << endl;
   }
}

void solve8B()
{
   string s;
   cin >> s;
   vector<vector<bool>> a(200, vector<bool>(200, false));
   int x = 100, y = 100;
   a[x][y] = true;
   bool flag = false;
   for(int i = 0; i < s.size(); i++)
   {
      /*if(s[i] == 'L')
      {
         if(a[x - 1][y] || a[x - 1][y - 1] || a[x - 1][y + 1] || a[x - 2][y]) 
         {
            flag = true; 
            break;
         }
         x--;
      }
      else if(s[i] == 'R') 
      {
         if(a[x + 1][y] || a[x + 1][y - 1] || a[x + 1][y + 1] || a[x + 2][y]) {flag = true; break;}
         x++;
      }
      else if(s[i] == 'U') 
      {
         if(a[x][y + 1] || a[x - 1][y + 1] || a[x + 1][y + 1] || a[x][y + 2]) 
         {
            flag = true; 
            break;
         }
         y++;
      }
      else 
      {
         if(a[x][y - 1] || a[x - 1][y - 1] || a[x + 1][y - 1] || a[x][y - 2]) 
         {
            flag = true; 
            break;
         }
         y--;
      }
      
      a[x][y] = true;
      */
      if(s[i] == 'L') x--;
      else if(s[i] == 'R') x++;
      else if(s[i] == 'U') y++;
      else y--;
      if(a[x][y] == true)  {cout << "BUG" << endl; return;}
      a[x][y] = true;
      int cnt = 0;
      if(a[x - 1][y]) cnt++;
      if(a[x + 1][y]) cnt++;
      if(a[x][y - 1]) cnt++;
      if(a[x][y + 1]) cnt++;
      
      if(cnt > 1)
      {
         flag = true;
         break;
      }
   }
   if(flag == true) cout << "BUG" << endl;
   else cout << "OK" << endl;
}


void solve688B()
{
   string s, ans;
   cin >> s;
   ans = s;
   reverse(s.begin(), s.end());
   ans += s;
   cout << ans << endl;
}

void solve1303B()
{
   ll n, g, b, ans;
   cin >> n >> g >> b;
   ans = n;
   if(g >= b) cout << ans << endl;
   else
   {
      ll t = g + b;
      ll total = n / t;
      ll rem = n % t;
      ll good = (total * 1ll * g) + min(g, rem);
      ll bad = (total * 1ll * b) + max(0ll, rem - g);
      //cout << "good " << good << " bad " << bad << endl;
      if(good >= bad)
      {
         cout << ans << endl;
      }
      else
      {
         ll incgood = good % g;
         good -= incgood;
         bad += incgood;
         //cout << "incgood " << incgood << " new good " << good << " new bad " << bad << endl;
         ans = (good * t) / g;
         //cout << ans << endl;
         ll diff = (bad - good + 1) / 2;
         ll pg = diff / g;
         ll rem2 = diff % g;
         //cout << "diff " << diff << " pg " << pg << " rem2 " << rem2 << endl; 
         ll additional;
         if(rem2 == 0) additional = pg * t - b;
         else additional = pg * t + rem2;
         //cout << "additional " << additional << endl;
         ans += additional;
         cout << ans << endl;
      }
   }
}

void solve762A()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(1e5, 1e18);
   int cnt = 0;
   for(ll i = 1; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         //a.push_back(i);
         a[cnt++] = i;
         //if(i != n / i) a.push_back(n / i);
         if(i != n / i) a[cnt++] = n / i;
      }
   }
   //cout << cnt << endl;
   sort(a.begin(), a.end());
   
   if(k > cnt) cout << -1 << endl;
   else cout << a[--k] << endl;
}

void solve1740C()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(auto& e : a) cin >> e;
   sort(a.begin(), a.end());
   ll ans = 0;
   for(int i = 0; i <= n - 3; i++)
   {
      ans = max(ans, abs(a[i + 1] - a[i]) + abs(a[n - 1] - a[i]));
   }
   
   for(int i = n - 1; i >= 2; i--)
   {
      ans = max(ans, abs(a[i] - a[i - 1]) + abs(a[i] - a[0]));
   }
   cout << ans << endl;
}

void solve1764C()
{
   ll n;
   cin >> n;
   vector<ll> a(n), pref(n, 0), suff(n , 0);
   for(auto& e: a) cin >> e;
   sort(a.begin(), a.end());
   for(int i = 1; i < n; i++)
   {
      if(a[i] == a[i - 1]) pref[i] = pref[i - 1] + 1;
      else pref[i] = 0;
   }
   for(int i = n - 2; i >= 0; i--)
   {
      if(a[i] == a[i + 1]) suff[i] = suff[i + 1] + 1;
      else suff[i] = 0;
   }
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   //for(auto elem : suff) cout << elem << " "; cout << endl;
   
   ll ans = 0;
   for(int i = 0; i <= n - 1; i++)
   {
      ll left = i - pref[i];
      ll mul = n - i;
      ll ans1 = left * 1ll * mul;
      //ll ans2 = n - i - suff[i];
      //ans2 = ans2 + ans2 * (i - 1);
      //cout << i << " element " << a[i] << " ans1 " <<  ans1 << " ans2 " << ans2 << endl;
      ans = max(ans, ans1);
   }
   ll cnt = 0;
   for(int i = 0; i <= n - 1; i++)
   {
      if(pref[i] % 2 == 1) cnt++;
   }
   ans = max(cnt, ans);
   cout << ans << endl;
}

void solve1184B1()
{
   int s, b;
   cin >> s >> b;
   vector<int> a(s);
   vector<pair<int, int>> base(b);
   vector<int> pref(b, 0);
   for(int i = 0; i < s; i++) cin >> a[i];
   for(int i = 0; i < b; i++)
   {
      int x, y;
      cin >> x >> y;
      base[i] = make_pair(x, y);
   }
   sort(base.begin(), base.end());
   pref[0] = base[0].second;
   for(int i = 1; i < b; i++) pref[i] = pref[i - 1] + base[i].second;
   for(int i = 0; i < s; i++)
   {
      int curr = a[i];
      int idx = upper_bound(base.begin(), base.end(), make_pair(curr, INT_MAX)) - base.begin();
      idx--;
      if(idx >= 0 && idx < b) cout << pref[idx] << " ";
      else cout << 0 << " ";
   }
   cout << endl;
}

void solve766B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto& e: a) cin >> e;
   sort(a.begin(), a.end());
   for(int i = 0; i + 2 < n; i++)
   {
      if(a[i] + a[i + 1] > a[i + 2])
      {
         cout << "YES" << endl;
         return;
      }
   }
   cout << "NO" << endl;
}

void solve1771B()
{
   ll n, m;
   cin >> n >> m;
   vector<ll> a(n + 1, -1);
   vector<pair<ll, ll>> b(m);
   ll total = (n * 1ll * (n + 1)) / 2;
   for(ll i = 0; i < m; i++)
   {
      ll x, y;
      cin >> x >> y;
      if(x > y) swap(x, y);
      b[i] = make_pair(x, y);
   }
   //sort(b.begin(), b.end());
   
   for(ll i = 0; i < m; i++)
   {
      ll f = b[i].first;
      ll s = b[i].second;
      a[f] = max(a[f], n - s + 1);
   }
   ll sum = 0;
   for(ll i = n - 1; i >= 1; i--)
   {
      a[i] = max(a[i], a[i + 1]);
      sum = sum + (a[i] == -1? 0 : a[i]);
   }
   //cout << total << " " << sum << endl;
   cout << total - sum << endl;
}

void solve1320A()
{
   int n;
   cin >> n;
   unordered_map<ll, ll> a;
   for(ll i = 1; i <= n; i++)
   {
      ll x;
      cin >> x;
      a[x - i] += x;
   }
   ll ans = 0;
   for(auto elem : a) ans = max(ans, elem.second);
   cout << ans << endl;
}

void solve1733D1()
{
   ll n, x, y;
   cin >> n >> x >> y;
   string a, b;
   cin >> a >> b;
   ll cnt = 0, ans = 0;
   bool adj = false;
   for(ll i = 0; i < n; i++)
   {
      if(a[i] != b[i]) 
      {
         cnt++;
         if(i >= 0 && a[i - 1] != b[i - 1]) adj = true;
      }
   }
   
   if(cnt % 2 == 1)
   {
      cout << -1 << endl;
      return;
   }
   if(cnt >= 4) ans = (cnt / 2) * 1ll * y;
   else if(cnt == 2)
   {
      if(adj == true)
      {
         if(x > 2 * y) ans = 2 * y;
         else ans = x;
      }
      else ans = y;
   }
   cout << ans << endl;
}

void solve1790A()
{
   string pi = "3141592653589793238462643383279";
   string s;
   cin >> s;
   int cnt = 0;
   for(int i = 0; i < s.size(); i++)
   {
      if(s[i] == pi[i]) cnt++;
      else break;
   }
   cout << cnt << endl;
}

void solve1790B()
{
   int n, s, r;
   cin >> n >> s >> r;
   vector<int> a;
   a.push_back(s - r);
   int t = r / (n - 1);
   int rem = r % (n - 1);
   for(int i = 1; i <= n - 1; i++) a.push_back(t);
   for(int i = n - 1; i >= 0 && rem > 0; i--, rem--) a[i]++;
   for(auto elem : a) cout << elem << " "; cout << endl;
}

void solve1790C()
{
   int n;
   cin >> n;
   vector<int> cnt(n + 1, 0);
   vector<int> st;
   vector<vector<int>> a(n, vector<int> (n - 1));
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n - 1; j++) cin >> a[i][j];
   }
   
   for(int col = 0; col < n - 1; col++)
   {
      for(int row = 0; row < n; row++)
      {
         int curr = a[row][col];
         cnt[curr]++;
      }
      int maxi1 = 0, maxi2 = 0, id1, id2;
      for(int i = 1; i <= n; i++)
      {
         if(cnt[i] > maxi1)
         {
            maxi1 = cnt[i];
            id1 = i;
         }
      }
      if(st.size() == 0)st.push_back(id1);
      for(int i = 1; i <= n; i++)
      {
         if(cnt[i] > maxi2 && i != id1)
         {
            maxi2 = cnt[i];
            id2 = i;
         }
      }
      //cout << id1 << " " << id2 << endl;
      if(st.size() == 1) st.push_back(id2);
      else
      {
         int b = st.back();
         if(id1 == b) st.push_back(id2);
         else st.push_back(id1);
      }
      cnt[id1] = cnt[id2] = 0;
   }
   
   for(auto elem : st) cout << elem << " "; cout << endl;
}

void solve1790D()
{
   int n;
   cin >> n;
   multiset<int> a;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a.insert(x);
   }
   
   int cnt = 0;
   while(a.size() > 0)
   {
      
      int curr = *a.begin();
      a.erase(a.begin());
      int tosee = curr + 1;
      while(a.find(tosee) != a.end())
      {
         a.erase(a.find(tosee));
         tosee++;
      }
      cnt++;
   }
   
   cout << cnt << endl;
}

void solve1425A()
{
   ll n, curr;
   cin >> n;
   curr = n;
   bool f = true;
   ll ans = 0;
   while(n > 0)
   {
      if(f == true)
      {
         if(n % 2 == 0)
         {
            if(n % 4 != 0 || n == 4)
            {
               n /= 2;
               ans += n;
               f = false;
            }
            else
            {
               ans += 1;
               n -= 1;
               f = false;
            }
         }
         else
         {
            ans += 1;
            n--;
            f = false;
         }
      }
      else
      {
         if(n % 2 == 0)
         {
            if(n % 4 != 0 || n == 4)
            {
               n /= 2;
               f = true;
            }
            else
            {
               n -= 1;
               f = true;
            }
         }
         else
         {
            n--;
            f = true;
         }
      }
   }
   cout << ans << endl;
}

void solve1514B()
{
   ll n, k, mod = 1e9 + 7;
   cin >> n >> k;
   ll power = 1;
   for(int i = 1; i <= k; i++) power = ( (power % mod) * (n % mod) ) % mod;
   cout << power << endl;
}

void solve630C()
{
   vector<ll> a(56);
   for(int i = 0; i < 56; i++) a[i] = (ll) pow(2, i);
   ll m, ans = 0;
   cin >> m;
   for(int i = 1; i <= m; i++) ans += a[i];
   cout << ans << endl;
}

void solve1543A()
{
   ll a, b;
   cin >> a >> b;
   if(a < b) swap(a, b);
   ll diff = a - b;
   ll f = a % diff;
   ll s = diff - f;
   if(diff == 0) cout << 0 << " " << 0 << endl;
   else cout << diff << " " << min(f, s) << endl;
}

void solve1574B()
{
   int m;
   vector<int> a(3);
   for(auto& e : a) cin >> e; cin >> m;
   sort(a.begin(), a.end());
   int maxi = a[0] + a[1] + a[2] - 3;
   int r = a[0] + a[1] + 1;
   int mini = max(0, a[2] - r);
   if(m < mini || m > maxi) cout << "NO" << endl;
   else cout << "YES" << endl;
}

void solve1791A()
{
   string s = "codeforces";
   char c;
   cin >> c;
   for(int i = 0; i < s.size(); i++)
   {
      if(s[i] == c) {cout << "YES" << endl; return;}
   }
   cout << "NO" << endl;
}

void solve1791B()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   bool flag = false;
   pair<int, int> curr = make_pair(0, 0);
   for(int i = 0; i < n; i++)
   {
      if(s[i] == 'L') curr.first--;
      else if(s[i] == 'R') curr.first++;
      else if(s[i] == 'U') curr.second++;
      else curr.second--;
      
      if(curr.first == 1 && curr.second == 1) flag = true;
   }
   if(flag) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1791C()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   int l = 0, r = n - 1;
   while(l != r && s[l] != s[r])
   {
      l++, r--;
   }
   cout << max(0, r - l + 1) << endl;
}

void solve1791D()
{
   int n; string s;
   cin >> n;
   cin >> s;
   vector<int> pref(n, 0), suff(n, 0), a(26, 0), b(26, 0);
   pref[0] = 1;
   a[s[0] - 'a']++;
   suff[n - 1] = 1;
   b[s[n - 1] - 'a']++;
   for(int i = 1; i < n; i++)
   {
      if(a[s[i] - 'a'] == 0) {pref[i] = pref[i - 1] + 1; a[s[i] - 'a']++;}
      else pref[i] = pref[i - 1];
   }
   
   for(int i = n - 2; i >= 0; i--)
   {
      if(b[s[i] - 'a'] == 0) {suff[i] = suff[i + 1] + 1; b[s[i] - 'a']++;}
      else suff[i] = suff[i + 1];
   }
   
   int maxi = 0;
   for(int i = 0; i + 1 < n; i++) maxi = max(maxi, pref[i] + suff[i + 1]);
   cout << min(n, maxi) << endl;
}

void solve1791E()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   ll neg = 0, ze = 0, sum = 0, mini = 1e18;
   for(int i = 0; i < n; i++) 
   {
      cin >> a[i];
      if(a[i] == 0ll) ze++;
      else if(a[i] < 0ll) neg++;
   
      mini = min(mini, abs(a[i]));
      sum += abs(a[i]);
   }
   
   if(neg % 2 == 1)sum = sum - (2ll * mini);
   cout << sum << endl;
   
}


void solve1786C()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   ll moves = 0;
   int curr = 1;
   for(int i = 0; i < n; i++)
   {
      if(a[i] == curr) curr++;
      else if (a[i] < curr) continue;
      else
      {
         moves += a[i] - curr;
         curr++;
      }
      
   }
   cout << moves << endl;
}

void solve1786A1()
{
   int n, bob = 0, al = 1;
   cin >> n;
   n--;
   bool b = true;
   for(int i = 2; n > 0 ; i += 2)
   {
      if(b == true)
      {
         bob += min(n, i);
         n -= min(n, i);
         bob += min(n, i + 1);
         n -= min(n, i + 1);
         b = false;
      }
      else 
      {
         al += min(n, i);
         n -= min(n, i);
         al += min(n, i + 1);
         n -= min(n, i + 1);
         b = true;
      }
   }
   cout << al << " " << bob << endl;
}

void solve1786A2()
{
   int n, bb = 0, bw = 0, ab = 0,  aw = 1;
   cin >> n;
   int nblack = n / 2;
   int nwhite = (n + 1)/ 2;
   n--;
   bool bob = true;
   bool black = true;
   for(int i = 2; n > 0 ; i += 2)
   {
      if(bob == true)
      {
         
         int cantake = min(n , i);
         bb += (cantake + 1) / 2;
         bw += cantake / 2;
         n -= cantake;
         cantake = min(n , i + 1);
         bb += (cantake + 1) / 2;
         bw += cantake / 2;
         n -= cantake;
         bob = false;
      }
      else 
      {
         int cantake = min(n , i);
         aw += (cantake + 1) / 2;
         ab += cantake / 2;
         n -= cantake;
         cantake = min(n , i + 1);
         aw += (cantake + 1) / 2;
         ab += cantake / 2;
         n -= cantake;
         bob = true;
      }
   }
   cout << aw << " " << ab << " " << bw << " " << bb  << endl;
}

void solve1786B()
{
   int n, w, h;
   cin >> n >> w >> h;
   vector<pair<int, int>> cake(n), dispenser(n);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      cake[i] = make_pair(x - w, x + w);
   }
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      dispenser[i] = make_pair(x - h, x + h);
   }
   sort(cake.begin(), cake.end());
   sort(dispenser.begin(), dispenser.end());
   int l = INT_MIN, r = INT_MAX;
   for(int i = 0; i < n; i++)
   {
      l = max(l, cake[i].first - dispenser[i].first);
      r = min(r, cake[i].second - dispenser[i].second);
   }
   //cout << l << " " << r << endl;
   if(l > r) cout << "NO" << endl;
   else cout << "YES" << endl;
}

void solve1792B()
{
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   if(a == 0) {cout << 1 << endl; return;}
   if(b > c) swap(b, c);
   int moves = a + 2 * b;
   moves += min(a + 1, c - b + d);
   cout << moves << endl;
}

void solve1537B()
{
   int n, m, x, y;
   cin >> n >> m >> x >> y;
   int t = 1, l = 1, b = n, r = m;
   int f = abs(x - 1) +  abs(y - 1) + abs(x - n) + abs(y - r);
   int s = abs(x - 1) +  abs(y - m) + abs(x - n) + abs(y - 1);
   if(f >= s) cout << 1 << " " << 1 << " " << n << " " << m << endl; 
   else cout << 1 << " " << m << " " << n << " " << 1 << endl;
}

void solve535B()
{
   string s;
   cin >> s;
   int n = s.size();
   int index = ( n == 1 ? 0 : (1 << n) - 2 ) , add = 0, mul = 1;
   for(int i = n - 1; i >= 0; i--)
   {
      if(s[i] == '7') add += mul;
      mul *= 2;
   }
   index += add + 1;
   cout << index << endl;
}

void solve1535C()
{
   string s;
   cin >> s;
   ll ans = 0, max0 = 0, max1 = 0;
   for(int i = 0; i < (int)s.size(); i++)
   {
      if(s[i] == '0')
      {
         max0++;
         max1 = 0;
         ans += max0;
      }
      else if(s[i] == '1')
      {
         max1++;
         max0 = 0;
         ans += max1;
      }
      else
      {
         max0++;
         max1++;
         ans += max(max0, max1);
      }
      swap(max1, max0);
   }
   cout << ans << endl;
}

void solve1221C()
{
   int c, m, x;
   cin >> c >> m >> x;
   if(c > m) swap(c, m);
   if(c == 0) 
   {
      cout << 0 << endl;
      return;
   }
   
   if(x >= c) cout << c << endl;
   else
   {
      if(2 * (c - x) <= m - x) cout << c << endl;
      else cout << x + (c - x + m - x) / 3 << endl;
   }
}

void solve1371B()
{
   ll n, r, ans = 0;
   cin >> n >> r;
   if(n > r) ans = (r * 1ll * (r + 1)) / 2;
   else ans = ((n * 1ll * (n + 1)) / 2) - n + 1ll;
   cout << ans << endl;
}

void solve1512C()
{
   int z, o;
   cin >> z >> o;
   int n = z + o;
   string s;
   cin >> s;
   if(z % 2 == 1 && o % 2 == 1)
   {
      cout << -1 << endl;
      return;
   }
   bool f = true;
   for(int i = 0; i < n; i++)
   {
      char a = s[i];
      char b = s[n - i - 1];
      if(a == b) continue;
      if(a != '?' && b != '?') f = false;
      else
      {
         if(a == '?')
         {
            swap(s[i], s[n - i - 1]);
            s[n - i - 1] = s[i];
         }
      }
   }
   for(int i = 0; i < n; i++)
   {
      if(s[i] == '0') z--;
      else if(s[i] == '1') o--;
   }
   //cout << z << " " << o << endl;
   //cout << s << " " << z << " " << o << endl;
   int l = 0, r = n - 1;
   while(l < r)
   {
      if(s[l] != '?') 
      {
         l++;
         r--;
      }
      else
      {
         if(z >= o)
         {
            s[l] = s[r] = '0';
            z -= 2;
            l++;
            r--;
            //cout << "zero" << endl;
         }
         else
         {
            s[l] = s[r] = '1';
            o -= 2;
            l++;
            r--;
            //cout << "one" << endl;
         }
      }
   }
   if(l == r && s[l] == '?')
   {
      if(o == 1) {s[l] = '1'; o--;}
      else if (z == 1) {s[l] = '0'; z--;}
      else f = false;
   }
   if(z < 0 || o < 0 || f == false) 
   {
      cout << -1 << endl;
      return;
   }
   else cout << s << endl;
}
void solve80B()
{
   string s;
   cin >> s;
   int h = 0, m = 0; 
   double ans1 = 0, ans2 = 0;
   for(int i = 0; i < 2; i++) h = h * 10 + (s[i] - '0');
   for(int i = 3; i < 5; i++) m = m * 10 + (s[i] - '0');
   h = h % 12;
   ans2 = m * 6;
   ans1 = h * 30 + m * 0.5;
   cout << fixed << setprecision(1) << ans1 << " " << ans2 << endl;
}

void solve1311B()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n), b(m);
   set<int> st;
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < m; i++) cin >> b[i];
   sort(b.begin(), b.end());
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j + 1 < n - i; j++)
      {
         if(a[j] > a[j + 1])
         {
            swap(a[j], a[j + 1]);
            st.insert(j + 1);
         }
      }
   }
   bool f = true;
   
   for(auto elem : st)
   {
      //cout << elem << " ";
      if(binary_search(b.begin(), b.end(), elem) == false)
      {
         f = false;
         break;
      }
   }
   if(f == false) cout << "NO" << endl;
   else cout << "YES" << endl;
}

void solve1792C()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), b(n + 1);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      b[a[i]] = i;
   }
   
   int l = (n + 1) / 2, r = (n + 2) / 2;
   //cout << l << " " << r << endl;
   int ans = 0;
   while(l > 0)
   {
      int indx1 = b[l];
      int indx2 = b[r];
      if(indx1 > indx2) 
      { 
         ans = l; 
         break;
         
      }
      int l2 = l - 1;
      int r2 = r + 1;
      if(l2 == 0)
      {
         ans = 0; 
         break;
      }
      int indx3 = b[l2];
      int indx4 = b[r2];
      if(indx1 > indx3 && indx1 < indx4 && indx2 > indx3 && indx2 < indx4)
      {
         l = l2;
         r = r2;
      }
      else 
      {
         ans = l - 1;
         break;
      }
   }
   cout << ans << endl;
}

void solve1446A()
{
   ll n, w;
   cin >> n >> w;
   vector<pair<ll,ll>> a(n);
   for(ll i = 0; i < n; i++)
   {
      ll x;
      cin >> x;
      a[i] = make_pair(x, i);
   }
   
   sort(a.begin(), a.end());
   ll sum = 0;
   vector<ll> ans;
   for(int i = n - 1; i >= 0; i--)
   {
      if(sum + a[i].first <= w)
      {
         ans.push_back(a[i].second);
         sum += a[i].first;
      }
   }
   if(sum >= (w + 1) / 2)
   {
      sort(ans.begin(), ans.end());
      cout << ans.size() << endl;
      for(auto elem : ans) cout << elem + 1 << " "; cout << endl;
   }
   else cout << -1 << endl;
}

void solve448B()
{
   string s, t;
   cin >> s >> t;
   vector<vector<int>> have(26), need(26);
   
   for(int i = 0; i < s.size(); i++) have[s[i] - 'a'].push_back(i);
   for(int i = 0; i < t.size(); i++) need[t[i] - 'a'].push_back(i);
   
   bool automaton = false, aray = false;
   
   for(int i = 0; i < 26; i++)
   {
      if(have[i].size() < need[i].size())
      {
         cout << "need tree" << endl;
         return;
      }
      else if(have[i].size() > need[i].size()) automaton = true;
   }
   int ss = s.size();
   int ts = t.size();
   int j = 0;
   for(int i = 0; i <= ss - 1; i++)
   {
      if(s[i] == t[j]) j++;
   }
   if(j == ts) aray = false;
   else aray = true;
   if(aray && automaton) cout << "both" << endl;
   else if(aray) cout << "array" << endl;
   else cout << "automaton" << endl;
}

void solve989B()
{
   int n, k; 
   string s;
   cin >> n >> k >> s;
   bool flag = true;
   for(int i = 0; i <= n - 1; i++)
   {
      int j = i;
      int cnt1 = 0, cnt2 = 0, cnt3 = 0;
      while(j + k < n)
      {
         if(s[j] == '.' || s[j + k] == '.')
         {
            if(s[j + k] == s[j])
            {
               s[j] = '1';
               s[j + k] = '0';
            }
            else
            {
               if(s[j] == '.') s[j] = ((s[j + k] == '1') ? '0' : '1');
               else s[j + k] = ((s[j] == '1') ? '0' : '1');
            }
            flag = false;
         }
         else if (s[j] != s[j + k]) flag = false;
         j += k;
      }
      if(s[i] == '.') s[i] = '0';
   }
   if(flag == true) cout << "NO" << endl;
   else cout << s << endl;
}

void solve1799B()
{
   int n;
   cin >> n;
   vector<pair<int, int>> a(n);
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a[i] = make_pair(x, i);
   }
   
   sort(a.begin(), a.end());
   if(a[0].first == 1 && a.back().first != 1)
   {
      cout << -1 << endl;
      return;
   }
   vector<pair<int, int>> ans;
   bool f = true;
   while(f)
   {
      //cout << "while " << endl;
      int curr = a[0].first;
      for(int i = 1; i < n; i++)
      {
         while(a[i].first > a[0].first)
         {
            a[i].first = (a[i].first + a[0].first - 1) / a[0].first;
            ans.push_back(make_pair(a[i].second + 1, a[0].second + 1));
         }
         
      }
      sort(a.begin(), a.end());
      //for(auto elem : a) cout << elem.first << " "; cout << endl;
      if(a[0].first == a.back().first) f = false;
   }
   
   cout << ans.size() << endl;
   for(auto elem : ans) cout << elem.first << " " << elem.second << endl;
}

void solve1799A()
{
   int n, m;
   cin >> n >> m;
   vector<int> a;
   vector<bool> flags(n + m + 1, false); 
   vector<int> times(n + 1, -1);
   for(int i = 1; i <= n; i++) 
   {
      a.push_back(i); 
      flags[i] = true;
   }
   int back = n - 1;
   for(int i = 1; i <= m; i++)
   {
      int x;
      cin >> x;
      if(flags[x] == false)
      {
         int b = a[back];
         back--;
         if(back >= 0) flags[b] = false;
         if(b >= 0 && b <= n && times[b] == -1) times[b] = i;
         a.push_back(x);
         flags[x] = true;
      }
   }
   
   for(int i = 1; i <= n; i++) cout << times[i] << " "; cout << endl;
}

void solve1451C()
{
   int n, k;
   cin >> n >> k;
   string a, b;
   cin >> a >> b;
   vector<int> achars(26, 0), bchars(26, 0);
   for(int i = 0; i < n; i++)
   {
      achars[a[i] - 'a']++;
      bchars[b[i] - 'a']++;
   }
   
   for(int i = 0; i + 1 < 26; i++)
   {
      //cout << char(i + 'a') << endl;
      if(achars[i] < bchars[i])
      {
         cout << "NO" << endl;
         return;
      }
      else
      {
         int diff = achars[i] - bchars[i];
         if(diff % k != 0)
         {
            cout << "NO" << endl;
            return;
         }
         else 
         {
            achars[i + 1] += diff;
         }
      }
   }
   //for(auto elem : achars) cout << elem << " "; cout << endl;
   //for(auto elem : bchars) cout << elem << " "; cout << endl;
   if(achars[25] != bchars[25]) {cout << "NO" << endl; return;}
   cout << "YES" << endl;
}

void solve1748B()
{
   int n;
   string s;
   cin >> n >> s;
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      vector<int> a(10, 0);
      int d = 0;
      int j = i;
      int maxi = 0;
      while(j >= 0 && i - j + 1 <= 100)
      {
         a[s[j] - '0']++;
         maxi = max(maxi, a[s[j] - '0']);
         if(a[s[j] - '0'] == 1) d++;
         if(maxi <= d) ans++;
         j--;
      }
   }
   cout << ans << endl;
}

void solve1691C()
{
   int n, k;
   string s;
   cin >> n >> k >> s;
   int sum = 0;
   vector<int> a;
   for(int i = 0; i < n; i++) 
   {
      if(s[i] == '1') a.push_back(i);
      if(i + 1 < n) sum += (s[i] - '0') * 10 + (s[i + 1] - '0');
   }
   
   if(a.size() == 0 || a.size() == n || k == 0) cout << sum << endl;
   else if(a.size() == 1)
   {
      int idx = a[0];
      int need1 = n - 1 - idx;
      int need2 = idx;
      if(k >= need1) cout << 1 << endl;
      else if(k >= need2) cout << 10 << endl;
      else cout << 11 << endl;
   }
   else
   {
      int idx1 = a[0];
      int idx2 = a.back();
      int need2 = n - 1 - idx2;
      int need1 = idx1;
      if(k >= need2 && need2 > 0)
      {
         k -= need2;
         sum -= 10;
      }
      if(k >= need1 && need1 > 0)
      {
         sum -= 1;
      }
      cout << sum << endl;
   }
}

void solve1800D()
{
   int n; string s;
   cin >> n >> s;
   int ans = n - 1;
   for(int i = n - 1; i >= 2; i--)
   {
      if(s[i] == s[i - 2]) ans--;
   }
   
   cout << ans << endl;
}

void solve1800A()
{
   int n; string s, t, u;
   cin >> n >> s;
   for(int i = 0; i < n; i++) t.push_back(tolower(s[i]));
   //cout << t << endl;
   vector<int> a(26, 0);
   for(int i = 0; i < n; i++)
   {
      char curr = t[i];
      u.push_back(curr);
      int j = i;
      while(j < n && t[j] == curr) j++;
      i = j - 1;
   }
   //cout << u << endl;
   bool f = (u.size() == 4) && (u[0] == 'm') && (u[1] == 'e') && (u[2] =='o') && (u[3] == 'w');
   if(f == false) cout << "NO" << endl;
   else cout << "YES" << endl;
}

void solve1800B()
{
   int n, k; string s;
   cin >> n >> k >> s;
   vector<int> upper(26, 0), lower(26, 0);
   
   for(int i = 0; i < n; i++)
   {
      if(isupper(s[i])) upper[s[i] - 'A']++;
      else lower[s[i] - 'a']++;
   }
   for(int i = 0; i < 26; i++)
   {
      if(upper[i] == lower[i]) continue;
      if(upper[i] < lower[i]) swap(upper[i], lower[i]);
      int diff = abs(upper[i] - lower[i]);
      int need = diff / 2;
      if(k >= need)
      {
         lower[i] += need;
         upper[i] -= need;
         k -= need;
      }
      else
      {
         lower[i] += k;
         upper[i] -= k;
         k = 0;
      }
   }
   int ans = 0;
   for(int i = 0; i < 26; i++) ans += min(upper[i], lower[i]);
   cout << ans << endl;
}

void solve1800C1()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   priority_queue<ll> pq;
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(a[i] != 0) 
      {
         //cout << a[i] << " is pushed" << endl;
         pq.push(a[i]);
      }
      else
      {
         if(pq.size() > 0)
         {
            ll x = pq.top();
            pq.pop();
            //cout << x << " is added " << endl; 
            ans += x;
         }
      }
   }
   cout << ans << endl;
}

void solve1800C2()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   priority_queue<ll> pq;
   ll ans = 0;
   for(int i = 0; i < n; i++)
   {
      if(a[i] != 0) 
      {
         //cout << a[i] << " is pushed" << endl;
         pq.push(a[i]);
      }
      else
      {
         if(pq.size() > 0)
         {
            ll x = pq.top();
            pq.pop();
            //cout << x << " is added " << endl; 
            ans += x;
         }
      }
   }
   cout << ans << endl;
}

void solve1794C()
{
   int n;
   cin >> n;
   vector<int> a(n + 1), b(n + 1), ans(n + 1, 1);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      b[i] = i;
   }
   
   for(int k = 1; k <= n; k++)
   {
      int l = 1, r = k, mark = -1;
      while(l <= r)
      {
         int mid = (l + r) / 2;
         //cout << " k " << k << " l " << l << " r " << r << " mid " << mid << endl;
         if(a[k - mid + 1] < b[mid])
         {
            r = mid - 1;
         }
         else
         {
            l = mid + 1;
            mark = mid;
         }
      }
      ans[k] = ( (mark == -1) ? 1 : mark );
   }
   for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}
void solve1624D()
{
   int n, k; string s;
   cin >> n >> k >> s;
   if(2 * k > n) 
   {
      cout << 1 << endl;
      return;
   }
   vector<int> a(26, 0), b(k, 0);
   for(int i = 0; i < n; i++) a[s[i] - 'a']++;
   int givenpairs = 0, givensolo = 0;
   for(int i = 0; i < 26; i++) 
   {
      givenpairs += a[i] / 2;
      givensolo += a[i] % 2;
   }
   int row = 0, sz = n / k;
   while(givenpairs > 0)
   {
      if(b[row] + 2 <= sz)b[row] += 2;
      else givensolo += 2;
      givenpairs--;
      row = (row + 1) % k;
   }
   vector<bool> flag(k, false);
   while(givensolo > 0 && flag[row] == false)
   {
      if(b[row] + 1 <= sz)b[row]++;
      flag[row] = true;
      givensolo--;
      row = (row + 1) % k;
   }
   
   int ans = INT_MAX;
   for(int i = 0; i < k; i++) ans = min(ans, b[i]);
   cout << ans << endl;
}

void solve1788C()
{
   ll n;
   cin >> n;
   if(n % 2 == 0) 
   {
      cout << "NO" << endl;
      return;
   }
   
   ll mid = 2 * n + 1, l = 1;
   cout << "YES" << endl;
   for(int i = mid - n / 2; i <= mid + n / 2; i += 2)
   {
      cout << l << " " << i - l << endl;
      l++;
   }
   for(int i = mid - (n / 2) + 1; i <= mid + n / 2; i += 2)
   {
      cout << l << " " << i - l << endl;
      l++;
   }
}

void solve1788B()
{
   int n, n1, curr = 0, sum = 0;
   cin >> n;
   n1 = n;
   vector<int> a(10, 0);
   while(n > 0)
   {
      a[curr] = n % 10;
      sum += n % 10;
      n /= 10;
      curr++;
   }
   int take = (sum + 1)/ 2;
   string s;
   for(int i = 9; i >= 0; i--)
   {
      if(take >= a[i])
      {
         s.push_back(a[i] + '0');
         take -= a[i];
      }
      else
      {
         s.push_back(take + '0');
         take = 0;
      }
   }
   int ff = stoi(s);
   int ss = n1 - ff;
   cout << ff << " " << ss << endl;
}

void solve1778B()
{
   ll n, m, d;
   cin >> n >> m >> d;
   vector<int> p(n + 1), a(m + 1);
   for(int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      p[x] = i;
   }
   
   for(int i = 1; i <= m; i++)
   {
      int x;
      cin >> x;
      a[i] = p[x];
   }
   //for(auto elem : p) cout << elem << " "; cout << endl;
   //for(auto elem : a) cout << elem << " "; cout << endl;
   ll ans = INT_MAX;
   for(int i = 1; i + 1 <= m; i++)
   {
      ll op2 = a[i + 1] - a[i];
      if(op2 > d || op2 < 0)
      {
         ans = 0;
         break;
      }
      ll op1 = a[i] - 1 + n - a[i + 1];
      if(op1 + op2 >= d + 1) op1 = d + 1 - op2;
      else op1 = INT_MAX;
      //cout << op1 << " " << op2 << endl;
      ans = min(ans, min(op1, op2));
   }
   cout << ans << endl;
}

void solve1108D()
{
   int n, ans = 0; string s;
   cin >> n >> s;
   vector<char> a = {'R', 'G', 'B'};
   for(int i = 0; i < n; i++)
   {
      char c = s[i];
      int j = i;
      int len = 0;
      while(j < n && s[j] == c)
      {
         len++;
         if(len % 2 == 0)
         {
            ans++;
            if(j - 1 >= 0 && j + 1 < n)
            {
               for(auto elem : a)
               {
                  if(elem != s[j - 1] && elem != s[j + 1]) s[j] = elem;
               }
            }
            else if(j - 1 >= 0)
            {
               for(auto elem : a)
               {
                  if(elem != s[j - 1]) s[j] = elem;
               }
            }
         }
         j++;
      }
      i = j - 1;
   }
   cout << ans << endl << s << endl;
}

void solve1443B()
{
   ll n, a, b, ans = (ll)1e15; string s;
   cin >> a >> b >> s;
   int sz = s.size();
   vector<pair<int, int>> segs;
   for(int i = 0; i < sz; i++)
   {
      int x = -1, y = -1;
      if(s[i] == '1')
      {
         x = i;
         int j = i;
         while(j < sz && s[j] == '1') j++;
         y = j - 1;
         i = j - 1;
      }
      if(x != -1 && y != -1) segs.push_back(make_pair(x, y));
     
   }
   
   //for(auto elem : segs) cout << "( "<<elem.first << " " << elem.second << " )"; cout << endl;
   n = segs.size();
   if(n <= 1) {cout << n * a << endl; return;}
   
   vector<ll> open(n - 1);
   for(ll i = 0; i + 1 < n; i++) open[i] = abs(segs[i].second - segs[i + 1].first) - 1;
   sort(open.begin(), open.end());
   //for(auto elem : open) cout << elem << " "; cout << endl;
   vector<ll> pref(n, 0);
   for(ll i = 0; i < open.size(); i++) pref[i + 1] = pref[i] + open[i] * 1ll * b;
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   
   for(int seg = n; seg >= 1; seg--)
   {
      int op = n - seg;
      ll choice = seg * 1ll * a + pref[op];
      //cout << choice << endl;
      ans = min(ans, choice);
   }
   cout << ans << endl;
}

void solve1582C()
{
   int n; string s;
   cin >> n >> s;
   int ans = INT_MAX;
   for(char c = 'a'; c <= 'z'; c++)
   {
      int cnt = 0, l = 0, r = n - 1;
      bool f = true;
      while(l < r)
      {
         if(s[l] == s[r])
         {
            l++; 
            r--;
         }
         else
         {
            if(s[l] == c)
            {
               cnt++;
               l++;
            }
            else if(s[r] == c)
            {
               cnt++;
               r--;
            }
            else
            {
               f = false;
               break;
            }
         }
      }
      //cout << (char) c << " " << cnt << " " << f << endl;
      if(f == true) ans = min(ans, cnt);
   }
   
   if(ans == INT_MAX) cout << -1 << endl;
   else cout << ans << endl;
}

void solve1802B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   int i = 0, cnt = 0, bld = 0, single = 0, dbl = 0, emp = 0;
   while(i < n && a[i] == 2) i++;
   for(; i < n; i++)
   {
      if(a[i] == 1)
      {
         single++;
         if(emp == 0) bld++;
         else emp--;
      }
      else if(a[i] == 2)
      {
         cnt = single;
         if(cnt % 2 == 0) 
         {
            single = 2;
            dbl += cnt / 2 - 1;
            emp = bld - dbl - single;
         }
         else
         {
            dbl += cnt / 2;
            single = cnt % 2;
            emp = bld - dbl - single;
         }
      }
   }
   cout << bld << endl;
}

void solve1802A()
{
   int n;
   cin >> n;
   int pos = 0, neg = 0;
   for(int i = 1; i <= n; i++) 
   {
      int x;
      cin >> x;
      if(x < 0) neg++;
      else pos++;
   }
   int cnt = 1;
   for(int j = 1; j <= pos; j++)
   {
      cout << cnt << " ";
      cnt++;
   }
   cnt -= 2;
   for(int j = 1; j <= neg; j++)
   {
      cout << cnt << " ";
      cnt--;
   }
   cout << endl;
   cnt = 1;
   int j;
   for(j = 1; j <= 2 * neg; j++)
   {
      if(j % 2 == 1)cout << 1 << " ";
      else cout << 0 << " ";
   }
   for(; j <= n; j++)
   {
      cout << cnt << " ";
      cnt++;
   }
   cout << endl;
}

void solve1553B()
{
   string s, t;
   cin >> s >> t;
   int sz = s.size();
   int tz = t.size();
   bool flag = false;
   for(int i = 0; i < sz; i++)
   {
      if(s[i] != t[0]) continue;
      for(int j = tz; j >= 0; j--)
      {
         string f;
         int bak = tz - j;
         int k, p;
         if(i + j - 1 < sz)
         {
            for(k = i, p = 1; p <= j; k++, p++) f.push_back(s[k]);
         }
         else continue;
         k -= 2;
         if(k + 1 - bak >= 0)
         {
            for(int p = 1; p <= bak; p++, k--) f.push_back(s[k]);
         }
         else continue;
         //cout << f << endl;
         if(f == t)
         {
            flag = true;
            break;
         }
      }
      if(flag == true) break;
   }
   if(flag) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1800E2()
{
   int n, k; string s, t;
   cin >> n >> k >> s >> t;
   vector<int> a(26, 0);
   if(s == t) 
   {
      cout << "YES" << endl;
      return;
   }
   for(int i = 0; i < n; i++) a[s[i] - 'a']++;
   for(int i = 0; i < n; i++) a[t[i] - 'a']--;
   for(int i = 0; i < 26; i++)
   {
      if(a[i] != 0)
      {
         cout << "NO" << endl;
         return;
      }
   }
   for(int i = 0; i < n; i++)
   {
      if(s[i] != t[i] && i - k < 0 && i + k >= n)
      {
         cout << "NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
}

void solve1178B()
{
   string s, t;
   cin >> s;
   int n = (int)s.size();
   bool flag = false;
   for(int i = 0; i < n; i++)
   {
      if(s[i] == 'o')
      {
         if(flag == false) continue;
         else t.push_back('o');
      }
      else if(s[i] == 'v')
      {
         if( (i >= 1 && s[i - 1] == 'v') || (i + 1 < n && s[i + 1] == 'v') ) 
         {
            flag = true;
            t.push_back('v');
         }
      }
   }
   vector<pair<int, int>> segs;
   n = t.size();
   for(int i = 0; i < n; i++)
   {
      int x = -1, y = -1;
      if(t[i] == 'v')
      {
         int j = i;
         x = j;
         while(j < n && t[j] == 'v') j++;
         y = j - 1;
         segs.push_back(make_pair(x, y));
         i = j - 1;
      }
   }
   //cout << t << endl;
   //for(auto elem : segs) cout << "( "<<elem.first << " " << elem.second <<" )"; cout << endl;
   ll total = 0;
   for(auto elem : segs) total += elem.second - elem.first;
   ll curr = 0, ans = 0;
   for(int i = 0; i + 1 < (int)segs.size(); i++)
   {
      curr += segs[i].second - segs[i].first;
      for(int j = segs[i].second + 1; j < segs[i + 1].first; j++)
      {
         ans = ans + 1ll * curr * (total - curr);
      }
   }
   cout << ans << endl;
}

void solve1194C()
{
   string s, t, p;
   cin >> s >> t >> p;
   int sz = (int) s.size(), tz = (int)t.size(), pz = (int)p.size();
   vector<int> a(26, 0);
   int i = 0, j = 0;
   bool flag = true;
   while(i < sz)
   {
      if(s[i] != t[j])
      {
         while(j < tz && s[i] != t[j])
         {
            a[t[j] - 'a']++;
            j++;
         }
         if(j == tz) 
         {
            flag = false;
            break;
         }
      }
      else 
      {
         i++;
         j++;
      }
   }
   while(j < tz) {a[t[j] - 'a']++; j++;}
   for(int k = 0; k < pz; k++)
   {
      if(a[p[k] - 'a'] > 0) a[p[k] - 'a']--;
   }
   for(int k = 0; k < 26; k++)
   {
      if(a[k] > 0) flag = false;
   }
   if(flag == false) cout << "NO" << endl;
   else cout << "YES" << endl;
}

void solve66A()
{
   string s;
   cin >> s;
   string l = "9223372036854775807";
   int n = (int)s.size();
   bool f = false;
   if(n == 19)
   {
      for(int i = 0; i < 19; i++)
      {
         if(s[i] == l[i]) {continue;}
         else if(s[i] > l[i]) {f = true; break;}
         else {f = false; break;}
      }
   }
   if(n > 19 || f == true) {cout << "BigInteger" << endl; return;}
   
   ll num = 0, mul = 1;
   for(int i = n - 1; i >= 0; i--)
   {
      num += (s[i] - '0') * mul;
      mul *= 10;
   }
   //cout << num << endl;
   int leftmost = 0;
   while(num > 0)
   {
      num = num >> 1;
      leftmost++;
   }
   if(leftmost <= 7) {cout << "byte" << endl; return;}
   if(leftmost <= 15) {cout << "short" << endl; return;}
   if(leftmost <= 31) {cout << "int" << endl; return;}
   if(leftmost <= 63) {cout << "long" << endl; return;}
}

void solve1421C()
{
   string s;
   cin >> s;
   int n = (int)s.size();
   vector<pair<char, int>> a;
   a.push_back(make_pair('R', n - 1));
   n++;
   a.push_back(make_pair('L', 2));
   n++;
   a.push_back(make_pair('R', 2));
   n = n + n - 2;
   a.push_back(make_pair('R', n - 1));
   n++;
   cout << 4 << endl;
   for(auto elem : a) cout << elem.first << " " << elem.second << endl;
}

void solve1804C()
{
   ll n, x, p;
   cin >> n >> x >> p;
   ll need = (n - x) % n;
   bool f = false;
   for(ll i = 1; i <= min(p, 2 * n); i++)
   {
      ll force = i;
      ll go = (force * 1ll * (force + 1)) / 2;
      ll actual = go % n;
      //cout <<go << " " <<actual << endl;
      if(actual == need) f = true;
   }
   if(f) cout << "Yes" << endl;
   else cout << "No" << endl;
}

void solve1806B()
{
   int n;
   cin >> n;
   vector<int> a(n), positives;
   int cnt0 = 0, cntpos = 0;
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      if(a[i] == 0) cnt0++;
      else {cntpos++; positives.push_back(a[i]);}
   }
   if(cntpos >= cnt0 - 1) {cout << 0 << endl; return;}
   int sz = positives.size();
   if(sz == 0) {cout << 1 << endl; return;}
   sort(positives.begin(), positives.end());
   reverse(positives.begin(), positives.end());
   if(positives[0] > 1) cout << 1 << endl;
   else cout << 2 << endl;
}

void solve1806A()
{
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   int ver = d - b;
   a += ver;
   if(a < c || d < b) cout << -1 << endl;
   else cout << ver + abs(c - a) << endl;
}

void solve525B()
{
   string s; int n;
   cin >> s >> n;
   vector<int> a((int)s.size(), 0);
   for(int i = 0; i < n; i++) 
   {
      int x;
      cin >> x;
      a[x - 1]++;
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   int l = 0, r = (int)s.size() - 1, add = 0;
   while(l <= r)
   {
      a[l] += add;
      //cout << l << " " << a[l] << endl;
      if(a[l] % 2 == 1) 
      {
         //cout << "swapping " << s[l] << " " << s[r] << endl;
         swap(s[l], s[r]);
      }
      add = 0;
      add += a[l];
      l++;
      r--;
   }
   cout << s << endl;
}

void solve1807D()
{
   ll n, q;
   cin >> n >> q;
   vector<ll> a(n + 1), pref(n + 1, 0), suff(n + 2, 0);
   for(int i = 1; i <= n; i++)
   {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
   }
   ll total = pref[n];
   for(ll i = n; i >= 1; i--) suff[i] = suff[i + 1] + a[i];
   //for(auto elem : pref) cout << elem << " "; cout << endl;
   //for(auto elem : suff) cout << elem << " "; cout << endl;
   while(q--)
   {
      int l, r, k;
      cin >> l >> r >> k;
      ll cnt = r - l + 1;
      cnt = cnt * 1ll * k;
      total = suff[r + 1] + pref[l - 1] + cnt;
      if(total % 2 == 1) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
   
}

void solve1807B()
{
   int n;
   cin >> n;
   ll odds = 0, evens = 0;
   for(int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(x % 2 == 1) odds += x;
      else evens += x;
   }
   if(evens > odds) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void solve1807C()
{
   int n; string s;
   cin >> n >> s;
   vector<vector<int>> a(26);
   for(int i = 0; i < n; i++)a[s[i] - 'a'].push_back(i);
   for(int i = 0; i < 26; i++)
   {
      bool odd = false, even = false;
      for(auto elem : a[i])
      {
         if(elem % 2 == 1) odd = true;
         else even = true;
      }
      if(odd && even)
      {
         cout << "NO" << endl;
         return;
      }
   }
   cout << "YES" << endl;
}

void solve1807A()
{
   int a, b, c;
   cin >> a >> b >> c;
   if(a + b == c) cout << '+' << endl;
   else if(a - b == c) cout << '-' << endl;
}

void solve1807G1()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   if(a[0] > 1) {cout << "NO" << endl; return;}
   ll curr = 1;
   for(int i = 1; i < n; i++)
   {
      if(curr < a[i])
      {
         cout << "NO" << endl;
         return;
      }
      curr += a[i];
   }
   
   cout << "YES" << endl;
}

void solve1807G2()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   if(a[0] > 1) {cout << "NO" << endl; return;}
   ll curr = 1;
   for(int i = 1; i < n; i++)
   {
      if(curr < a[i])
      {
         cout << "NO" << endl;
         return;
      }
      curr += a[i];
   }
   
   cout << "YES" << endl;
}

void solve1807E()
{
   int n;
   cin >> n;
   vector<ll> a(n + 1);
   for(ll i = 1; i <= n; i++) cin >> a[i];
   int l = 1, r = n;
   while(l < r)
   {
      int mid = (l + r) / 2;
      cout << "? " << mid - l + 1 << " ";
      for(int i = l; i <= mid; i++) cout << i << " "; cout << endl;
      int m;
      cin >> m;
      int sum = 0;
      for(int i = l; i <= mid; i++) sum += a[i];
      if(sum == m) l = mid + 1;
      else r = mid;
   }
   
   cout << "! " << l << endl;
}

void solve697B()
{
   string s, t((int)1e5 + 30, '0');
   cin >> s;
   int move = 0, i = 0, n = (int) s.size(), right = -1;
   while(i < n && s[i] != 'e') 
   {
      if(i > 1 && s[i] > '0') right = i;
      t[i] = s[i];
      i++;
   }
   if(right == -1 && s[0] == '0') {cout << 0 << endl; return;}
   i++;
   for(; i < n; i++) move = move * 10 + (s[i] - '0');
   //cout << move << endl;
   i = 1;
   while(move > 0)
   {
      swap(t[i], t[i + 1]);
      i++;
      move--;
   }
   //cout << t << endl << t[i] << endl;
   i++;
   //cout << right << " " << i << endl;
   t = t.substr(0, max(i, right + 1));
   //cout << t << endl;
   i = 0;
   while(i < t.size() && t[i] == '0') i++;
   if(i < t.size() && t[i] == '.') t = t.substr(i - 1);
   else t = t.substr(i);
   if(t.back() == '.') t.pop_back();
   cout << t << endl;
   //cout << t << endl;
}

void solve954B()
{
   int n; string s;
   cin >> n >> s;
   int maxi = 1;
   for(int i = 1; i <= n ; i++)
   {
      int j = 0, k = j + i, f = j + i;
      while(j < f && k < n && s[j] == s[k])
      {
         //cout << j << " inside " << k << endl;
         k++;
         j++;
      }
      //cout << j << " outside " << k << endl;
      if(j == i) maxi = max(maxi, i);
   }
   //cout << maxi << endl;
   cout << n - maxi + 1 << endl;
}

void solve1648A()
{
   //each index has n + (n - i - 1) * i counts of segment
   int n, m;
   cin >> n >> m;
   vector<vector<int>> rows(1e5 + 30), cols(1e5 + 30);
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < m; j++)
      {
         int x;
         cin >> x;
         rows[x].push_back(i);
         cols[x].push_back(j);
      }
   }
   for(int i = 0; i <(int) rows.size(); i++) sort(rows[i].begin(), rows[i].end());
   for(int i = 0; i <(int) cols.size(); i++) sort(cols[i].begin(), cols[i].end());
   /*for(int i = 0; i < rows.size(); i++)
   {
      cout << i << " rows ";
      for(int j = 0; j < (int)rows[i].size(); j++) cout << rows[i][j] << " "; cout << endl;
   }
   for(int i = 0; i < cols.size(); i++)
   {
      cout << i << " cols ";
      for(int j = 0; j < (int)cols[i].size(); j++) cout << cols[i][j] << " "; cout << endl;
   }*/
   ll sum = 0;
   for(int i = 0; i < (int)rows.size(); i++)
   {
      n = rows[i].size();
      for(int j = 0; j < n; j++)
      {
         sum += (2 * j - n + 1) * 1ll * rows[i][j];  
      }
   }
   for(int i = 0; i < (int)cols.size(); i++)
   {
      n = cols[i].size();
      for(int j = 0; j < n; j++)
      {
         sum += (2 * j - n + 1) * 1ll * cols[i][j];  
      }
   }
   cout << sum << endl;
}

void solve1316B()
{
   int n; string s;
   cin >> n >> s;
   string t(50002, 'z');
   int mini = INT_MAX;
   bool swp = true;
   for(int k = n; k >= 1; k--)
   {
      string p = s.substr(k - 1);
      string q = s.substr(0, k - 1);
      if(swp == true)
      {
         reverse(q.begin(), q.end());
         swp = false;
      }
      else swp = true;
      p += q;
      if(p <= t) 
      {
         if(p == t) mini = min(mini, k);
         else mini = k;
         t = p;
      }
   }
   cout << t << endl << mini << endl;
}

void solve1251B()
{
   ll n;
   cin >> n;
   ll cnt0 = 0, cnt1 = 0, ans = 0;
   vector<int> a(n, 0);
   for(int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      for(int j = 0; j < s.size(); j++)
      {
         a[i] = s.size();
         if(s[j] == '0') cnt0++;
         else cnt1++;
      }
   }
   sort(a.begin(), a.end());
   int i = 0;
   while(cnt0 > 0)
   {
      if(cnt0 >= 2) 
      {
         int j = 0;
         while(j < n && a[j] < 2) j++;
         if(j < n) a[j] -= 2;
         else
         {
            j = 0;
            while(j < n && a[j] <= 0) j++;
            a[j]--;
            j = 0;
            while(j < n && a[j] <= 0) j++;
            a[j]--;
            
         }
         cnt0 -= 2;
      }
      else if(cnt0 == 1)
      {
         int j = 0;
         while(j < n && a[j] % 2 == 0) j++;
         if(j < n) a[j]--;
         cnt0--;
      }
   }
   //for(auto elem : a) cout << elem << " "; cout << endl;
   while(cnt1 > 0)
   {
      if(cnt1 >= 2) 
      {
         int j = 0;
         while(j < n && a[j] < 2) j++;
         if(j < n) a[j] -= 2;
         else
         {
            j = 0;
            while(j < n && a[j] <= 0) j++;
            a[j]--;
            j = 0;
            while(j < n && a[j] <= 0) j++;
            a[j]--;
         }
         cnt1 -= 2;
      }
      else if(cnt1 == 1)
      {
         int j = 0;
         while(j < n && a[j] % 2 == 0) j++;
         if(j < n) a[j]--;
         cnt1--;
      }
   }
   for(int i = 0; i < n; i++) if(a[i] == 0) ans++;
   cout << ans << endl;
}

void solve1808B()
{
   ll n, m, sum = 0;
   cin >> n >> m;
   vector<vector<ll>> a(n, vector<ll> (m));
   for(ll i = 0; i < n; i++)
   {
      for(ll j = 0; j < m; j++) cin >> a[i][j];
   }
   
   for(ll col = 0; col < m; col++)
   {
      vector<ll> sorted(n);
      for(ll row = 0; row < n; row++)
      {
         sorted[row] = a[row][col];
      }
      sort(sorted.begin(), sorted.end());
      reverse(sorted.begin(), sorted.end());
      for(ll i = 0; i < n; i++)
      {
         ll curr = sorted[i];
         ll add = curr * 1ll * (n - 1 - i);
         ll sub = curr * 1ll * i;
         sum += add - sub;
      }
   }
   cout << sum << endl;
}

void solve1808A()
{
   int l, r, ans, maxi = INT_MIN;
   cin >> l >> r;
   for(int i = l; i <= min(l + 100, r); i++)
   {
      string s = to_string(i);
      sort(s.begin(), s.end());
      int diff = (s.back() - '0') - (s.front() - '0');
      if(diff > maxi) 
      {
         maxi = diff;
         ans = i;
      }
   }
   cout << ans << endl;
}

void solve1624C()
{
   int n, x;
   cin >> n;
   vector<vector<int>> a(n);
   for(int i = 0; i < n; i++)
   {
      cin >> x;
      while(x > 0)
      {
         if(x <= n) a[i].push_back(x);
         x /= 2;
      }
      //reverse(a[i].begin(), a[i].end());
   }
   sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y)
   {
      if((int)x.size() < (int)y.size()) return true;
      else return false;
   });
   vector<bool> flags(n + 1, false);
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < (int)a[i].size(); j++)
      {
         if(flags[a[i][j]] == false) 
         {
            //cout << a[i][j] << endl;
            flags[a[i][j]] = true;
            break;
         }
      }
   }
   bool ans = true;
   for(int i = 1; i <= n; i++) ans &= flags[i];
   if(ans) cout << "YES" <<endl;
   else cout << "NO" << endl;
}

void solve1452B()
{
   ll n, sum = 0, ans;
   cin >> n;
   vector<ll> a(n);
   for(int i = 0; i < n; i++)
   {
      cin >> a[i];
      sum += a[i];
   }
   sort(a.begin(), a.end());
   ll maxineed = (sum + n - 2) / (n - 1);
   ll needsum = maxineed * (n - 1);
   //cout << "maxineed " << maxineed << " needsum " << needsum << endl;
   ans = needsum - sum;
   sum += ans;
   //cout << "sum "<< sum << " ans " << ans << endl;
   if(maxineed < a.back()) ans += a.back() * 1ll * (n - 1) - sum; 
   cout << ans << endl;
}

void solve463B()
{
   int n, x, maxi = INT_MIN;
   cin >> n;
   for(int i = 1; i <= n; i++)
   {
      cin >> x;
      maxi = max(maxi, x);
   }
   cout << maxi << endl;
}

void solve1370B()
{
   int n, x;
   cin >> n;
   vector<int> odds, evens;
   for(int i = 1; i <= 2 * n; i++)
   {
      cin >> x;
      if(x % 2 == 1) odds.push_back(i);
      else evens.push_back(i);
   }
   if(odds.size() < evens.size()) swap(odds, evens);
   for(int i = 0; i + 1 < (int)odds.size(); i += 2) 
   {
      if(odds.size() % 2 == 0 && i == (int)odds.size() - 2) continue;
      cout << odds[i] << " " << odds[i + 1] << endl;
   }
   for(int i = 0; i + 1 < (int)evens.size(); i += 2) cout << evens[i] << " " << evens[i + 1] << endl;
}

void solve1463A()
{
   int a, b, c;
   cin >> a >> b >> c;
   int mini = min(a, min(b, c));
   if((a + b + c ) % 9 == 0 && mini >= (a + b + c) / 9) cout << "YES" << endl;
   else cout << "NO" << endl;
}

int main()
{ 
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) 
    {
       //run a function
    }
}
