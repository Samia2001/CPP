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
typedef tree<int,null_type,greater_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct edge
{
    ll s, d, w;
};

edge e[100005];
ll dis[100005] , x = 0 , p , q;

void belford(ll n, ll m, ll st)
{
    ll i, j;
    fill(dis, dis+n+1, -1e18);//in shortest path it will be 1e18
    dis[st] = 0;
    rep(i, n+1)
    {
        rep1(j, m)
        {
            ll u = e[j].s;
            ll v = e[j].d;
            ll wt = e[j].w;

            if(dis[u]!=-1e18 && dis[u]+wt>dis[v])//< sign
            {
                dis[v] = dis[u]+wt;
            }
        }
        if(i==n-1)
            p = dis[n];
        if(i==n)
            q = dis[n];
    }

}

int main()
{
    FastRead
    ll  n, m, i, a, b, w;
    cin >> n >> m;

    rep1(i, m)
    {
        cin>>e[i].s>>e[i].d>>e[i].w;

    }

    belford(n, m, 1);

    if(p==q)
        cout<<dis[n]<<endl;
    else
        cout<<"inf"<<endl;

    return 0;
}

