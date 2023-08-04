#include <iostream>
using namespace std;

//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择
//测试 char数组 int数组

//交换函数模板
template<class T>
void mySwap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}


//排序算法
template<class T>
void mySort(T arr[],int len)
{
	for(int i = 0;i < len;i++)
	{
		int max = i;//认定最大值的下标
		for(int j = i+1;j < len ;j++)
		{
			if(arr[max] < arr[j])
			{
				max = j;//更新最大值下标
			}
		}

		if(max != i)
		{
			mySwap(arr[max],arr[i]);
		}
	}
}
//提供打印数组模板
template<class T>
void printArray(T arr[],int len)
{
	for(int i = 0;i <len;i++)
	{
		cout<<arr[i]<<endl;
	}
}

void test01()
{
	//测试char数组
	char charArr[] = "badcfe";
	int len = sizeof(charArr)/sizeof(char);
	mySort(charArr,len);
	printArray(charArr,len);
}
void test02()
{
	//测试int数组
	int intArr[] = {1,3,2,5,8,4};
	int len = sizeof(intArr)/sizeof(int);

	mySort(intArr,len);
	printArray(intArr,len);
	
}
int main(int argc, char **argv)
{
	//cmd需要显示gbk,把utf8转成gbk
	system("chcp 65001");

	test01();
	test02();

	return 0;
}
