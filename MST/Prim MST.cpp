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
#define case "Case "<<g+1<<": "
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

vector<pll>v[200005];
ll vis[200005];

ll prims(ll n)
{
    ll s = 1;
    priority_queue<pll, vector<pll>, std::greater<pll> >pq;

    ll i, u, sum = 0, j, p;

    for(i = 1 ; i <= n - 1 ; i++)
    {
        u = s;
        vis[s]=1;

        vector<pll>::iterator it;

        for(it = v[u].begin() ; it != v[u].end() ; it++)
        {
            if(vis[it->first]==0)
            {
                pq.push({it->second, it->first});
            }
        }

        while(vis[s])
        {
            pll T = pq.top();
            pq.pop();
            s = T.second;
            p = T.first;
        }

        sum = sum + p ;
    }
    return sum;
}

int main()
{
    FastRead

    ll n, m, i, a, b, w;
    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        v[a].pb({b, w});
        v[b].pb({a, w});
    }

    cout << prims(n);


    return 0;
}



