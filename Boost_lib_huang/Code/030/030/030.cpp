
#include<iostream>
using namespace std;

#include<boost/unordered_map.hpp> 
#include<boost/timer/timer.hpp>
#include<boost/format.hpp>
using namespace  boost;
using namespace  boost::timer;

#include<map> 

int main()
{
	 
	//与STL   map相似，key是唯一的，value可以重复，区别是无序的
	unordered_map<int ,string>  um;

	um.insert( make_pair(1, "AAA"));
	um.insert(make_pair(1, "AAAAAA"));//重复的key无法插入
	um[3]; //竟然是插入了一个key为2的键值对， value为默认值""
	um[2] = "BBB";//插入  key为2，value为BBB的键值对

	cout << um.size() << endl;

	auto  itt  = um.find( 2);//根据key查找
	if (itt != um.end())
	{
		cout << itt->first  <<"->" << itt->second << endl;
	}

	um[3] = "CCC";//这里可以修改value值

	//遍历,元素是无序的
	for (auto it = um.begin(); it != um.end(); ++it)
	{
		cout << it->first << "->" << it->second << endl;
	}


	cout << endl;
	cout << "--------------测试性能---------------" << endl;

	unordered_map<int,string>  um2;
	map<int, string>  m2;

	for (int i = 0; i < 100000; ++i)
	{
		boost::format fmt("%1%");
		fmt%i;
		um2.insert(make_pair(i, fmt.str())); 
		m2.insert(make_pair(i, fmt.str()));
	}

	{//查找性能更好
		auto_cpu_timer  t(6, "unordered_map消耗时间%w\n");
		for (size_t i = 0; i < 100000; i++)
		{
			auto ret = um2.find(i);
		} 
	}


	{
		auto_cpu_timer  t(6, "map消耗时间%w\n");
		for (size_t i = 0; i < 100000; i++)
		{
			auto ret = m2.find(i);
		}
	}

	return 0;
}
