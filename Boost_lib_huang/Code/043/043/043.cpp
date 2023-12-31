#include<boost/thread.hpp>
using  namespace  boost; //名字空间

#include<iostream>
using namespace std;
 
//要想运行，需要libboost_thread-vc141-mt-gd-x32-1_67.lib，附加库目录


//try_mutex  m;//try_mutex 等价于 typedef mutex try_mutex;

//超时返回的mutex
timed_mutex  tmu;

void  ThreadFun1()
{
	tmu.lock();
	printf("ThreadFun1先锁住8秒！\n" );
	this_thread::sleep(posix_time::seconds(8)); 
	tmu.unlock();
	printf("ThreadFun1解锁！\n"); 
}



void  ThreadFun2()
{
	//尝试锁住mutex，如果有其他线程锁住，最多阻塞3秒然后返回0 
	this_thread::sleep(posix_time::seconds(1));
	printf("ThreadFun2尝试加锁！\n");
	bool  bLock = tmu.try_lock_for(chrono::seconds(3));//第3秒时，线程1仍然锁着，所以线程2无法加锁，返回0
	//bool  bLock=tmu.try_lock_for(chrono::seconds(10)); //第10秒时，线程1已经解锁，所以线程2可以加锁，返回1
	cout << "ThreadFun2加锁是否成功：" << bLock << endl;
	tmu.unlock(); 
}

int main()
{ 
	thread  t1(ThreadFun1);
	thread  t2(ThreadFun2);

	t1.join();
	t2.join();

	return 0;
}
