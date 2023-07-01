#include<iostream>
using namespace std;

#include<boost/circular_buffer.hpp> 
#include<boost/timer/timer.hpp>
using namespace  boost;
using namespace  boost::timer;

int main()
{
	//环形缓存（特别像队列）
	circular_buffer<int>  cb(3);//容量为3

	 cb.push_back(1);//从尾部插入
	 cb.push_back(2);//
	 cb.push_back(3);//容量已满

	 //cb.push_front(1);//从头插入
	 //cb.push_front(2);//
	 //cb.push_front(3);//容量已满

	for (int i = 0; i < cb.size(); ++i) 	cout << cb[i] << "   ";
	cout << endl;


	//容量已满，尾部插入，踢出头部元素
	cb.push_back(4);
	for (int i = 0; i < cb.size(); ++i) 	cout << cb[i] << "   ";
	cout << endl;

	//容量已满，头部插入，踢出尾部元素
	cb.push_front(5);
	for (int i = 0; i < cb.size(); ++i) 	cout << cb[i] << "   ";
	cout << endl;

	cb.pop_back();//删除尾部的元素
	for (int i = 0; i < cb.size(); ++i) 	cout << cb[i] << "   ";
	cout << endl;

	cb.pop_front();//删除头部的元素
	for (int i = 0; i < cb.size(); ++i) 	cout << cb[i] << "   ";
	cout << endl;

	return 0;
}
