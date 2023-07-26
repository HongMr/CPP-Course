#include<iostream>
using namespace std;

//1.new的基本语法
int *func()
{
	//在堆区创建整型数据
	//new返回是 该数据类型的指针
	int *p = new int(10);
	return p;
}

void test01()
{
	int *p = func();
	cout<< *p <<endl;

	//堆区的数据由程序员管理开辟，程序员管理释放
	delete p;
	//cout<< *p <<endl;
}

//2.在堆区利用New开辟数组
void test02()
{
	//创建10个整型数据的数组，在堆区
	int *arr = new int[10];
	for(int i = 0;i< 10;i++)
	{
		arr[i] = i+100;
	}

	for(int i = 0; i < 10;i++)
		cout<<arr[i]<<endl;

	int *tmp = new int[100];
	int *pTmp = new int;
	cout<<*pTmp<<endl;
}
int main()
{
	//解决中文乱码问题
	system("chcp 65001");
	test02();
	system("pause");

	return 0;
}
