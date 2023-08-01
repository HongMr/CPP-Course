#include <iostream>

//拷贝构造函数
using namespace std;


class Foo{
public:
	Foo(){
		cout<<"moren gouzao"<<endl;
	};//默认构造函数
	
	Foo(const Foo &){
	 	cout<<"kao bei gou zao"<<endl;
	};

};

void test01()
{
	Foo f1;

	Foo f2(f1);//拷贝构造函数
}

void test02()
{
	//拷贝初始化
	string dots(10,'.');//直接初始化，普通构造
	cout<<"pu tong gou zao dots:"<<dots<<endl;

	string s(dots);//直接初始化，也算拷贝构造函数
	cout <<"kao be gouzao hanshu s:"<<s<<endl;
	
}
int main()
{
	test02();
	return 0;
}
