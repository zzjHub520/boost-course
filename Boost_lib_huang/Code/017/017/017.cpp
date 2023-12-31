
#include<iostream>
using namespace std;   
 
#include<boost/scoped_array.hpp>
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
	//注意，scoped_ptr不能接受数组指针
	//scoped_ptr<A>  p1(new A[5]);//传入对象数组指针
	 
	//C++中的new 与delete需要注意的
	/*
	A  *pA = new  A;
	delete  pA;

	A *pArr = new A[5]; 
	pArr[0].m_a = 100;//当成数组名一样使用 

	(pArr + 3)->m_a = 300;//直接加上整数，表示第4个对象的地址

	delete  []pArr; //删除数组指针
	*/


	//指向数组内存地址的智能指针
	scoped_array<A>   p2(new  A[5]);

	for (int i = 0; i < 5; ++i)
	p2[i].m_a = i;  //支持[]访问，把p2当做数组名

	cout << p2[4].m_a << endl;//用索引访问

	//(p2 + 3)->m_a=300;//不支持


    return 0;
}

