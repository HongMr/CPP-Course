#include<iostream>
#include<stack>
using namespace std;

void test01()
{
	stack<int> intStack;//空栈
	//填满栈
	for(size_t ix = 0; ix != 10;++ix)
		intStack.push(ix);//intStack 保存0到9十个数

	while(!intStack.empty()) //intStack中有值就继续循环
	{
		int value = intStack.top();
		cout<<"value: "<<value<<endl;
		//使用栈顶值的代码
		intStack.pop();//弹出栈顶元素，继续循环,pop删除栈顶元素
		
	}
}
int main()
{
	test01();
	return 0;
}
