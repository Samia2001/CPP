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
ll dp[11][2][99] ;
ll po10[11],k;
bool isprime(ll x)
{
  for(ll i = 2;i*i<=x;i++)
  {
    if(x%i==0)
    {
      return false;
    }
  }
  if(x==1)return false;
  return true;
}
ll sol(ll pos, bool is_small, ll sum) {
  if (pos >= digit.size()) {
    if (isprime(sum)) return 1 ;
    return 0 ;
  }

  if (dp[pos][is_small][sum]!= -1) return dp[pos][is_small][sum];

  ll limit = digit[pos] ;
  if (is_small) limit = 9 ;
  ll val = 0 ;

  for (int i = 0; i <= limit; i++) {
    ll sz = (ll)digit.size()-pos-1;
    val += sol(pos + 1, ((i < digit[pos]) | is_small), sum + i) ;
  }

  return dp[pos][is_small][sum] = val ;
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
    ll a, b ,p=1;
    cin >> a >> b  ;
    po10[0]=1;
    for(i =1 ;i<=10;i++)
      po10[i]=po10[i-1]*10;
    
    ll r, l ;
    convert(b) ;
    memset(dp, -1, sizeof dp) ;
    r = sol(0, 0, 0) ;
    digit.clear() ;
    convert(a - 1) ;
    memset(dp, -1, sizeof dp) ;
    l = sol(0, 0, 0) ;
    digit.clear() ;
    cout <<r - l << endl ;

  }
  return 0;
}
