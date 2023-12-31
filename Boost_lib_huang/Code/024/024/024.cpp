
#include<iostream>
using namespace std;   
 
#include<boost/noncopyable.hpp>
using namespace  boost;


//class  A
//{
//public:
//	A()  { 	cout << "构造A类对象！" << endl; }
//	~A( )  { 	cout << "析构A类对象！" << endl; } 
//
//private: //技巧，避免类对象的拷贝与赋值
//	A(const  A  &a) { cout << "拷贝构造A类对象！" << endl; };//拷贝构造函数
//	A  &  operator = (const A  &a) //赋值函数
//	{   
//		cout << "赋值A类对象！" << endl;  
//		return  *this;
//	};
//
//};


class  A: public  noncopyable //轻松的禁止类的对象拷贝与赋值
{
public:
	A() { cout << "构造A类对象！" << endl; }
	~A() { cout << "析构A类对象！" << endl; } 
};



int main()
{ 
	
	A  a;

	A  a2(a);

	A  a3 = a;//调用的依然是拷贝构造

	A  a4;
	a4 = a; //调用的才是= 赋值


    return 0;
}
