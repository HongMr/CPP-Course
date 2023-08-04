#include <iostream>
//1.ofstream :写操作
//2.ifstream:读操作
//3.fstream:读写文件
#include <string>
#include <fstream>
using namespace std;

//二进制文件 写文件
class Person
{
public:
	char m_Name[64];

	int m_Age;
};

//write
void test01()
{
	//1.包含头文件<fstream>

	//2.创建流对象
	//ofstream ofs;
	ofstream ofs("person.txt",ios::out|ios::binary);
	//3.打开文件
	//ofs.open("person.txt",ios::out|ios::binary);
	
	//4.写文件
	Person p = {"张三",18};
	ofs.write((const char *)&p,sizeof(Person));
	//5.关闭文件
	ofs.close();
}

void test02()
{
	//1.包含头文件<fstream>

	//2.创建流对象
	//ofstream ifs;
	ifstream ifs("person.txt",ios::in|ios::binary);

	if (!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
		return ;
	}
	
	//3.打开文件
	//ifs.open("person.txt",ios::out|ios::binary);
	
	//4.读文件
	Person p ;
	ifs.read((char *)&p,sizeof(Person));

	cout<<"姓名："<<p.m_Name<<" 年龄："<<p.m_Age<<endl;
	//5.关闭文件
	ifs.close();

}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	test02();
	return 0;
}
