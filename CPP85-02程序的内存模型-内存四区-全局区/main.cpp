#include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;
int main()
{
	//解决中文乱码问题
	system("chcp 65001");
	//全局区：
	//全局变量 、静态变量、常量
	
	//创建普通局部变量
	int a = 10;
	int b = 10;
	cout<<"局部变量a的地址为："<<(unsigned int)&a <<endl;
	cout<<"局部变量b的地址为："<<(unsigned int)&b <<endl;

	cout<<"全局变量g_a的地址为："<<(unsigned int)&g_a <<endl;
	cout<<"全局变量g_b的地址为："<<(unsigned int)&g_b <<endl;	


	//静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout <<"静态变量s_a的地址为："<<( unsigned int)&s_a<<endl;
	cout <<"静态变量s_b的地址为："<<( unsigned int)&s_b<<endl;
	system("pause");

	return 0;
}
