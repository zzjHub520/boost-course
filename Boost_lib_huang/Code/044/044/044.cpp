#include<boost/thread.hpp>
using  namespace  boost; //名字空间

#include<iostream>
using namespace std;
 
//要想运行，需要libboost_thread-vc141-mt-gd-x32-1_67.lib，附加库目录

//mutex  m;//普通mutex加锁两次会死锁

recursive_mutex  m;//递归mutex， 可以多次加锁，防止死锁，必须相应多次解锁


void  ThreadFun1()
{
	m.lock();//第一次加锁
	cout << "ThreadFun1第一次加锁!" << endl;

	m.lock();//第二次加锁
	cout << "ThreadFun1第二次加锁!" << endl;

	m.unlock();
	cout << "ThreadFun1第一次解锁!" << endl;

	this_thread::sleep(posix_time::seconds(8));//睡眠8秒后第二次解锁

	m.unlock();
	cout << "ThreadFun1第二次解锁!" << endl;
}
  

void  ThreadFun2()
{
	this_thread::sleep(posix_time::seconds(1));//保证在线程1后面执行
	bool  b=m.try_lock();//不阻塞加锁 ，加锁成功返回1，加锁失败返回0
	cout << "ThreadFun2加锁是否成功:" << b << endl;
	m.unlock();
}


int main()
{  

	//同时执行
	thread  t1(ThreadFun1); 
	thread  t2(ThreadFun2);

	t1.join();
	t2.join();

	return 0;
}
