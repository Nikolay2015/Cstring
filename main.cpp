#include "Mystring.h"
#include <iostream>

using namespace std;
const unsigned number_tests = 24;
int test_mas[number_tests];

void TEST_1()
{
	String A("Hello World");

	if (A == "Hello World")
	{
		test_mas[0] = 1;
	}

	String B("Hello World", 5);

	if (B == "Hello")
	{
		test_mas[1] = 1;
	}

	String C('H',5);

	if (C == "HHHHH")
	{
		test_mas[2] = 1;
	}

	String D(A);

	if (D == "Hello World")
	{
		test_mas[3] = 1;
	}

	String E(move(A));

	if (E == "Hello World")
	{
		test_mas[4] = 1;
	}

	String F;

	if (F == "")
	{
		test_mas[5] = 1;
	}
};

void TEST_2()
{
	String A("Hello World");
	String B;

	B = A;
	if (A == "Hello World")
	{
		test_mas[6] = 1;
	}

	String C("Hello World");
	String D;

	C = move(D);
	if (A == "Hello World")
	{
		test_mas[7] = 1;
	}
};

void TEST_3()
{
	String A("Hello");
	String B(" World");

	A += B;
	if (A == "Hello World")
	{
		test_mas[8] = 1;
	}

	String C("Hello");

	C += " World";
	if (C == "Hello World")
	{
		test_mas[9] = 1;
	}

	String D("Hello Worl");

	D += 'd';
	if (D == "Hello World")
	{
		test_mas[10] = 1;
	}
};

void TEST_4()
{
	String A("LIVE");
	String B("EVIL");

	A.myswap(B);
	if ((B == "LIVE") && (A == "EVIL"))
	{
		test_mas[11] = 1;
	}

	String C("Live");

	C[1] = 'o';
	if (C == "Love")
	{
		test_mas[12] = 1;
	}

	String D("Live");

	if (D[1] == 'i')
	{
		test_mas[13] = 1;
	}

	String E("Live");
	if (E.at(1) = 'i')
	{
		test_mas[14] = 1;
	}
};

void TEST_5()
{
	String A("Hello");
	String B(" World");

	A = A + B;
	if (A == "Hello World")
	{
		test_mas[15] = 1;
	}

	String C("Hello");

	C = C + " World";
	if (C == "Hello World")
	{
		test_mas[16] = 1;
	}

	String D(" World");

	D = "Hello" + D;
	if (D == "Hello World")
	{
		test_mas[17] = 1;
	}
};

void TEST_6()
{
	String A("Hi_aam");
	String B("Hi_aam");
	if (A == B)
	{
		test_mas[18] = 1;
	}

	String C("Hi_aaa");

	if ((C < A) == true)
	{
		test_mas[19] = 1;
	}
	
	if (A != C)
	{
		test_mas[20] = 1;
	}
	String D("Hi_aamm");
			
	if (A <= D)
		{
			test_mas[21] = 1;
		}
	if ((A > C) == true)
	{
		test_mas[22] = 1;
	}

	String E("Hi_aa");

	if (A >= E)
	{
		test_mas[23] = 1;
	}

};

void result()
{
	char yes = 0;
	for (unsigned i = 0; i < number_tests; i++)
	{
		if (test_mas[i] == 0)
		{
			yes = 1;
			cout << "TEST # " << i << " Not Passed" << '\n';
		}
	}
	if (yes == 0)
	{
		cout << "ALL TEST PASSED" << '\n';
	}
	//system("PAUSE");//del this string 
};

int main()
{
	TEST_1();//= () 
	TEST_2();//operator tests
	TEST_3();//+= tests
	TEST_4();//swap and []
	TEST_5();//tests of +
	TEST_6();// < == <= >= >
	result();
	return 0;
}