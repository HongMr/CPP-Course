#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
	int m_Age;
};

//利用虚继承，解决菱形继承问题

//羊类
class Sheep :virtual public Animal
{

};


//驼类
class Tuo:virtual public Animal
{

};
//羊驼
class SheepTuo:public Sheep, public Tuo
{

};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承，两个父类拥有相同数据 需要加以作用域区分
	cout<<"st.Sheep::m_Age = "<<st.Sheep::m_Age<<endl;
	cout<<"st.Tuo::m_Age = "<<st.Tuo::m_Age<<endl;
	

	//这份数据我们知道，只有一份就可以，菱形
	cout<<"st.m_Age = "<<st.m_Age<<endl;
}

int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	
	return 0;
}
