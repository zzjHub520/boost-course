#include<iostream>
using namespace std;   
 
#include<boost/shared_array.hpp>
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
	A  * pArr = new A[5];//pArr是数组指针

	//错误
	//boost::shared_ptr<A>  p1(pArr);//delete 不能释放 数组内存指针，应该用delete[]


	boost::shared_array<A>  p1(pArr);//适合数组内存指针
	cout << p1.unique() << "  ,  " << p1.use_count() << endl;

	boost::shared_array<A>  p2(p1);
	cout << p2.unique() << "  ,  " << p2.use_count() << endl;

	//支持[]运算符，像使用数组名一样
	for (int i = 0; i < 5; ++i) 	p1[i].m_a = i;

	cout << p2[3].m_a << endl;//使用索引访问

    return 0;
}

