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
