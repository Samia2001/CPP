// A book shop maintains the inventory of books that are being sold at the shop.
// The list includes details such as author, title, price, publisher and stock position.
// Whenever a customer wants a book, the sales person inputs the title and author
// and the system searches the list and displays whether it is available or not. If
// it is not, an appropriate message is displayed. If it is, then the system displays
// the book details and requests for the number of copies required. If the requested
// copies are available, the total cost of the required copies is displayed, otherwise
// the message Sorry! These many copies are not in stock is displayed.
// Design a system using a class called stock with suitable member functions and
// constructors.

#include<bits/stdc++.h>
#define ll long long
using namespace std;
class stock
{
public:
	ll p,stp;
	static ll cnt;
	string author , pub , t;
	stock()
	{
		getline(cin , author);
		getline(cin,t);
		cin >> p ;
		getchar();
		getline(cin,pub); 
		cin>> stp;
		getchar();
	}
	void display()
	{
		cout<<author<<endl<<t<<endl<<p<<endl<<pub<<endl<<stp<<endl;

	}
	ll search(string A , string T)
	{
		if(A==author && t == T)
		{
			display();
			ll copies;
			cout<<"How many copies you want? "<<endl;
			cin >> copies;
			if(copies<=stp)
			{
				return p*copies;
			}
			else
			{
				return -1;
				
			}
		}
		else
		{
			cnt++;
			return 0;
		}
	}

	

	
};
ll stock::cnt = 0;

int main()
{
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("outp.txt", "w", stdout);
#endif
	stock a[5];
	string author , t;
	ll i;
	getline(cin , author);
	getline(cin,t);
	for(i = 0 ; i<5 ; i++)
	{
		ll p = a[i].search(author,t);
		if(p>0)
			{
				cout<<"total price = "<<p<<endl;
				break;
			}
		else if(p==-1)
		{
			cout<<" Sorry! These many copies are not in stock."<<endl;
			break;
		}

	}
	if(stock::cnt==5)
		cout<<"Not available"<<endl;


	
	return 0;
}
