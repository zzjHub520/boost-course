#include<boost/thread.hpp>
using  namespace  boost; //名字空间

#include<iostream>
using namespace std;
 
//要想运行，需要libboost_thread-vc141-mt-gd-x32-1_67.lib，附加库目录

void  ThreadFun(string  & threadName)
{
	for (size_t i = 0; i < 5; i++)
	{
		printf("%s 执行！\n", threadName.c_str());

		//线程睡眠
		 this_thread::sleep(posix_time::seconds(1));
	}
}

int main()
{ 
	//定义线程对象,线程执行函数，函数参数，构造
	thread  t1(ThreadFun, string("线程1"));//立即运行
	 
	thread  t2(ThreadFun, string("线程2"));//立即运行

	//t1.join();//先阻塞，等待子线程执行完毕后返回
	//t2.join();//先阻塞，等待子线程执行完毕后返回

	//如果线程还没结束，最多等待3秒
	t1.timed_join(posix_time::seconds(8));


	cout << "main结束!" << endl;

	return 0;
}
