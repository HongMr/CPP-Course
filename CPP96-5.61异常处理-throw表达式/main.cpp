#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test01()
{
	int a = 1;
	int b = 2;
	cin >> a;
	cin >> b;
	if (a != b)
		throw runtime_error("a and b not same");

	cout << a + b << endl;
}

int main()
{
	test01();
	system("pause");

	return 0;
}