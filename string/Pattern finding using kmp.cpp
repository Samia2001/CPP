/*
input-
aabaaab
aab
output-
0
4
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("outp1.txt", "w", stdout);
#endif
   ll i , j;
   string s , p , a;
   cin >> s >> p;
   a = p+"#"+s;
   ll n = a.size();
   std::vector<ll> ar(n+1);
   for (i = 1 ; i < n  ; i++)
   {
      j = ar[i-1];
      while(j>0 && a[i]!=a[j])
         j = ar[j-1];
      if(a[i]==a[j])  
       j++;
      ar[i] = j;
   }
   for(i=0 ;i<ar.size() ;i++)
   {
      if(ar[i]==p.size())
      {
         cout<<i-2*p.size()<<endl;
      }
   }
   //cout<<ar[i]<<" ";
   cout<<endl;

}
