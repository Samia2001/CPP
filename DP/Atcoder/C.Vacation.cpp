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
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define pi acos(-1)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
    FastRead
    ll n, k;

    cin >> n;

    ll a[n + 5] , b[n + 5] , c[n + 5] , i, j ,dp1[n + 5] = {0} ,dp2[n + 5] = {0}, dp3[n + 5] = {0};

    rep(i, n)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp1[0] = a[0];
    dp2[0] = b[0];
    dp3[0] = c[0];
    for(i = 1 ; i< n ; i++)
    {
        dp1[i] = a[i] + max(dp2[i - 1],dp3[i - 1]);
        dp2[i] = b[i] + max(dp3[i - 1],dp1[i - 1]);
        dp3[i] = c[i] + max(dp2[i - 1],dp1[i - 1]);
    }

    cout<<max(dp1[n - 1],max(dp2[n - 1],dp3[n - 1]));

    return 0;
}
