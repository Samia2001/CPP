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
string a[1005];
ll n;
ll dp[1005][1005], mod = 1e9 + 7;
ll grid(ll i , ll j)
{
  if (i == n - 1 && j == n - 1)
  {
    if (a[i][j] != '*')
      return 1;
    else
      return 0;
  }
  if (dp[i][j] != -1)
    return dp[i][j] % mod;
  ll p = 0, q = 0;

  if (i + 1 < n && a[i + 1][j] != '*')
    p = grid(i + 1, j);
  if (j + 1 < n && a[i][j + 1] != '*')
    q = grid(i, j + 1);

  return dp[i][j] = (p + q) % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i , j;
  nml {

    cin >> n;

    rep(i , n)
    cin >> a[i];

    rep(i , n + 3)
    {
      rep(j , n + 3)
      {
        dp[i][j] = -1;
      }
    }
    if(a[0][0]=='*')
      cout<<0<<endl;
    else
    cout << grid(0, 0) % mod;


  }


  return 0;
}
