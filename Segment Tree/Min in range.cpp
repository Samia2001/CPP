//dp21
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

ll a[200005], seg[800005];

void ini(ll node, ll b, ll e)
{
    if(b == e)
        seg[node] = a[b];
    else
    {
        ll mid = (b + e)/2;
        ll left = node*2;
        ll right = node*2 + 1;

        ini(left, b, mid);
        ini(right, mid + 1, e);

        seg[node] = min(seg[left] , seg[right]);

    }

}

ll query(ll node, ll b, ll e, ll x, ll y)
{
    if(x > e || y < b)
        return 1e18;
    if(b>=x && e<=y)
        return seg[node];

    ll mid = (b + e)/2;
    ll left = node*2;
    ll right = node*2 + 1;

    return min(query(left, b, mid, x, y) , query(right, mid + 1, e, x, y));
}

void update(ll node, ll b, ll e, ll i, ll nval)
{
    if(i > e || i < b)
        return;
    if(b>=i && e<=i)
    {
        seg[node] = nval;
        return;
    }

    ll mid = (b + e)/2;
    ll left = node*2;
    ll right = node*2 + 1;

    update(left, b, mid, i, nval);
    update(right, mid + 1, e, i, nval);

    seg[node] = seg[left] + seg[right];

}

int main()
{
    FastRead

    ll n, i, q, t, x, y;
    cin >> n >> q;

    rep1(i, n)
    cin >> a[i];

    ini(1, 1, n);

    rep(i, q)
    {
        cin >> x >> y;
        cout<<query(1, 1, n, x, y)<<endl;

    }


    return 0;
}



