#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define    rrep(X,Y)    for(X=Y-1;X>=0;X--)
#define    rrep1(X,Y)   for(X=Y;X>=1;X--)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define case "Case "<<g+1<<":"
#define sf(T) scanf("%lld",&T)
#define pf(T) printf("%lld\n",T)
#define      len(n)             (long long)((log(n)/log(10))+1.0000000001)
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define pi acos(-1)
#define pb push_back
#define pll pair<ll , ll>
#define pqmn priority_queue<ll, vector<ll>, std::greater<ll> >
#define nm -1e18
#define ok return 0

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vector<ll>v[100006],ans;
bool vis[100006];


void dfs(ll s)
{
    vis[s] = 1;
    vector<ll>::iterator it;
    for(it = v[s].begin() ; it!= v[s].end() ; it++)
    {
        if(vis[*it]==0)
        {
            vis[*it] = 1;
            dfs(*it);
        }
    }
    ans.pb(s);
}

int main()
{
    FastRead
    ll n, m, i, a, b;
    cin >> n >> m;

    rep(i, m)
    {
        cin >> a >> b;
        v[a].push_back(b);
    }
    rep1(i , n)
    {
        if(vis[i]==0)
            dfs(i);
    }
    rrep(i, ans.size())
    cout<<ans[i]<<" ";

    return 0;
}
