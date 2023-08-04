#include <iostream>
using namespace std;
#if 0

//函数模板
//交换两个整型函数
void swapInt(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//交换两个浮点型函数
void swapDouble(double &a,double &b)
{
	double tmp = a;
	a = b;
	b = tmp;
}


//函数模板
template<typename T>//声明一个模板 告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b)
{
	T tmp =a;
	a = b;
	b = tmp;
}

void test01()
{
	int a = 10;
	int b = 20;
	
	//swapInt(a, b);

	//两种方式使用函数模板
	//1.自动类型推导
	//mySwap(a,b);

	//2.显示指定类型
	mySwap<int>(a,b);
	
	
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	
	double c = 1.11;
	double d = 2.22;
	swapDouble(c,d);	
}
#endif

//函数模板注意事项

template<class T>//typename 可以替换成class
void mySwap(T &a, T &b)
{
	T tmp =a;
	a = b;
	b = tmp;
}

//1.自动类型推导，必须推导出一致的数据类型T才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	mySwap(a,b);//正确
	//mySwap(a,c);//错误，推导不出一致的T类型
	
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;

	
}
//2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout<<"func函数调用"<<endl;
}

void test02()
{
	//func();//错误，无法确定T的类型
	func<int>();//正确，可以确定T的类型为int
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	test02();
	return 0;
}
