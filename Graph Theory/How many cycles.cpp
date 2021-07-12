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

vector<ll>v[100006],cycle;
ll vis[100006] , cnt = 0;

void dfs(ll s , ll parent)
{
    vis[s] = 1;
    cycle.pb(s);
    vector<ll>::iterator it;
    for(it = v[s].begin() ; it!= v[s].end() ; it++)
    {
        if(vis[*it]==0)
        {
            vis[*it] = 1;
            dfs(*it , s);
        }
        else if(vis[*it]==1 && *it != parent)
        {
            ll sz = cycle.size() - 1;
            while(sz >= 0)
            {
                cout<<cycle[sz]<<" ";
                if(cycle[sz]==*it)
                    break;
                sz--;
            }
            cnt++;
            cout<<endl;

        }
    }
    vis[s] = 2;
    cycle.pop_back();
}

int main()
{

    ll n, m, i, a, b;
    cin >> n >> m;

    rep(i, m)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i = 1 ; i <= n ; i++)
    {
        if(vis[i]==0)
            dfs(i , -1);
    }
    cout<<"Total number of cycles : "<<cnt;
    return 0;
}
