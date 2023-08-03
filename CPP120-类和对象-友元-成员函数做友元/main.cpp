#include <iostream>
#include <string>

using namespace std;

class Building;

class GoodGay
{
public:
	GoodGay();

	void visit();//让visit函数可以访问Building中私有成员

	void visit2();//让visit2函数不可以访问Building中私有成员

	Building *building;
};

class Building
{
	//告诉编译器GoodGay类下的visit成员函数作为Building的好友，可以访问Building的私有成员变量
	friend void GoodGay::visit();
public:
	Building();
	
public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom     = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout<<"好友正在访问："<<building->m_SittingRoom<<endl;
	cout<<"好友正在访问："<<building->m_BedRoom<<endl;
}

void GoodGay::visit2()
{
	cout<<"好友2 正在访问："<<building->m_SittingRoom<<endl;
	//cout<<"好友2 正在访问："<<building->m_BedRoom<<endl;
}

void test01()
{

	GoodGay gg;
	gg.visit();
	gg.visit2();
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
