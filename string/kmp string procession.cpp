#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("outp1.txt", "w", stdout);
#endif
   ll i , j;
   string a;
   cin >> a;
   ll n = a.size();
   for (i = 0 ; i < n  ; i++)
   {
      ll x = 0;
      if (i == 0)cout << x << " ";
      else
      {  for (j = 1; j <= i; j++)
         {
            string b = a.substr(0, j);
            string c = a.substr(i - j + 1, j);
            //cout << b << " " << c << endl;
            if (b == c)
               x = b.size();
         }
         cout << x << " ";
      }
   }
}
