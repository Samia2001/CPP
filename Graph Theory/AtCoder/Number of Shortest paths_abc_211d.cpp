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

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vector<pll>v[200006];
ll n , d[200006] , path[200006] , mod = 1e9+7;

ll dijkstra(ll s)
{
    fill(d , d+n+1 , 1e18);
    d[s] = 0;
    path[s] = 1;
    ll u;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
    pq.push({d[s] , s});
    while(pq.size()!=0)
    {
        u = pq.top().second;
        pq.pop();
        vector<pll>::iterator it;
        for(it = v[u].begin(); it!=v[u].end(); it++)
        {
            if(d[it->first] > d[u] + it->second)
            {
                d[it->first] = d[u] + it->second;
                pq.push({d[it->first],it->first});
                path[it->first] = path[u];
            }
            else if(d[it->first] == d[u] + it->second)
            {
                path[it->first] = (path[u] + path[it->first])%mod;
            }

        }

    }
    return path[n];

}
int main()
{
    FastRead
    ll  m, i, a, b , w;
    cin >> n >> m ;

    rep(i, m)
    {
        cin >> a >> b;
        v[a].push_back({b , 1});
        v[b].push_back({a , 1});
    }

    cout<<dijkstra(1);



    return 0;
}
