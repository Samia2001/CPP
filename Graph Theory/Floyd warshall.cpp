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

vector<ll>v[1005];
vector<ll>::iterator it;
bool vis[1005];
ll d[1005][1005] , i , j , k;

void floyd(ll n)
{
    rep1(k , n)
    {
        rep1(i , n)
        {
            rep1(j , n)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main()
{
    FastRead

    ll n, m, i, a, b, w;
    cin >> n >> m ;

    rep1(i , n)
    {
        for(j = i+1 ; j<=n ; j++)
        {
            d[i][j] = 1e18;
            d[j][i] = 1e18;
        }
    }

    rep1(i , n)
    d[i][i] = 0;

    rep(i, m)
    {
        cin >> a >> b >> w;
        d[a][b] = w;
        d[b][a] = w;
    }

    floyd(n);
    cout<<d[1][3];



    return 0;
}
/*
6 7
1 2 3
1 3 3
3 4 1
4 1 1
5 6 3
2 6 6
3 5 9
*/
