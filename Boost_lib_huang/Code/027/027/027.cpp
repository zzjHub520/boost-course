//
//#include<iostream>
//using namespace std;   
// 
//#include<boost/array.hpp> 
//using namespace  boost;
// 
//
//int main()
//{ 
// 
//	boost::array<int, 6> arr = {1,2,3,4};
//
//	//数组的大小
//	cout << arr.size() << endl;
//   
//    //下标访问
//	cout << arr[5] << endl;
//	cout << arr.at(4) << endl;
//
//	//[] 与  at的区别在于 是否抛出异常
//	try
//	{
//		//arr[100] = 100;
//		arr.at(100) = 100;
//	}
//	catch (const std::out_of_range  & e)
//	{
//		cout <<"抛出异常"<< e.what() << endl;
//	}
//
//
//	//第一个和最后一个
//	cout << arr.front() <<" , "<< arr.back() << endl;
//
//	//与算法搭配使用
//	copy(arr.cbegin(), arr.cend(), ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	//获取原始的数组
//	int  *pOrgin= arr.data();
//	cout <<pOrgin[3] << endl;
//
//    return 0;
//}
