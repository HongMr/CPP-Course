#include<iostream>
#include <string>
using namespace std;
//类模板
template<class NameType, class AgeType = int>

class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_Name = name;
		this->m_Age  = age;
	}
	void showPerson()
	{
		cout<<"name : "<<m_Name<<"  age: "<<m_Age<<endl;
	}
	NameType m_Name;
	AgeType  m_Age;
};

//1.类模板没有自动类型推导使用方式

void test01()
{
	//Person("张三",78);//错误：1.类模板没有自动类型推导使用方式

	Person<string,int>("张三",78).showPerson();//正确，只能用显示指定类型
}

//2.类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string>("李四",20).showPerson();
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	test02();

	return 0;
}
