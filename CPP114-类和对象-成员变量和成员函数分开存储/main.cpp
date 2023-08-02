#include <iostream>

using namespace std;

//成员变量  和 成员函数分开存储的

class Person
{
public:
	int m_A;//非静态成员变量，属于类的对象上
	
	//静态成员变量不属于某一个对象，不属于类的对象上
	static int m_B;

	void func(){} //非静态成员函数，存放再其他地方，不属于类对象上

	static void func2(){}//静态成员函数，不属于类的对象上。
	
};

int Person::m_B = 50;

void test01()
{
	Person p;
	//空对象占用内存空间为：1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每一个空对象也应该哟一个独一无二的内存地址
	cout<<"size of p = "<<sizeof(p)<<endl;
}

void test02()
{
	Person p ;
	cout<<"size of p = "<<sizeof(p)<<endl;
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test02();
	
	return 0;
}
