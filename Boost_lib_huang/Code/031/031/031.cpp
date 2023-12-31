
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
	 
	//与STL   multimap相似，key可以重复，区别是无序的
	unordered_multimap<int ,string>  um;

	um.insert(make_pair(1, "AAA"));
	um.insert(make_pair(1, "AAAA"));//重复的key可以插入 
	um.insert(make_pair(1, "AAAAAA"));//重复的key可以插入 
	//um[2] = "BBB";//不提供[]运算符，因为同一个key可以对应对个value
	um.insert(make_pair(2, "BBB")); 
	um.insert(make_pair(3, "CCC"));

	cout << um.size() << endl;

	//返回key值为1的个数
	cout << um.count(1) << endl;

	//auto  itt  = um.find(1);//根据key查找第一个
	//if (itt != um.end())
	//{
	//	cout << itt->first  <<"->" << itt->second << endl;
	//}

	//查找所有key为1的
	cout << "------查找所有key为1--------" << endl;
	auto  rge= um.equal_range(1); //返回查找到结果的范围
	for ( auto   it= rge.first 	; it != rge.second; it++)
	{
		cout << it->first << "->" << it->second << endl;
	}

 
	//遍历,元素是无序的
	cout << "------遍历所有--------" << endl;
	for (auto it = um.begin(); it != um.end(); ++it)
	{
		cout << it->first << "->" << it->second << endl;
	}


	 cout << endl;
	 cout << "--------------测试性能---------------" << endl;

	 unordered_multimap<int,string>  um2;
	 multimap<int, string>  m2;

	for (int i = 0; i < 100000; ++i)
	{
		int  elem = i % 10000;
		boost::format fmt("%1%");
		fmt%elem;
		um2.insert(make_pair(elem, fmt.str()));
		m2.insert(make_pair(elem, fmt.str()));
	}

	{//查找性能更好
		auto_cpu_timer  t(6, "unordered_multimap消耗时间%w\n");
		for (size_t i = 0; i < 100000; i++)
		{
			auto ret = um2.find(i);
		} 
	}


	{
		auto_cpu_timer  t(6, "multimap消耗时间%w\n");
		for (size_t i = 0; i < 100000; i++)
		{
			auto ret = m2.find(i);
		}
	}

	return 0;
}
