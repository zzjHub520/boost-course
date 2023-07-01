#pragma once
#include<iostream>
using namespace std;
/*
//��Ķ����ʵ�ַŵ�ͬһ�ļ���
class  A
{
public :
	A(int  a);
	void  Print();
private:
	int  a;
};


A::A(int  a)
{
	this->a = a;
}


void  A::Print()
{
	cout << a << endl;
}


*/


//��Ķ����ʵ�ַŵ�ͬһ�ļ���
template <typename T>
class  A
{
public:
	A(T  a);
	void  Print();
private:
	T  a;
};


template <typename T>
A<T>::A(T  a)
{
	this->a = a;
}

template <typename T>
void  A<T>::Print()
{
	cout << a << endl;
}
