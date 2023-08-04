#include <iostream>
#include <string>
using namespace std;

//虚析构和纯虚析构

class Animal
{
public:
	Animal()
	{
		cout<<"Animal 构造函数"<<endl;
	}
	//利用虚析构可以解决，父类指针释放子类对象时不干净问题
#if 0
	virtual ~Animal()//虚析构函数
	{
		cout<<"Animal 析构函数调用"<<endl;
	}
#else
	//纯虚析构   需要声明也需要实现
	//有了纯虚析构函数之后，这个也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;//纯虚析构
#endif
	
	//纯虚函数
	virtual void speak() = 0;
};
Animal::~Animal()
{
	cout<<"Animal 纯虚析构函数调用"<<endl;
}

class Cat:public Animal
{
public:
	Cat(string name)
	{
		cout<<"Cat构造函数调用"<<endl;
		m_name = new string(name);
	}
	~Cat()
	{
		if(m_name != NULL)
		{
			cout<<"Cat 析构函数调用"<<endl;
			delete m_name;
			m_name = NULL;
		}
	}
	
	virtual void speak()
	{
		cout<<*m_name<<"小猫在说话"<<endl;
	}

	string *m_name;
};

void test01()
{
	Animal *animal = new Cat("tom");
	animal->speak();
	//父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
	delete animal;
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
