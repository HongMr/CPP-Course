#include <iostream>
using namespace std;

//普通函数与函数模板调用规则
//1.如果函数模板和普通函数都可以调用，优先调用普通函数
//2.可以通过空模板参数列表 强制调用 函数模板
//3.函数模板可以发生函数重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板
#if 1
void myPrint(int a,int b)
{
	cout<<"调用的普通函数"<<endl;
}
#endif



template<class T>
void myPrint(T a, T b)
{
	cout<<"调用的模板 "<<endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout<<"调用重载的模板"<<endl;
}

void test01()
{
	int a = 10,b = 20;
	myPrint(a,b);

	//通过空模板参数列表，强制调用函数模板
	myPrint<>(a,b);
	int c = 30;
	myPrint(a,b,c);


	//4.如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'a',c2 = 'b';
	myPrint(c1,c2);
}


int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();

	return 0;
}
