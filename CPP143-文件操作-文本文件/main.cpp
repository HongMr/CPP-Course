#include <iostream>
//1.ofstream :写操作
//2.ifstream:读操作
//3.fstream:读写文件
#include <string>
#include <fstream>
using namespace std;

void test01()
{
	//1.包含头文件fstream

	//2.创建流对象
	ofstream ofs;

	//3.指定打开方式
	ofs.open("test.txt",ios::out);

	//4.写内容
	ofs<<"姓名：张三"<<endl;
	ofs<<"性别：男"<<endl;
	ofs.close();
	
}

//读文件
void test02()
{
	//创建流对象
	ifstream ifs;
	
	ifs.open("test.txt",ios::in);

	if(!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
		return ;
	}

	//4.读数据
	//第一种方法：
#if 0
	char buf[1024] = {0};
	while(ifs >> buf)//一行一行的读取到buf中
	{
		cout<<buf<<endl;
	}
	
#endif
#if 0
	//第二种
	char buf[1024] = {0};
	while(ifs.getline(buf,sizeof(buf)))
	{
		cout<<buf<<endl;
	}

	
#endif

#if 0

	//第三种
	string buf;
	while(getline(ifs,buf))
	{
		cout<<buf<<endl;
	}
#endif

	//第四种
	char c;
	while((c = ifs.get()) != EOF)//EOF: end of file
	{	
		cout<<c;
	}
	cout<<endl;
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
