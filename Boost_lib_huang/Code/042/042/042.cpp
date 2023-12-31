#include<boost/thread.hpp>
using  namespace  boost; //名字空间

#include<iostream>
using namespace std;
 
//要想运行，需要libboost_thread-vc141-mt-gd-x32-1_67.lib，附加库目录


//多个售票窗口同时卖票，总票数100张
int  tickets = 100;


//定义互斥量mutex
mutex   m;

void  SellA()
{
	while (true)
	{
		//this_thread::sleep(posix_time::milliseconds(10));

		m.lock();//保护共享资源同一时刻只有一个线程访问
		if (tickets > 0)
		{
			printf("A窗口卖出第%d张票!\n", tickets);//A，B同时进入
			 --tickets; 
		} 
		m.unlock();
       if(tickets<=0) break; 
		
	}
}

void  SellB()
{
	while (true)
	{
		//this_thread::sleep(posix_time::milliseconds(10));
		m.lock();
		if (tickets > 0)
		{
			printf("B窗口卖出第%d张票!\n", tickets);
			--tickets;
		}
		m.unlock();
		if (tickets <= 0) break;

	}
}
 
int main()
{ 
	thread  ta(SellA);//A线程立即执行
	thread  tb(SellB);//B线程立即执行

	ta.join();//等待线程结束
	tb.join();//等待线程结束

	cout << "票卖光了！" << endl;

	return 0;
}
