#include<iostream>
using namespace std;
//继承方式
#if 0
//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//1.公共继承
class Son1:public Base1
{
public:
	void func()
	{
		m_A = 10;//父类中的公共权限成员 到子类中依然是公共权限
		m_B = 10;//父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 10;//父类中的私有权限成员 子类访问不到
	}
};

//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2:protected Base2
{
public:
	void func()
	{
		m_A = 100;//父类中的公共权限成员 到子类中是保护权限
		m_B = 100;//父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 100;////父类中的私有权限成员 子类访问不到
	}
};
//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;

};

class Son3:private Base3
{
public:
	void func()
	{
		m_A = 100;//父类中公共成员 到子类中变为 私有成员
		m_B = 100;//父类中保护成员 到子类中变为 私有成员
		//m_C = 100;//父类中私有成员，子类访问不到
	}
};



void test01()
{
	Son1 s1;
	s1.m_A = 100;//公共权限，类内、类外都能访问
	//s1.m_B = 100;//保护权限在类内能访问，在类外不能访问
	cout <<"Son1 m_A="<<s1.m_A<<endl;
}

void test02()
{
	Son2 s2;
	//s2.m_A = 1000;//在Son2中m_A变为保护权限，因此类外不能访问
	
}
void test03()
{
	Son3 s3;
	//s3.m_A = 1000;//到Son3 中变为私有成员,类外无法访问
	//s3.m_B = 1000;
	
}

int main()
{
	//解决中文乱码问题
	system("chcp 65001");

	cout << " Java的下载视频界面 " << endl;
	
	test01();
	test02();
	test03();

	
	system("pause");

	return 0;
}

#endif

//继承中的对象模型
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son:public Base
{
public:
	int m_D;
};
	
void test01()
{
	cout<<"size of Son = "<<sizeof(Son)<<endl;
}

int main()
{
	test01();
	
	return 0;
}
