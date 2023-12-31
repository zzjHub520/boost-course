#include<iostream>
using namespace std;   
 
#include<boost/make_shared.hpp>
using namespace  boost;


class  A
{
public:
	A(int _a ,float _b, char _c ,string _d)  	
	{
		 a=_a ; b = _b; c = _c; d = _d;
		cout << "构造A类对象！" << endl;
	}
	~A( )  
	{
		cout << "析构A类对象！" << endl;
	} 
	int a; 
	float b; 
	char c; 
	string d;
};


int main()
{ 

	//原始的方式构造shared_ptr，需要new，产生一种不对称性
	boost::shared_ptr<A>  p1(new A(100, 1.234f, 'C', "hello"));
	cout << p1->a << ", " << p1->b << ", " << p1->c<< ", " << p1->d << endl;


	//推荐使用工厂函数，屏蔽new ,更高效
	boost::shared_ptr<A>  p2  =  boost::make_shared<A>(100, 1.234f, 'C', "hello");
	cout << p2->a << ", " << p2->b << ", " << p2->c << ", " << p2->d << endl;



    return 0;
}

