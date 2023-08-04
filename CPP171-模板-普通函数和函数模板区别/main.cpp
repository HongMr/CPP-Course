#include <iostream>

using namespace std;

//普通函数于函数模板区别
//1.普通函数调用可以发生隐式类型转换
//2.函数模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板 用显示指定类型 可以发生隐式类型转换

//普通函数
int myAdd01(int a, int b)
{
	return a+b;
}

//函数模板
template<class T>
T myAdd02(T a,T b)
{
	return a+b;
}

void test01()
{
	int a = 10;
	int b = 10;
	char c = 'c'; //c - 99
	cout<<myAdd01(a,b)<<endl;//正确
	cout<<myAdd01(a,c)<<endl;//正确
}

void test02()
{
	int a = 10;
	int b = 10;
	char c = 'c';
	cout<<myAdd02(a,b)<<endl;//正确
	//自动推导，会出错
	//cout<<myAdd02(a,c)<<endl;//错误
	cout<<myAdd02<int>(a,c)<<endl;//正确，显示指定类型
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	test02();

	return 0;
}
