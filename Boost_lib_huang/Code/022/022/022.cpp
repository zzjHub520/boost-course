#include<iostream>
using namespace std;   
 
#include<boost/weak_ptr.hpp>
#include<boost/shared_ptr.hpp>
using namespace  boost;


class  A
{
public:
	A()  	
	{
		cout << "构造A类对象！" << endl;
	}
	~A( )  
	{
		cout << "析构A类对象！" << endl;
	} 
	int m_a; 
};


int main()
{ 
 
	boost::shared_ptr<A>  p1(new  A);// 引用计数+1
	cout << p1.unique() << " , " << p1.use_count() << endl;

	//weak_ptr是 shared_ptr的协助者，或者是一个配角，主要用于观察
	boost::weak_ptr<A>  p2(p1);//不改变引用计数
	cout << p1.unique() << " , " << p1.use_count() << endl;
	cout << p2.expired()/*用于观察shared_ptr指向的内存是否释放 */ << " , " << p2.use_count() << endl;


	//weak_ptr不管理这块内存
	//p2->m_a;//错误的
	//*p2.m_a = 100;//错误的


	boost::shared_ptr<A>  p3(p1);// 引用计数+1
	boost::shared_ptr<A>  p4(p3);// 引用计数+1

	//用weak_ptr来观察一下
	cout << p2.expired()<< " , " << p2.use_count() << endl;


	p1.reset();	 //释放管理权 ， 引用计数-1
	p3.reset();	 //释放管理权 ， 引用计数-1
	p4.reset();	 //释放管理权 ， 引用计数-1，此刻内存释放

	cout << p2.expired() /* 返回1表示内存已经释放*/<< " , " << p2.use_count() << endl;


    return 0;
}

