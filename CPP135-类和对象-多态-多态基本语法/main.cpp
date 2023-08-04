#include <iostream>
using namespace std;

//多态

//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数


//动态多态使用
//父类的指针或者引用 指向子类对象


//动物类
//空类大小为1
class Animal
{
public:
	virtual void speak()//虚函数
	{
		cout<<"动物在说话"<<endl;
	}
};

//猫类
class Cat:public Animal
{
public:
	//重写：函数返回值类型，函数名 参数列表 完全一致称为重写
	void speak()
	{
		cout<<"小猫在说话"<<endl;
	}
};

//执行说话的函数

//没有加virtual时， 函数地址早绑定 在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定 ，需要在运行阶段进行绑定，地址晚绑定

//动态多态使用
//父类的指针或者引用 指向子类对象

void doSpeak(Animal &animal) //Animal & animal = cat
{
	animal.speak();
}


void test01()
{
	Cat cat;
	doSpeak(cat);
	cat.speak();
	cat.Animal::speak();
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
