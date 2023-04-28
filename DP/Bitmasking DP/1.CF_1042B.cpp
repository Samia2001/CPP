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
ll mask(string a)
{
  sort(a.begin(), a.end());
  ll sum =0,i;
  rep(i, a.size())
  { 
    ll b = a[i] - 'A';
    sum += (1<<b);

  }
  return sum;
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
    ll c[n + 5],mn=1e18,val[8];
    string a[n + 5];
    rep1(i,8)
    val[i]=1e18;

    rep(i , n)
    {
      cin >> c[i] >> a[i];
      ll p =  mask(a[i]);
      val[p]=min(val[p],c[i]);
      
    }
    mn = min(mn , min((val[1]+val[2]+val[4]),val[7]));

    rep1(i,7)
    {
      for(j = i+1;j<=7;j++)
      {
        ll x = val[i];
        ll y = val[j];
        if(x!=1e18 && y!=1e18 && i+j>=7)
        {
          mn = min(mn,x+y);
        }
      }
    }
    if(mn>=1e18)mn=-1;
    
    cout<<mn<<endl;




  }


  return 0;
}
