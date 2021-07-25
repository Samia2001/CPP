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
#define nm -1e18

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
    FastRead
    ll n, k;
    cin >> n >> k;

    ordered_set os;
    map<ll,ll>mp;

    ll a[n + 5], ar[n + 5] = {0}, i , p , q;

    rep(i, n)
    {
        cin >> a[i];
        os.insert(a[i]);
    }

    p = k%n;
    q = k/n;

    if(k>=n)
    {
        fill(ar, ar+n, q);
    }


    for(i = 0 ; i<p ; i++)
    {
        ll x = *os.find_by_order(i);
        mp[x] = 1;
    }

    rep(i, n)
    {
        if(mp[a[i]] == 1)
            ar[i] = ar[i] + 1;
        cout<<ar[i]<<endl;
    }


    return 0;

}
