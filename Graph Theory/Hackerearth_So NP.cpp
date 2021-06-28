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
 
vector<ll>v[400005];
bool vis[400005];
ll c = 0 , d = 0;
 
void dfs(ll s)
{
    vis[s]=1;
    c++;
    vector<ll>::iterator it;
    for(it = v[s].begin();it!=v[s].end();it++)
    {
        if(vis[*it] == 0)
        {
            vis[*it] = 1;
            dfs(*it);
 
        }
    }
}
int main()
{
    ll n, m, k , i, a, b, cnt = 0 , sum = 0;
    cin >> n >> m >> k;
 
    rep(i, m)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
 
    }
    rep1(i , n)
    {
        if(vis[i]==0)
        {
            cnt++;
            c = 0;
            dfs(i);
            sum =sum + (c - 1);
 
        }
    }
 
    if(cnt>k)
    {
        cout<<"-1";
    }
    else
    {
        cout<<m-(sum-(k-cnt));
    }
 
 
    return 0;
}
