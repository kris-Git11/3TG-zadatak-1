#include "iostream"
#include "math.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>


using namespace std;

class trokut
{
private:
	float a, b, c;
public:
	void value(float, float, float);

	float opseg()
	{
		float ops;
		ops = a + b + c;
		return (ops); }

	float povrsina()
	{
		float s = (a + b + c) / 2;
		float povrs = sqrt(s*(s - a)*(s - b)*(s - c)); 
		return povrs;
	}

	float ptrokut()
	{
		if (a + b>c)
		{
			if (b + c>a)
			{
				if (c + a>b)
				return true;
			}
		}
		return false;
	}



};

void trokut::value(float ta, float tb, float tc)
{
	a = ta;
	b = tb;
	c = tc;
}





int main()
{
	trokut t1;
	float a, b, c;
	cout << "Unesite stranicu trokuta a: " << endl;
	cin >> a;
	cout << "Unesite stranicu trokuta b: " << endl;
	cin >> b;
	cout << "Unesite stranicu trokuta c: " << endl;
	cin >> c;
	t1.value(a, b, c);

	if (t1.ptrokut())
	{
		cout << "Opseg trokuta je: " << t1.opseg() << endl;
		cout << "Povrsina trokuta je: " << t1.povrsina() << endl;

	}
	else
		cout << "Trokut ne postoji." << endl;
	system("pause");
	return 0;

}
