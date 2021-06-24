/*  _/_/_/_/
 _/_/_/_/_/
_/_/
_/_/
_/_/_/
 _/_/_/_/_/
      _/_/_/
         _/_/
         _/_/
  _/_/_/_/_/
   _/_/_/_/
*/
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

vector<pll>v[100005];
vector<pll>::iterator it;
ll cnt[100005], s, d, cost, n;

ll bfs(ll s)
{
    ll i;
    queue<ll>q;
    q.push(s);
    fill(cnt, cnt+100005, INT_MAX);
    cnt[s] = 0;

    while(q.size()!=0)
    {
        ll u = q.front();
        q.pop();

        for(it = v[u].begin() ; it!= v[u].end() ; it++)
        {
            ll v = it->first;
            ll w = it->second;
            if(cnt[v]>(cnt[u]+w))
            {
                q.push(v);
                cnt[v] = min(cnt[v],(cnt[u] + w));
            }

        }
    }
    return cnt[d];
}
int main()
{
    ml
    {

        ll  m, i, a, b;
        cin >> n >> m >> s >> d;

        rep(i, m)
        {
            cin >> a >> b >> cost;
            v[a].push_back({b, cost});
            v[b].push_back({a, cost});
        }
        ll x = bfs(s);
        if(x!=INT_MAX)
        {
            cout<<x<<endl;
        }
        else
        {
            cout<<"NONE"<<endl;
        }
        memset(v, 0, sizeof(v)) ;
    }

    return 0;
}
