#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rrep(X,Y)     for(X=Y-1;X>=0;X--)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define nml ll T = 1,g; for(g=0;g<T;g++)
#define case "Case "<<g+1<<":"
#define pb push_back
#define pll pair<ll , ll>
using namespace std;
ll mod = 1e9 + 7;
ll dp[1000001];
 
int main()
{
 
  ll i , j;
  nml {
    ll n , m;
    cin >> n >> m;
    ll c[n + 5];
    rep1(i, n)cin >> c[i];
    dp[0] = 1;
 
    for (i = 1; i < n + 1; i++)
    {
      for (j = c[i]; j < m + 1; j++)
      {
 
        dp[j] = (dp[j - c[i]] + dp[j]) % mod;
 
      }
    }
    ll p = dp[m];
    if (p == 1e18)cout << -1 << endl;
    else
      cout << p << endl;
 
  }
  return 0;
}
