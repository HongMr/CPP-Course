#include <iostream>
#include <windows.h>
#include <cstdlib>
//浅拷贝--简单的赋值拷贝
//深拷贝与浅拷贝
using namespace std;

class Person{
public:	
	Person()
	{
		cout<<"Person 的构造函数"<<endl;
	}

	Person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout<<"Person 的有参构造函数"<<endl;
	}
	//自己实现拷贝构造函数-叫做深拷贝，解决浅拷贝堆区分配的数据重复释放问题
	Person(const Person &p)
	{
		cout<<"Person 拷贝构造函数调用"<<endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;//编译器默认实现就是这种代码，就是浅拷贝实现的方法

		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}
	~Person()
	{
		cout<<"Person 的析构函数"<<endl;
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
	}

	int m_Age;
	int *m_Height;
};

void test01()
{
	
	Person p1(18,170);
	cout<<"p1 的年龄"<<p1.m_Age<<"p1的身高："<<*p1.m_Height<<endl;

	Person p2(p1);//浅拷贝,利用编译器提供的拷贝构造函数，会做浅拷贝操作；
	//浅拷贝带来的问题，堆区的内存重复释放。
	//利用深拷贝解决浅拷贝问题。
	
	cout<<"p2的年龄"<<p2.m_Age<<"p2的身高："<<*p2.m_Height<<endl;
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	return 0;
}
