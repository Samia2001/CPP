/*Suppose we need to model two-dimensional shape objects, such as rectangles, squares, triangles, ellipses, and circles. 
a)rectangle, ellipse and triangle needs two value as input to calculate area
b)Squere and circle needs only one value as input to calculate area
Your code must provide An abstract class named shape and some concrete class.
They have the features:
1) get() to take the input value
2) area() to calculate and return area
Your code will first take an integer choice from user.
if choice=0 then the process will finish and all the previous calculated area will be summed and showed as result.
and for the value of choice 1,2,3,4,5 calculate Circles, ellipses, squares, rectangles, and triangles consecutively.*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
class shape
{
public:
	virtual void get()=0;
	virtual double area()=0;
};
class square:public shape
{
public:
	double a;
	void get()
	{
		cin>>a;
	}
	double area()
	{
		return (a*a);
	}
};
class rectangle:public shape
{
public:
	double a,b;
	void get()
	{
		cin>>a>>b;
	}
	double area()
	{
		return (a*b);
	}
};
class circle:public square
{
public:
	double area()
	{
		return (a*a)*3.14159;
	}
};
class ellipse:public rectangle
{
public:
	double area()
	{
		return (a*b)*3.14159;
	}
};
class tri:public rectangle
{
public:
	double area()
	{
		return (a*b)/2;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("outp.txt", "w", stdout);
#endif
 ll t , c ;
 double sum = 0;
 while(cin >> c)
 {
 	shape *p;
 	square sq;
 	rectangle r;
 	tri tr;
 	ellipse e;
 	circle cir;
 	
 	if(c==0)break;
 	else
 	{
 		if(c==1)
 		{
 			p = &cir;
 		}
 		if(c==2)
 		{
 			p = &e;
 		}
 		if(c==3)
 		{
 			p = &sq;
 		}
 		if(c==4)
 		{
 			p = &r;
 		}
 		if(c==5)
 		{
 			p = &tr;
 		}
 		p->get();
 		sum = sum + p->area();

 	}

 }
 
 cout<<sum;



	
	return 0;
}
