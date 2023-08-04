#include <iostream>
#include <string>
using namespace std;

//普通函数与函数模板调用规则
//1.如果函数模板和普通函数都可以调用，优先调用普通函数
//2.可以通过空模板参数列表 强制调用 函数模板
//3.函数模板可以发生函数重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板

class Person
{
public:
	Person(string name,int age)
	{
		m_Name = name;
		m_Age  = age;
	}

	string m_Name;
	int m_Age;
};

//模板局限性

//模板并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

//对比两个数据是否相等函数
template<class T>
bool myCompare(T &a, T &b)
{
	if(a ==b)
		return true;
	else 
		return false;
}


//利用具体化Person的版本实现代码，具体优先调用
template<> bool myCompare(Person &p1, Person &p2)
{
	if(p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
		return true;
	else
		return false;
}

void test01()
{
	int a = 10;
	int b = 20;

	bool ret = myCompare(a,b);
	if (ret == true)
		cout<<"对比相等"<<endl;
	else
		cout<<"对比不相等"<<endl;
}

void test02()
{
	Person p1("tom",19);
	Person p2("tom",19);

	bool  ret = myCompare(p1,p2);
	if(ret)
		cout<<"p1 == p2"<<endl;
	else
		cout<<"p1 != p2"<<endl;
	
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	test02();

	return 0;
}
