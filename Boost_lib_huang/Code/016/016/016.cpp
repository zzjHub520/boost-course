
#include<iostream>
using namespace std;   
 
#include<boost/scoped_ptr.hpp>
using namespace  boost;

 
class  A
{
public:
	A(int  _a) : m_a(_a)
	{
		cout << "构造A类对象！" << endl;
	}
	~A( )  
	{
		cout << "析构A类对象！" << endl;
	}
	int  m_a;
};

int main()
{ 
 
	//C++  98的auto_ptr
	auto_ptr<A>  p1(new  A(100));
	cout << p1->m_a << endl;

	//auto_ptr<A>  p2(p1);//调用拷贝构造函数，此时p1失去所有权
	
	auto_ptr<A>  p2;
	p2=p1;//调用赋值函数，此时p1失去所有权

	//p1->m_a = 200;//错误
	cout << p1.get() << endl;//为NULL
	 
	cout << p2->m_a << endl;



	//---------------------------------------------------
	//使用boost的  scoped_ptr

	cout << " ------------boost的  scoped_ptr------------" << endl;

	scoped_ptr<A>  s1(new  A(100)); //不能转让
	s1->m_a = 100;

	//scoped_ptr<A>  s2(s1);//拷贝构造函数是private

	scoped_ptr<A>  s3;
	//s3 = s1;//=运算符重载函数是private



    return 0;
}

