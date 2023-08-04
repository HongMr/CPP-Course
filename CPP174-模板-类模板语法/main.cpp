#include<iostream>
#include <string>
using namespace std;
//类模板
template<class NameType, class AgeType>

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

void test01()
{
	Person<string,int>("张三",78).showPerson();
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();

	return 0;
}
