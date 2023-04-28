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
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i , j;
  nml {
    ll n , m;
    cin >> n >> m;
    ll c[n + 5],sum[m+5]={0};
    rep1(i, n)cin >> c[i];
    dp[0] = 1;
    sum[0]=1;
    for (i = 1; i < m + 1; i++)
    {
      for (j = 1; j < n + 1; j++)
      {
        if(i>=c[j])
        dp[i]=(dp[i]+sum[i-c[j]])%mod;
 
      }
      sum[i]=dp[i];
    }
    ll p = dp[m];
    if (p == 1e18)cout << -1 << endl;
    else
      cout << p << endl;
 
  }
  return 0;
}
