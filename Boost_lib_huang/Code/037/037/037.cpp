#include<boost/foreach.hpp>
using  namespace  boost; //名字空间


#include<iostream>
using namespace std;

#include<vector>


int main()
{ 
	
	//C++的循环
	int  arr[5] = {1,2,3,4,5};
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] <<"     ";
	}
	cout << endl;

	//C++ 11提供更简洁的写法
	for (int &e : arr)
	{
		cout << e<< "     ";
	}
	cout << endl;


	//使用BOOST_FOREACH循环
	BOOST_FOREACH(auto & e, arr) //逗号分隔
	{
		cout << e << "     ";
	}
	cout << endl;


	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//for(vector<int>::iterator  it= v.begin(); it!= v.end(); ++it)
	BOOST_FOREACH(auto & e, v) //逗号分隔
	{
		cout << e << "     ";
	}
	cout << endl;

	//倒序循环
	BOOST_REVERSE_FOREACH(auto & e, v) //逗号分隔
	{
		cout << e << "     ";
	}
	cout << endl;



	return 0;
}
