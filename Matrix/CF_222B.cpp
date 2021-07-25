/*instead of exchanging row or column we can just exchange indices*/

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
typedef tree<int,null_type,greater_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
    FastRead
    ll n, m, k;
    cin >> n >>m >>k;

    ll a[n + 5][m + 5], r[n + 5] , c[m + 5], i, j;
    vector<ll>v[n + 5], v1[m + 5];

    rep1(i, n)
    {
        r[i] = i;

        rep1(j, m)
        {
            cin>>a[i][j];
        }
    }

    rep1(i , m)
    c[i] = i;

    ll x, y;
    char ch;

    rep(i, k)
    {
        cin >> ch >> x >> y;
        if(ch == 'r')
            swap(r[x],r[y]);

        else if(ch == 'c')
        {
            swap(c[x],c[y]);

        }

        else
            cout<<a[r[x]][c[y]]<<endl;
    }




    return 0;

}
