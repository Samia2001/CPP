// Define a class Distance with feet and inch and with a print function to print the
// distance.
// a) overload < operator compares two distances using member function.
// b) overload + operator to add two Distances using friend function.
// c)use prefix postfix operators
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Distance
{
public:
	double f , i;
Distance()
{
}
Distance(double x , double y)
{
	f = x;
	i = y;
}
bool operator< (Distance d2)
{
   double a = d2.f+(d2.i/12);
   double b = f + (i/12);
   return (a>b);
}
Distance operator++()
{
	Distance d;
	d.f = f+1;
	d.i = i;
	return d;
}
Distance operator++(int)
{
	Distance d;
	d.i = i++;
	d.f = f;
	return d;
}
friend Distance operator+(Distance d1 , Distance d2);

};
Distance operator+(Distance d1 , Distance d2)
{
	Distance d3;
	ll p = (d1.i+d2.i);
	d3.i = p%12;
	d3.f = d1.f+d2.f+p/12;

	return d3;
}
int main()
{
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("outp.txt", "w", stdout);
#endif
 double m,n,o,p;
 cin >> m >> n >> o >> p;
 Distance d1(m,n),d2(o,p),d3;
 
 if(d1<d2)
 	cout<<"distance 2 is bigger"<<endl;
 else
 	cout<<"distance 1 is bigger"<<endl;
d3 = d1+d2;

 cout<<"sum of 2 distances is"<<" "<<d3.f<<" feet "<<d3.i<<" inch"<<endl;
 d3 = (d1++) + d2;
 cout<<d3.f<<" feet "<<d3.i<<" inch"<<endl;


 
	return 0;
}
