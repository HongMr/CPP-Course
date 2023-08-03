#include <iostream>

using namespace std;

//使用VS中的 x64 Native Tools Command Prompt for VS 2022这个工具打开main.cpp的路径，cd /d 路径，使用下面的命令
//cl /d1 reportSingleClassLayoutSon main.cpp

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

class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器给隐藏了，因此访问不到，但是确实被继承下去了
	cout<<"size of Son = "<<sizeof(Son)<<endl;
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
