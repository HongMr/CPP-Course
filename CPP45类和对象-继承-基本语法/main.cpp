#include<iostream>
using namespace std;

//普通实现页面

class BasePage
{
public:
	void header()
	{
		cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
	}
	void footer()
	{
		cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
	}
	void left()
	{
		cout<<"Java、Python、C++、...(公共分类列表)"<<endl;
	}

};
//Java页面
class Java:public BasePage
{
public:
	void content()
	{
		cout<<"Java学科视频"<<endl;
	}
};
	
//Python页面
class Python:public BasePage
{
public:
	void content()
	{
		cout<<" Python 学科视频"<<endl;
	}
};

//C++页面
class Cpp:public BasePage
{
public:
	void content()
	{
		cout<<" CPP 学科视频"<<endl;
	}

};
int main()
{
	//解决中文乱码问题
	system("chcp 65001");

	cout << " Java的下载视频界面 " << endl;
	
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout<<"----------------python-------------"<<endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	
	cout<<"----------------CPP-------------"<<endl;
	Cpp c;
	c.header();
	c.footer();
	c.left();
	c.content();
	
	system("pause");

	return 0;
}
