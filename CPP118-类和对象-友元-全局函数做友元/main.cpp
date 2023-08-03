#include <iostream>

using namespace std;

class Building
{
	//goodGay全局函数是Building好朋友，可以访问Building中私有成员
	friend void goodGay(Building *building);//全局函数作为友元

public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;

private:
	string m_BedRoom;
	
};

//全局函数
void goodGay(Building *building)
{
	cout<<"好友全局函数，正在访问："<<building->m_SittingRoom<<endl;

	cout<<"好友全局函数，正在访问："<<building->m_BedRoom<<endl;
}

void test01()
{
	Building building;
	goodGay(&building);
}


int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
