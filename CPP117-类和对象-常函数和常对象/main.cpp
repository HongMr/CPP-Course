#include <iostream>

using namespace std;

//常函数
class Person{
public:
	//this指针的本质        是指针常量       指针的指向是不可以修改的
	void showPerson() const //常函数  在成员函数后面加const,修饰的是this指向，让指针指向的值也不可以修改
	{
		this->m_B = 100;
		//this->m_A = 100;//常函数中不允许修改
		//this = NULL;//错误，this指针不可以修改指针的指向
	}
	void func()
	{
		cout<<"普通函数：func\n"<<endl;
	}

    int m_A;	
	mutable int m_B;//特殊变量，添加mutable,即使在常函数中，也可以修改这个值
};

void test01()
{
	Person p ;
	p.showPerson();
}

//常对象
void test02()
{
	const Person p;//在对象前加const,变为常量对象
	//p.m_A = 100;//错误，常对象中不能修改成员变量
	p.m_B = 200;//m_B是特殊值，在常对象下也可以修改

	//常对象只能调用常函数
	p.showPerson();
	//p.func();//常对象，不可以调用普通成员函数,因为普通成员函数可以修改属性
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
