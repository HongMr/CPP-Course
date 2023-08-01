#include <iostream>
#include <map>
#include <set>

using namespace std;

void test01()
{
	//统计每个单词在输入中出现的次数
	map<string,size_t> word_count;  //string 到size_t的空map

	set<string> exclude = {"The","But","And"};
	
	string word;
	int count = 0;
	while(cin >> word)
	{
		//只统计不再exclude中的单词
		if (exclude.find(word) == exclude.end())
			++word_count[word];
		
		++count;
		if(count>=5) 
		break;
	}

	for(const auto &w : word_count) //对map中每个元素
	{
		cout<<w.first <<" occurs "<<w.second
			<<((w.second > 1) ? " times":" time")<<endl;
	}
}

int main()
{
	test01();
	return 0;
}
