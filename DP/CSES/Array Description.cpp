#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rrep(X,Y)     for(X=Y-1;X>=0;X--)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define nml ll T = 1,g; for(g=0;g<T;g++)
#define case "Case "<<g+1<<": "
#define pb push_back
#define pll pair<ll , ll>
using namespace std;
vector<ll>digit ;
ll dp[100005][102], n, m, mod = 1e9 + 7;
ll sol(ll pos, ll prev) {
  if (pos >= digit.size()) {
    return 1 ;
  }

  if (dp[pos][prev] != -1) return dp[pos][prev] ;
  if (digit[pos] == 0)
  {
    ll val = 0,p,q;
    if (pos == 0)
    { p = 1;
      q = m;
    }
    else {
      p = max(prev - 1, 1ll);
      q = min(prev + 1, m);
    }
    for (int i = p; i <= q; i++) {
      if (prev == 0 || abs(prev - i) < 2)
        val = (val + sol(pos + 1, i)) % mod ;
    }
    return dp[pos][prev] = val ;
  }
  else
  {
    if (prev == 0 || abs(prev - digit[pos]) < 2)
      return dp[pos][prev] = sol(pos + 1, digit[pos]);
    else
      return 0;
  }

}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i , j;

  cin >> n >> m;
  rep(i , n)
  {
    ll a;
    cin >> a;
    digit.push_back(a);
  }
  memset(dp, -1, sizeof(dp));
  cout << sol(0, 0);


  return 0;
}
