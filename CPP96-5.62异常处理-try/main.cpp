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

void test02()
{
	int a = 1;
	int b = 2;
	while (cin >> a >> b) {
		try {
			if (a != b)
				throw runtime_error("a and b not same");

		}
		catch (runtime_error err) {
			cout << err.what()
				<< "\n Try Again? Enter y or n" << endl;

			char c;
			cin >> c;

			if (!cin || c == 'n')
				break;
		}
	}
}

int main()
{
	test02();
	system("pause");

	return 0;
}