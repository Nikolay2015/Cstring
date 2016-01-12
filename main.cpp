#include "string.h"
#include <iostream>

using namespace std;

void main()
{
	String a('a',5);
	String b(move(a));
//	String b(a);
	//cout << a.size();
	cout << b << '\n';
	//cout << M_PI << '\n';
	String c("Hi");
	String H = c;
	String Hel("hell");
	String O("o00");
	char *st = "*st44r";
	cout << Hel << '\n';
	cout << "hel += o    "<<(Hel += O) << '\n';
	cout << Hel << '\n';
	cout << "hel += st    " << (Hel += st) << '\n';
	cout << "c += 'a'   " << (c += 'a') << "size of c  "<<'\n';
	cout << c.size() << '\n';
//	cout << (Hel += "suf") << '\n';
	//cout << H << '\n';
	String S1("hi");
	String S2("hh");

	if (S1 != S2)
	{
		cout << "equal" << '\n';
	}
}