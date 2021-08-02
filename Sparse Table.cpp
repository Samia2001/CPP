
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

ll LOG = 16;
ll sp[100005][17], lg[100005];

void sparse(ll n, ll a[])
{
    ll i , j;
    lg[0] = -1;
    rep1(i, n)
    {
        lg[i] = lg[i/2]+1;
    }
    rep(i, n)
    {
        sp[i][0] = a[i];
    }

    rep1(j, LOG)
    {
        for(i = 0 ; i + (1<<j)-1<n ; i++)
        {
            sp[i][j] = min(sp[i][j-1], sp[i+ (1<<(j-1))][j-1]);
        }
    }
}
ll query(ll l, ll r)
{
    ll len = r-l+1;
    ll x = lg[len];
    return min(sp[l][x],sp[r - (1<<x) + 1][x]);
}
int main()
{
    FastRead
    
    ll n, i, j;
    cin >> n;
    
    ll a[n + 5];

    rep(i, n)
    {
        cin>>a[i];
    }

    sparse(n, a);

    ll q, l, r;
    cin >> q;

    rep(i, q)
    {
        cin >> l >> r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}

