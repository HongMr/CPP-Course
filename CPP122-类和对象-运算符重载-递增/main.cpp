#include <iostream>

using namespace std;

//重载递增运算符++
//自定义整型
class MyInteger
{
	friend ostream & operator<<(ostream &out , MyInteger & myint);
	
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符,返回引用是为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}


	//重载++后置运算符
	//int代表占位参数，可以用于区分前置和后置
	MyInteger operator++(int)
	{
		//先 记录当时结果
		MyInteger tmp = *this;
		//后递增
		
		m_Num++;
		return tmp;
	}
private:
	int m_Num;
};

//重载<<运算符
ostream & operator<<(ostream &out , MyInteger & myint)
{
	out<<"m_Num = "<<myint.m_Num;
	return out;
}
void test01()
{
	MyInteger myint;
	cout<<myint<<endl;

	cout<<++myint<<endl;
}

void test02()
{
	MyInteger myint;
	cout<<myint++<<endl;
	cout<<myint<<endl;
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test02();
	
	return 0;
}
