#include <iostream>
using namespace std;

class Building;

class goodGay
{
public:
	goodGay();
	
	void visit();//参观函数，
	Building *building;
};
class Building
{
	//goodGay是本类的好友，可以访问本类的私有成员
	friend class goodGay;
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
	m_BedRoom = "卧室";
}

goodGay::goodGay()
{
	//
	building = new Building;

}
void goodGay::visit()
{
	cout<<"好友正在访问："<<building->m_SittingRoom<<endl;

	cout<<"好友正在访问："<<building->m_BedRoom<<endl;
}

void test01()
{
	goodGay gg;
	gg.visit();
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
