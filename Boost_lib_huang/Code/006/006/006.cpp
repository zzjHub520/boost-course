// 006.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace  std;

//string_algo库的头文件
#include<boost/algorithm/string.hpp>
using  namespace  boost;//名字空间

int main()
{
	//大小写转换 
	cout << "大小写转换" << endl;
	string  str1 = "abc";
	to_upper(str1);//改变原字符串
	cout << str1 << endl;
   
	to_lower(str1);//改变原字符串
	cout << str1 << endl;
	 
	string  str2=to_upper_copy(str1);//不改变原字符串
	cout << str1 << endl;
	cout << str2 << endl;
	 
	//判断式，返回bool
	cout << "判断式" << endl;
	cout << starts_with("Hello World", "He") << endl;//大小写敏感
	cout << starts_with("Hello World", "he") << endl;
	cout << istarts_with("Hello World", "he") << endl;//i忽略大小写

	cout << ends_with("Hello World", "ld") << endl;//大小写敏感 
	cout << iends_with("Hello World", "Ld") << endl;//i忽略大小写

	cout << contains("Hello World", "llo") << endl;//大小写敏感 
	cout << icontains("Hello World", "LLo") << endl;//i忽略大小写

	cout << equals("abc", "abc") << endl;//内容是否相等
	cout << iequals("abc", "Abc") << endl;//内容是否相等,i忽略大小写

	cout << all("Hello", is_lower()) << endl;//判断每一个字符是否全部是小写
	cout << all("hello", is_lower()) << endl;//判断每一个字符是否全部是小写

	cout <<  lexicographical_compare("zabc","xyz")<< endl;//字典次序第一个是否小于第二个

	cout << "判断式，函数对象" << endl;
	cout << is_equal()("abc", "abc") << endl;//内容是否相等,i忽略大小写
	is_equal  eq; 
	cout << eq("abc", "abc")<< endl;//等价于上面的写法

	cout << is_less()("abc", "zbc") << endl;//内容是否小于
	cout << is_not_greater()("abc", "zbc") << endl;//内容是否不大于


	cout << "分类" << endl;
	cout << is_alnum()('1') << endl;//判断是否是字母或数字
	cout << is_alnum()('a') << endl;
	cout << is_alnum()(',') << endl;

	cout << is_alpha()('A') << endl;//是否字母
	cout << is_digit()('1') << endl;//是否数字
	cout << is_cntrl()('\n') << endl;//是否控制字符
	cout << is_any_of("ABCDE")( 'F' ) << endl;//是否是ABCDE里面的任何一个
	cout << is_xdigit()('Q') << endl;//是否16进制的字符
	cout << is_lower()('a') << endl;//是否小写字符

    return 0;
}

