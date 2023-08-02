#include <iostream>
using namespace std;
//空指针调用成员函数
class Person{
public:
	void showClassName()
	{
		cout<<"this is Person class"<<endl;
	}

	void showPersonAge()
	{
		if (this == NULL)
			return ;
		
		//报错原因是空指针，this没有可以指向的对象，所以调用错误
		cout<<"age = "<<this->m_Age<<endl;
	}
	
	int m_Age;
};

void test01()
{
	Person *p = NULL;
	p->showClassName();
	p->showPersonAge();
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
