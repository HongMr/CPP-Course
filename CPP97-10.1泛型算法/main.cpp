#include <iostream>
#include <iterator> //begin和end函数定义在iterator文件中
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void test01()
{
	int ia[] = {27,210,47,12,109,83};
	int val = 83;
	int *result = find(begin(ia),end(ia),val);
	cout<< "result= "<<result<<"  *result = "<<*result<<endl;
	cout<<"end(ia) = "<<end(ia)<<"  *end(ia) = "<<*end(ia)<<endl;

	//从ia[1]开始，直至（但不包含）ia[4]的范围内查找元素
	auto aresult = find(ia+1,ia+4,val);
	cout <<"aresult:"<<aresult<<" *aresult"<<*aresult<<endl;
	cout <<"ia+4:"<<ia+4<<"  ia[4]"<<*(ia+4)<<endl;
}


void test02()
{
	int ia[] = {0,1,2,3,4,5,-10,6,7,8};
	int *beg = begin(ia); //begin函数返回指向ia首元素的指针，end函数返回指向ia尾元素下一位置的指针。
	int *last = end(ia);

}


void test03()
{
	vector<int> vec;
	for(int i = 0;i < 10; i++)
		vec.push_back(i);

	int sum = accumulate(vec.cbegin(),vec.cend(),0);
	cout<<"sum = "<<sum <<endl;
}

void test04()
{
	vector<string> v;
	v.push_back("hello");
	v.push_back("world");

	string sum = accumulate(v.cbegin(),v.cend(),string(""));
	cout<<"sum = "<<sum <<endl;
}
int main()
{	
	test04();
	return 0;
}
