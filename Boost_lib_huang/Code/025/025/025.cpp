
#include<iostream>
using namespace std;   
 
#include<boost/timer.hpp>
#include<boost/progress.hpp>

using namespace  boost;

#include<Windows.h>


int main()
{ 

	timer t;

	//cout << "最大精度：" << t.elapsed_max() / 3600 <<"小时"<< endl;

	//cout << "最小精度：" << t.elapsed_min() << endl;//毫秒

	Sleep(1234);//睡眠1234毫秒

	double  elapsed = t.elapsed();

	//从对象定义到此刻的时间
	cout << "流逝的时间：" << elapsed << endl;


	cout << "------------------------------" << endl;
	

	{
		progress_timer  pt; //继承至timer
		//progress_timer  pt2(pt); //noncopyable
		
		Sleep(2345);//睡眠2345毫秒

	}//析构时，自动打印消耗时间

    return 0;
}
