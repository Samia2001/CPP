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
#define case "Case "<<g+1<<":"
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

vector<ll>v[100005],ans;
vector<ll>::iterator it;
ll in[100005] ;


void bfs(ll n)
{
    ll i;
    queue<ll>q;
    rep1(i, n)
    {
        if(in[i]==0)
            q.push(i);
    }

    while(q.size()!=0)
    {
        ll u = q.front();


        if(in[u]==0)
        {
            q.pop();
            for(it = v[u].begin() ; it!= v[u].end() ; it++)
            {

                in[*it]--;

                if(in[*it]==0)
                    q.push(*it);
            }
            ans.pb(u);
        }
    }
}

int main()
{
    FastRead
   
        ll n, m, i, a, b;
        cin >> n >> m;

        rep(i, m)
        {
            cin >> a >> b;
            in[b]++;
            v[a].push_back(b);
        }


        bfs(n);


        rep(i, ans.size())
        cout<<ans[i]<<" ";
        cout<<endl;


        ans.clear();
        memset(v, 0, sizeof(v));
        memset(in, 0, sizeof(in));

    return 0;
}
