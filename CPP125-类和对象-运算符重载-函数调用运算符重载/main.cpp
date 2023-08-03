#include <iostream>
using namespace std;
//函数调用运算符()可以重载
//由于重载后使用的方式非常像函数的调用，因此称为仿函数
//仿函数没有固定写法 非常灵活

//
class MyPrint
{
public:
	//重载函数调用运算符
	void operator()(string test)
	{
		cout<<test<<endl;
	}
};

void test01()
{
	MyPrint myPrint;
	myPrint("hello world");//由于重载后使用的方式非常像函数的调用，因此称为仿函数
}
//仿函数没有固定写法 非常灵活

class MyAdd
{
public:
	int operator()(int num1,int num2)
	{
		return (num1+num2);
	}
};

void test02()
{
	MyAdd myadd;
	int ret = myadd(10,10);
	cout<<ret<<endl;

	//匿名函数对象
	cout<<MyAdd()(100,100)<<endl;
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test02();
	
	return 0;
}
