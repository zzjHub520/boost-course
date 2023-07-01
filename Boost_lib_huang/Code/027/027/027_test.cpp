
#include<iostream>
using namespace std;

#include<boost/array.hpp> 
#include<boost/timer/timer.hpp>
using namespace  boost;
using namespace  boost::timer;

#include<vector>

//���� ��ͨ���飬boost::array , std::vector

const  int N = 10000;

template< typename T>
void   Work(T   arr)
{ 
	for (size_t i = 0; i < N; i++)
	for (size_t j= 0; j< N; j++)
	{
		arr[i] = arr[j];
	}
}


int main()
{
	 
	//��ͨ����
	{
		int  arr[N] = {0};
		auto_cpu_timer  t(6, "��ͨ��������ʱ��%w\n");
		Work<int[]>(arr);
	}


	//boost::array
	{
		boost::array<int,N> arr= { 0 };
		auto_cpu_timer  t(6, "boost::array����ʱ��%w\n");
		Work<boost::array<int,N>>(arr);
	}

	//std::vector
	{
		vector<int> arr;
		arr.resize(N);
		auto_cpu_timer  t(6, "std::vector����ʱ��%w\n");
		Work<vector<int>>(arr);
	}
 

	return 0;
}
