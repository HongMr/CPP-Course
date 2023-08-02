#include <iostream>
using namespace std;

//静态成员变量
#if 0

class Person
{
public:
	//1.所有对象都共享同一份数据
	//2.编译阶段就分配内存
	//3.类内声明，类外初始化操作
	static int m_A;
private:
	//静态成员变量也是有访问权限的
	static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;
void test01()
{
	Person p;
	cout<<p.m_A<<endl;
	Person p2;
	p.m_A = 200;
	cout<<p.m_A<<endl;
}

void test02()
{
	//静态成员变量 不属于某个对象上，所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式

	//1.通过对象进行访问
	Person p ;
	cout<<p.m_A<<endl;

	//2.通过类名进行访问；
	cout<<Person::m_A<<endl;

	//错误，私有权限的静态变量外部无法访问
	//cout<<Person::m_B<<endl;
}
#endif

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Person
{
public:

	//静态成员函数
	static void func()
	{
		m_A = 100;//静态成员函数可以访问 静态成员变量
		//m_B = 200;//错误，静态成员函数 不可以访问非静态成员变量,无法区分到底是那个对象中的m_B
		cout <<" static void func 调用"<<endl;
	}

	static int m_A;//静态成员变量
	int m_B;//非静态成员变量
};

int Person::m_A = 0;

void test01()
{
	//1.通过对象访问

	Person p;
	p.func();
	//2.通过类名进行访问

	Person::func();
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	return 0;
}
