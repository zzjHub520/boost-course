#include<boost/random.hpp>
using  namespace  boost; //名字空间

#include<iostream>
using namespace std;

int main()
{ 
	//mt19937  马特赛特旋转演算法,适用于很多场景
	mt19937 mt(time(0));
	cout << "随机数范围" << mt.min() << "~" << mt.max() << endl;

	for(int i=0;i<5;++i)
	{
		cout << mt()<< "  ,   ";
		//想生成0-1之间的随机数
		//cout << mt() *1.0 / 10000000000<< "  ,   ";
	}
	cout <<endl;

	//rand48, LCG线性同余算法
	rand48   r48;
	cout << "随机数范围" << r48.min() << "~" << r48.max() << endl;

	for (int i = 0; i<5; ++i)
	{
		cout << r48() << "  ,   ";
	}
	cout << endl;

	//小数特定分布0 -1
	uniform_01<mt19937&>  u01(mt);
	for (int i = 0; i<5; ++i)
	{
		cout << u01() << "  ,   ";
	}
	cout << endl;

	//整数特定分布 0-100
	uniform_int<>  ui;
	for (int i = 0; i<5; ++i)
	{
		cout << ui(r48) << "  ,   ";
	}

	return 0;
}
