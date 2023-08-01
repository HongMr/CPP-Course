#include <iostream>

using namespace std;

class B{
public:
	virtual void f1(int) const
	{
		cout<<" class B virtual f1"<<endl;
	}

	virtual void f2()
	{
		cout<<"class B virtual f2"<<endl;
	}

	void f3()
	{
		cout<<"class B f3()"<<endl;
	}
};

class D1:public B{
public:
	void f1(int) const override
	{
		cout<<"class D1 f1"<<endl;
	}
};

class D2:public B{
public:
	void f1(int) const final; //把函数定义成final了，不允许后续的其他类覆盖f1(int)
};

class D3:public D2{
public:
	void f2(); //正确，覆盖从间接基类B继承而来的f2
	//void f1(int) const; //错误，D2已经将f2声明成final
};

void test01()
{
	B b;
	b.f1(2);

	D1 d;
	d.f1(3);
}

int main(int argc, char **argv)
{
	test01();
	return 0;
}
