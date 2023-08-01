#include <iostream>
#include <memory>

using namespace std;

void test01()
{
	shared_ptr<int> p = make_shared<int>(32);
	cout<<"p addr: "<<p<<"  *p = "<<*p<<endl;

	auto q(p);

	cout<<"q addr: "<<q<<"  *q = "<<*q<<endl;
}

int main(int argc, char **argv)
{
	test01();
	return 0;
}
