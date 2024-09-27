/*"Success isn't permanent, failure isn't fatal,
    it's the courage to continue that counts"*/
#include<bits/stdc++.h>
using namespace std;
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define pfis(a) printf("%d ",a);
#define pfls(a) printf("%lld ",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb(a) push_back(a);
#define mp(a,b) make_pair(a,b)
#define ll long long
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define endl "\n"
#define BLOCK 750
const ll mod = 1e9 + 7;
vector<ll> v1[200005];
bool vis[200005] = {false};
ll dis[200005];
ll mark[200005];
ll curr = -1;
void dfs(ll s)
{

    curr++;
    //  cout << curr << endl;
    if (curr > 0)
    {
        mark[1]++;
        mark[curr + 1]--;
    }
    vis[s] = 1;
    ll i;
    for (i = 0; i < v1[s].size(); i++)
    {
        ll k = v1[s][i];
        if (vis[k] == 0)
        {
            dfs(k);
            curr--;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    unordered_map<ll, ll> mp;
    sfl(n);
    sfl(m);
    f(i, 1, m + 1)
    {
        sfl(dis[i]);
        if (dis[i] <= 200005)
        {
            mp[dis[i]]++;
        }
    }
    f(i, 1, n)
    {
        ll x;
        sfl(x);
        v1[x].pb(i + 1);
        v1[i + 1].pb(x);
    }
    dfs(1);

    ll ans = 0;
    f(i, 0, n + 1)
    {
        mark[i] = mark[i] + mark[i - 1];
        if (mp[i] > 0)
        {
            ans += mark[i];
        }
        // cout << mark[i] << " ";
    }
    if (mp[0] > 0)
    {
        ans += n;
    }
    cout << ans << endl;
    return 0;
}
