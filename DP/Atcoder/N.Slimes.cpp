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
ll n, a[505], dp[505][505],cum[506];

ll call(ll l, ll r)
{
  if(l==r)
    return dp[l][r]=0;
  if(dp[l][r]!=-1)return dp[l][r];
  ll mn = 1e18;
  for(ll i = l;i<r;i++)
   mn = min(mn,call(l,i)+call(i+1,r)+cum[r]-cum[l-1]);
 return dp[l][r]=mn;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i, j;
  cin >> n;
  rep1(i , n)
  {
    cin >> a[i];
    cum[i]=cum[i-1]+a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << call(1, n);
  return 0;
}
