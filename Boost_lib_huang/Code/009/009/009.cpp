// 008.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace std;   
 
#include<boost/typeof/typeof.hpp>

int main()
{ 
	//C++ 11的自动类型推导

	auto   a = 100;//通过变量的值推导类型
	cout << typeid(a).name() << endl;

	auto  b=1.234f;
	cout << typeid(b).name() << endl;


	decltype(a++)  c;
	cout <<a<< typeid(c).name() << endl;

	decltype( &c )  d;
	cout <<typeid(d).name() << endl;


	//boost宏
	BOOST_TYPEOF(1.234 + 100)   e; //和decltype类似
	cout << typeid(e).name() << endl; 


	BOOST_AUTO(f, "sfddsf"); //是利用BOOST_TYPEOF定义变量   + 初始化
	cout << f<<typeid(f).name() << endl;

	BOOST_AUTO(g, 123);
	cout << g<< typeid(g).name() << endl;



	for (BOOST_AUTO(i, 0); i < 10; ++i)
  //	for ( int i= 0;			  i < 10; ++i)
	{
		cout << i << endl;
	}


    return 0;
}

