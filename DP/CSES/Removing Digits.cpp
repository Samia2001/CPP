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
 
ll rec(ll n)
{
  ll i;
  if (n == 0)
    return 0;
  else if (dp[n] != 1e18)
    return dp[n];
  ll N = n;
  while (n)
  {
    if (n % 10)
    {
      ll b = N - (n % 10);
      //cout<<b<<endl;
      dp[N] = min(1 + rec(b), dp[N]);
    }
    n /= 10;
  }
  return dp[N];
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i , j;
  nml {
    ll n;
    cin >> n;
    for (i = 0; i <= 1000001; i++)
      dp[i] = 1e18;
    cout << rec(n);
  }
  return 0;
}
