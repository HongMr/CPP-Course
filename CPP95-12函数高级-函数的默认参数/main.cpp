#include<iostream>
#include<string>
#include<vector>
using namespace std;

//函数默认参数
int func(int a, int b, int c)
{

	return a + b + c;
}
void test01()
{
	string str("some string");
	for (auto c : str)
		cout << c << endl;
}

void test02()
{
	vector<int> arr;
	int a = 0;
	int count = 0;
	while (cin >> a)
	{
		arr.push_back(a);
		++count;
		if (count == 3)
			break;
	}

#if 0
	for (auto c = 0; c < arr.size();c++)
		cout << arr[c] << endl;

	for (auto c : arr)
		cout << c << endl;
#endif 
	cout << "-------------" << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
		cout << *it << endl;
	cout << "======" << endl;
	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << "val:" << *it << endl;
}
int main()
{
#if 0
	cout<< func(1,20,30)<<endl;

	string line;
	while (getline(cin, line))
	{
		auto size = line.size();
		cout << size << endl;
		cout << line << endl;
	}
#endif 	
	test02();
	system("pause");

	return 0;
}