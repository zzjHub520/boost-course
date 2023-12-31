// 004.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace  std;

//包含头文件
#include<boost/lexical_cast.hpp>


int main()
{
	/*
	//字符串转整数
	int  a = atoi("123");
	cout << a << endl;

	//整数转字符串
	char b[64] = {0};
	itoa(16, b, 2);
	cout << b << endl;

	//字符串转浮点数
	double  c = atof("1.23456");
	cout << c << endl;

	//浮点数转字符串
	char d[64] = { 0 };
	gcvt(1.23456, 4, d);//四舍五入
	cout << d<< endl;
	*/

	using   boost::lexical_cast;//声明，省略boost名字空间前缀
	using   boost::bad_lexical_cast;
	try
	{
		//字符串转整型
		//int  a = lexical_cast<int>("123");
		int  a = lexical_cast<int>("123efd", 3);
		cout << a << endl;

		//字符串 转 浮点型
		float  b = lexical_cast<float>("1.23456");
		cout << b << endl;

		//浮点数转为字符串
		string   c = lexical_cast<string>("1.23456");
		cout << c << endl;

		//浮点数转为字符串
		string   d = lexical_cast<string>("666");
		cout << d << endl;
	}
	//catch (const std::exception&  e)
	catch (const bad_lexical_cast &  e)
	{
		cout << e.what() << endl;
	}
	





    return 0;
}

