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
ll dp[11][99] ;
map<ll, ll>mp;
ll sol(ll pos, ll prev) {
  if (pos >= digit.size()) {

    return 1;
  }

  if (dp[pos][prev] != -1) return dp[pos][prev] ;
  ll val = 0;

  for (int i = 0; i <= 9; i++) {

    if (mp[i])
    {
      ll p = abs(prev - i);
      if (p <= 2 || prev == 0)   
      {
        val += sol(pos + 1, i) ;
      }
    }

  }

  return dp[pos][prev] = val ;
}
void convert(ll x) {
  while (x) {
    digit.push_back(x % 10) ;
    x /= 10;
  }
  reverse(digit.begin(), digit.end()) ;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i , j;
  ml{
    ll n , m;
    cin >> m >> n;
    rep(i , m)
    {
      ll b;
      cin >> b;
      mp[b] = 1;
    }

    ll r, l , N = n, num = 1;
    while (N)
    {
      num *= 10;
      N--;
    }
    num--;
    convert(num) ;
    memset(dp, -1, sizeof dp) ;
    r = sol(0, 0) ;
    cout << case<<r << endl;
    digit.clear() ;
    mp.clear();
    
  }
  return 0;
}
