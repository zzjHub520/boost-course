#include<iostream>
using namespace std;

#include<boost/weak_ptr.hpp>
#include<boost/shared_ptr.hpp>
using namespace  boost;


class  A
{
public:
	A()
	{
		cout << "����A�����" << endl;
	}
	~A()
	{
		cout << "����A�����" << endl;
	}
	 
	//boost::shared_ptr<A>  m_a;  
	boost::weak_ptr<A>  m_a; //�������Ϊweak_ptr����ı����ü���
};


int main()
{
	{
	boost::shared_ptr<A>  p1(new  A);//���ü���Ϊ1
	 
	cout << p1.unique() << "," << p1.use_count() << endl;
	 
	//��������ѭ������
	p1->m_a = p1;//   shared_ptr��ֵ����������������+1

	cout << p1.unique() << "," << p1.use_count() << endl;
	} //������ʱ��p1�������ڽ����������������������ü���-1������ע�⣬2-1>0
	  //���� new A����ڴ治�ᱻ�ͷţ� ����m_a��ԱҲ�����ͷţ������͵��������ü���
	//һֱ��Ϊ0�� ��new A������ڴ�й©



	return 0;
}

