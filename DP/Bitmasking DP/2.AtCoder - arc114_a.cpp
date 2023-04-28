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
    ll a[60],mn=1e18;
    rep(i , n)
    {
      cin >> a[i];
    }
    ll prime[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,43, 47};

    for (i = 1 ; i < (1 << 15); i++)
    {
      ll num=1;
      for(j = 0;j<15;j++)
      {
        if(i&(1<<j))
          num*=prime[j];
      }
      ll x=1;
      rep(j,n)
      {
        if(__gcd(a[j],num)==1)
        {
          x=0;
          break;
        }
      }
      if(x)
        mn = min(mn,num);
    }
    cout<<mn<<endl;

  }
  return 0;
}
