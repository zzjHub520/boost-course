#include<iostream>
using namespace std;   
   
#include<boost/date_time/gregorian/gregorian.hpp>
using namespace  boost::gregorian;

#pragma  comment(lib, "libboost_date_time-vc141-mt-gd-x32-1_67.lib")

int  main()
{ 
	 //构造日期
	date   d1(2000, 1, 1);
	date   d2 = from_string("2010-02-02");
	date   d3 = from_string("2010/03/03");
	date   d4 = from_undelimited_string("20100404");//无界定的字符串

	date  d5(min_date_time);//特殊时间值1400-01-01
	date  d6(max_date_time);//特殊时间值9999-12-31

	//输出日期
	cout << d1.year() << "年" <<(int) d1.month() << "月" << d1.day() << endl;
	cout << to_simple_string(d2) << endl;//2010-Feb-02
	cout << to_iso_string(d3) << endl;//20100303
	cout << to_iso_extended_string(d4) << endl;//2010-03-03
	cout << to_iso_string(d5) << endl;
	cout << to_iso_string(d6) << endl;

	//获取今天的日期
	date  today = day_clock::local_day();

	cout << "年"<< today.year() << endl;
	cout << "月"<< today.month() << endl;
	cout << "日"<< today.day() << endl;
	cout <<"星期"<< today.day_of_week() << endl; 
	cout << "一年中的第几周" << today.week_number() << endl;
	cout << "一年中的第多少天" << today.day_of_year() << endl;
	cout << "这个月的结束日期" << today.end_of_month() << endl;

	//时间长度(最小单位是 天)
	days  day1(10);
	days  day2(-5);
	date_duration  du1  = day1 + day2;
	cout <<"10天-5天"<< du1.days() << endl;

	weeks  w1(1);
	cout << "1周的天数" << w1.days() << endl;
	date_duration  du2 = w1 + day1;
	cout << "1周+ 10天" << du2.days() << endl;

	months   mon1(1);//一个月无法知道是多少天 ，并且无法加天数
	cout << "1个月" << mon1.number_of_months() << endl;

	years  year1(1);//一年无法知道是多少天，并且无法加天数
	cout << "1年" << year1.number_of_years()<< endl;

	//如何知道一年多少个月
	months mon2= year1 + months(0);
	cout << "1年多少个月" << mon2.number_of_months() << endl;


	//日期+  日期长度 = 新日期 ，很实用
	date   d10(2018, 1, 31);

	cout << "今天往前推10天是几月几日:" ;
	cout <<  to_iso_extended_string(  d10 + days(-10) ) << endl;

	cout << "今天往后加2周是几月几日:";
	cout << to_iso_extended_string(d10 + weeks(2)) << endl;

	cout << "今天往后推一个月是几月几日:";
	cout << to_iso_extended_string(d10 + months(1)) << endl;

	cout << "今天往后推一年月是几月几日:";
	cout << to_iso_extended_string(d10 + years(1)) << endl;

    return 0;
}

