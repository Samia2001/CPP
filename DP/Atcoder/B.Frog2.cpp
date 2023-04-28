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

    cin >> n >>k;

    ll a[n + 5], i, j,dp[n + 5] = {0} , mn = INT_MAX;

    rep(i, n)
    {
        cin >> a[i];
    }

    for(i = 1 ; i< n ; i++)
    {
        mn=INT_MAX;

        for(j = 1 ; j <= min(k ,i) ; j++)
        {
                mn = min(mn ,dp[i-j] + abs(a[i]-a[i-j]));

        }

         dp[i] = mn ;
    }
    cout << dp[n - 1];

    return 0;
}
