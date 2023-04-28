#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5001], n, dp[5001][5001][2];
ll call(ll l, ll r, ll plyr)
{
  if (l > r)
    return 0;
  if(dp[l][r][plyr]!=-1)return dp[l][r][plyr];
  if (plyr == 0)
  {
    ll p = a[l] + call(l + 1, r, 1);
    ll q = a[r] + call(l, r - 1, 1);
    return dp[l][r][plyr] = max(p, q);
  }
  else
  {
    ll p = call(l + 1, r, 0);
    ll q = call(l, r - 1, 0);
 
    return dp[l][r][plyr] = min(p, q);
  }
}
int main()
{
 
  ll i, j;
 
  cin >> n;
 
  for(i = 0;i<n;i++)
  {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << call(0, n - 1, 0);
 
 
  return 0;
}
