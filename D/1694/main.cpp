#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(ll i, bool vis[], vector<ll> adj[], ll self[], ll sum[], ll l[], ll r[])
{
    vis[i]=true;
    ll j, l1=adj[i].size();

    for(j=0; j<l1; j++)
    {
        if(vis[adj[i][j]]==false)
        {
            dfs(adj[i][j], vis, adj, self, sum, l, r);
            sum[i]=sum[i]+self[adj[i][j]];
        }
    }

    if(sum[i]<l[i]){
        self[i]=r[i];
    }else if(sum[i]<r[i]){
        self[i]=sum[i];
    }else{
        self[i]=r[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, i, j, u, v, ans, m;

    cin>>t;

    for(;t--;)
    {
        cin>>n;

        bool vis[n+1];
        ll self[n+1], sum[n+1];
        vector<ll> adj[n+1];

        for(i=0; i<=n; i++)
        {
            vis[i]=false;
            self[i]=0;
            sum[i]=0;
        }

        for(i=2; i<=n; i++)
        {
            cin>>j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        ll l[n+1], r[n+1];

        for(i=1; i<=n; i++)
        {
            cin>>l[i]>>r[i];
        }

        dfs(1, vis, adj, self, sum, l, r);
        ans=0;

        for(i=1; i<=n; i++)
        {
            if(self[i]>sum[i]){
                ans++;
                //cout<<self[i]<<" "<<sum[i]<<" "<<i<<"\n";
            }
        }

        cout<<ans<<"\n";

    }
}
