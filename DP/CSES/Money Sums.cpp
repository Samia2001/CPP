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
ll n , a[500];
bool dp[105][100005];
vector<ll>call(ll s)
{
  ll i , j;
  vector<ll>v;
  rep(i, s + 1)
  dp[0][i] = 0;
  rep(i, n + 1)
  dp[i][0] = 1;
 
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= s; j++)
    {
      if (j < a[i])
        dp[i][j] = dp[i - 1][j];
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]]);
      }
    }
 
  }
  for (j = 1; j <= s; j++)
  {
    if (dp[n][j])
      v.pb(j);
  }
 
  return v;
 
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll s = 0, i;
  cin >> n;
  rep1(i , n)
  {
    cin >> a[i];
    s += a[i];
  }
 
  vector<ll>v = call(s);
  cout << v.size() << endl;
  
  rep(i , v.size())
  cout<<v[i]<<" ";
 
 
 
 
  return 0;
}
