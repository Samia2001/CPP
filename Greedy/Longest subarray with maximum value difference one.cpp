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
#define nml ll T = 1,g; for(g=0;g<T;g++)
#define case "Case "<<g+1<<":"
#define fs(n) fixed << setprecision(n)
#define sf(T) scanf("%lld",&T)
#define pf(T) printf("%lld\n",T)
#define      len(n)             (long long)((log(n)/log(10))+1.0000000001)
#define FastRead                      \
ios_base::sync_with_stdio(false); \
cin.tie(0);
#define pi acos(-1)
#define pb push_back
#define pll pair<ll , ll>
#define ceill(ggg,gg) (ggg/gg)+bool(ggg%gg)
#define pqmn priority_queue<ll, vector<ll>, std::greater<ll> >
#define nm -1e18
#define ok return 0

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll mod = 998244353;
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
  if (a.first == b.first)
    return (a.second > b.second);
  else
    return (a.first < b.first);
}

int main()
{
  FastRead
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i , j;
  nml{
    ll n , mx = nm , x = -1 , c = 1;
    cin >> n;
    ll a[n+5];
    rep(i , n)cin >> a[i];
    ll i = 0 , j = 1;
    while(j<n)
    {
      if(abs(a[j]-a[i])==0)
      {
        c++;
        j++;
      }
      else if(abs(a[j]-a[i])==1 && x==-1)
      {
        x = a[j];
        c++;
        j++;
      }
      else if(a[j]==x || a[j]==a[i])
      {
        c++;
        j++;
      }
      else
      {
        mx = max(mx , c);
        c = 1;
        x = -1;
        i = j-1;
        if(abs(a[j]-a[i])!=1)
         {
          i = j;
          j++;
         }
      }
    }
    mx = max(mx , c);
    cout<<mx<<endl;

  }


  return 0;
}

