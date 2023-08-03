#include<iostream>

using namespace std;

//加号运算符重载
class Person
{
	//要变成友元函数才好访问私有成员变量
	friend ostream & operator<<(ostream & out,Person &p);
public:
#if 0
	//成员函数重载加号运算符
	Person operator+(Person &p)
	{
		Person tmp ;
		tmp.m_A = this->m_A + p.m_A;
		tmp.m_B = this->m_B + p.m_B;
		return tmp;
	}
#endif

	//不会利用成员函数重载<<运算符，因为无法实现cout<<在左侧
#if 0
	Person operator<<(Person &p)
	{
		

	}
#endif
	int m_A;
	int m_B;
};

//全局函数重载+
Person operator+(Person &p1,Person &p2)
{
	Person tmp ;
	tmp.m_A = p1.m_A + p2.m_A;
	tmp.m_B = p1.m_B + p2.m_B;
	return tmp;
}

//只能利用全局函数重载左移运算符
ostream & operator<<(ostream & out,Person &p)//本质 operator<<(cout,p)简化成cout<<p
{
	out<<"m_A = "<<p.m_A;
	out<<"m_B = "<<p.m_B;

	return out;
}
void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;

	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//Person p3 = p1+p2;
	//Person p3 = p1.operator+(p2);//成员函数重载的本质调用

	//全局函数重载本质调用

	Person p3 = operator+(p1,p2);

	
	
	cout<<"p3.m_A = "<<p3.m_A<<endl;
	cout<<"p3.m_B = "<<p3.m_B<<endl;
}

//
void test02()
{
	Person p;
	p.m_A = 10;
	p.m_B = 10;
	//cout<<p.m_A<<endl;
	cout<<p<<endl;
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test02();
	
	return 0;
}
