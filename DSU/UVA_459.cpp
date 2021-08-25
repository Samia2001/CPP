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

ll parent[100000],level[100000];

void make_set(ll v)
{
    parent[v]=v;
    level[v]=0;
}

ll find_root(ll v)
{
    if(v!=parent[v])
        return find_root(parent[v]);
    else
        return parent[v];
}

void union_set(ll a,ll b)
{
    ll x=find_root(a);
    ll y=find_root(b);
    if(x==y)
    {
        return;
    }
    if(level[x]>level[y])
        parent[y]=x;
    else
    {
        parent[x]=y;
        if(level[x]==level[y])
            level[y]++;

    }
}
int main()
{
    FastRead

    ll tc, j;
    char a;
    cin >> tc;
    rep(j, tc)
    {
        string b;

        if(j==0)
            cin >> a;

        ll n = a-'A' + 1, i;
        
        rep1(i, n)
        {
            make_set(i);
        }

        while(cin>>b)
        {
            if(b.size()==1)
            {
                a = b[0];
                break;
            }

            ll p = b[0]-'A' + 1;
            ll q = b[1]-'A' + 1;

           union_set(p,q);
        }

        ll x = 0;
        set<ll>s;

        rep1(i, n)
        {
            x = find_root(i);
            s.insert(x);
        }

        cout<<s.size()<<endl;

        if(j<(tc-1))
        cout<<endl;

        memset(parent , 0 , sizeof(parent));
        memset(level , 0 , sizeof(level));

    }

    return 0;
}


