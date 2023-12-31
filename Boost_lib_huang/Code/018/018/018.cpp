
#include<iostream>
using namespace std;   
 
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
	int  m_a;
};

int main()
{ 
	boost::shared_ptr<A>  p1(new A);//引用计数为1
	//此时唯一管理A的内存
	cout << p1.unique() << " ,  " << p1.use_count() << endl;

	//此时， p1,p2同时管理A的内存
	boost::shared_ptr<A>  p2( p1); //拷贝构造，引用计数+1
	cout << p2.unique() << " ,  " << p2.use_count() << endl;

	boost::shared_ptr<A>  p3; 
	p3 = p2;//赋值运算符  引用计数+1
	cout << p1.unique() << " ,  " << p1.use_count() << endl;

	//3个智能指针指向同一地址
	cout << p1.get() << " ,  " << p2.get() << " ,  " << p3.get() << " ,  " << endl;



	//手动分离管理权
	p1.reset();//  引用计数-1
	cout << p2.unique() << " ,  " << p2.use_count() << endl;
	cout << p3.unique() << " ,  " << p3.use_count() << endl;

	p2.reset();//  引用计数-1 
	cout << p3.unique() << " ,  " << p3.use_count() << endl;


	p3.reset();//引用计数-1 ，此时，全部放弃了管理权，A内存就会释放

	cout << "结束！" << endl;

    return 0;
}

