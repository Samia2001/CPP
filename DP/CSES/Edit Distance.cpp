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
string a , b;
ll dp[5005][5005];
ll edit()
{
  ll i , j;
  if (a.size() > b.size())swap(a, b);
  ll n = a.size();
  ll m = b.size();
  for (i = 0; i <= n; i++)
    dp[i][0] = 1e18;
  for (i = 0; i <= m; i++)
    dp[0][i] = i;
  dp[0][0] = 0;
 
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= m; j++)
    {
      if (a[i - 1] != b[j - 1])
      {
        ll mn = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        dp[i][j]=mn+1;
      }
      
      else
      {
        dp[i][j]=dp[i-1][j-1];;
      }
        
    }
  }
  return dp[n][m];
 
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i, j;
  nml{
    cin >> a >> b;
    cout << edit() << endl;
  }
 
  return 0;
}
