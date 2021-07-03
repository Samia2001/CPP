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
#define case "Scenario #"<<g+1<<": "
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

set<ll>v[100006];

ll n;
void dfs(ll s)
{
    if(v[s].size()==0)
        return;
    ll f = *v[s].begin();
    v[s].erase(f);
    v[f].erase(s);

    if(s!= n+1 && f!=n+1)
    {
        cout<<s<<" "<<f<<endl;

    }
    dfs(f);

}

int main()
{
    ml
    {
        ll m, i, a, b, c = 0;
        cin >> n >> m;
        rep1(i, n)
        v[i].clear();
        rep(i, m)
        {
            cin >> a >> b;
            v[a].insert(b);
            v[b].insert(a);
        }
        rep1(i, n)
        {
            if(v[i].size()%2)
            {
                c++;
                v[i].insert(n+1);
                v[n+1].insert(i);
            }
        }
        cout<<n - c<<endl;

        rep1(i, n)
        {
            if(v[i].size()!=0)
                dfs(i);
        }


    }
    return 0;
}
