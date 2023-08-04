#include<iostream>
#include<string>
using namespace std;

//普通写法
class Calculator
{
public:
	int getResult(string oper)
	{
		if(oper == "+")
			return m_Num1+m_Num2;
		else if (oper == "-")
			return m_Num1-m_Num2;
		else if (oper == "*")
			return m_Num1*m_Num2;
	}

	int m_Num1;
	int m_Num2;
};

void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout<<c.m_Num1<<" + "<<c.m_Num2<<" = "<<c.getResult("+")<<endl;
	cout<<c.m_Num1<<" - "<<c.m_Num2<<" = "<<c.getResult("-")<<endl;
	cout<<c.m_Num1<<" * "<<c.m_Num2<<" = "<<c.getResult("*")<<endl;

	//如果想扩展新的功能，需求修改源码
	
}

//利用多态实现计算器
//实现计算器抽象类

//多态好处
//1.组织清晰
//2.可读性强
//3.对于前期和后期的维护性高

class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;	
};

class AddCalculator:public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1+m_Num2;
	}
};

class SubCalculator:public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1-m_Num2;
	}
};

class MulCalculator:public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1*m_Num2;
	}
};

void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	//+
	AbstractCalculator *abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout<<abc->m_Num1<<" + "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;	
	delete abc;

	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout<<abc->m_Num1<<" - "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
	delete abc;

	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout<<abc->m_Num1<<" * "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
	delete abc;
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test02();
	
	return 0;
}
