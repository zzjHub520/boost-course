#include<boost/property_tree/ptree.hpp> 
#include<boost/property_tree/xml_parser.hpp>
using namespace  boost::property_tree; //名字空间

#include<iostream>
using namespace std;

int main()
{ 
	try
	{

		//定义  basic_ptree<std::string, std::string> 的对象
		ptree  pt;

		//读取xml文件
		xml_parser::read_xml("test.xml", pt);

		//写入xml文件
		//write_xml

		//解析xml
		cout << "姓名：" << pt.get<string>("stu.name") << endl;
		cout << "年龄：" << pt.get<int>("stu.age") << endl;
		cout << "平均分：" << pt.get<float>("stu.score") << endl;

		//获取节点属性
		cout << "学号：" << pt.get<string>("stu.name.<xmlattr>.id") << endl;


		//找不到节点，输出默认值
		cout << "性别：" << pt.get<string>("stu.sex","保密") << endl;

		//节点里面的内容不是数据，而是节点
		auto  pt2=pt.get_child("stu.lesson");
		for (auto it = pt2.begin(); it != pt2.end(); ++it)
		{
			cout << it->first.data() << "->" << it->second.data() << endl;
		}
	 

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}


	return 0;
}
