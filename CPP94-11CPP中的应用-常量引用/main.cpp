#include<iostream>
using namespace std;


//打印函数
void showValue(const int &val)
{
	cout<<"val = "<<val <<endl;
}
int main()
{
	//解决中文乱码问题
	system("chcp 65001");

	//常量引用
	//使用场景：用来修饰形参，防止误操作
	
	//int a = 10;
	//int &ref =10;//错误：引用必须引一块合法的内存空间

	
	int a = 100;
	showValue(a);

	system("pause");

	return 0;
}
