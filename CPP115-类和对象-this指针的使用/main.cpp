#include <iostream>

using namespace std;
//this指针的用途
//1.解决名称冲突

//2.返回对象本身用*this

class Person{
public:
	Person(int age)
	{
		//解决名称冲突
		//age = age;//错误，名字冲突了

		//this指针 指向被调用的成员函数 所属的对象
		this->age = age;
	}

	Person& PersonAddAge(Person p)
	{
		this->age = this->age+p.age;

		//this指向p2的指针， 而*this指向的就是p2这个对象本体
		return *this;
	}
	
	int age;
};
//1.解决名称冲突

void test01()
{
	Person p(18);


	cout<<p.age<<endl;
}

//2.返回对象本身用*this
void test02()
{
	Person p1(10);
	Person p2(20);
	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout<<"p2的年龄："<<p2.age<<endl;
}


int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test02();
	
	return 0;
}
