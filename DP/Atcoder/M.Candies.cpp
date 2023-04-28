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
ll a[105], dp[102][100005], c[102][100005];
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll n, i, j, m, mod = 1e9 + 7;
  cin >> n >> m;

  rep1(i , n)
  {
    cin >> a[i];

  }
  rep(i , n + 2)
  c[i][0] = 1;
  rep(i , m + 2)
  c[0][i] = 1;

  rep1(i , n)
  {
    for(j = 0;j<=m;j++)
    {
      if (j <= a[i])
      {
        dp[i][j] = c[i - 1][j]%mod;
        //cout<<dp[i][j]<<endl;
      }
      else
      {
        dp[i][j] = (c[i - 1][j] - c[i - 1][j - a[i] - 1]+mod)%mod;
      }
      if (j)
        c[i][j] = (c[i][j - 1] + dp[i][j]) % mod;
    }
  }
  cout << dp[n][m]%mod << endl;
  return 0;
}
