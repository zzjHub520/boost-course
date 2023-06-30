//#include <iostream>
//#include <boost/date_time/gregorian/gregorian.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
//using namespace std;
//using namespace boost::gregorian;
//using namespace boost::posix_time;
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    date d1(2000, 1, 1);
//    date d2 = from_string("2010-02-02");
//    date d3 = from_string("2010/03/03");
//    date d4 = from_undelimited_string("20100404");
//    date d5(min_date_time);
//    date d6(max_date_time);
//    cout << d1.year() << "year" << d1.month() << "month" << d1.day() << endl;
//    cout << to_simple_string(d2) << endl;
//    cout << to_iso_string(d3) << endl;
//    cout << to_iso_extended_string(d4) << endl;
//    cout << to_iso_string(d5) << endl;
//    cout << to_iso_string(d6) << endl;
//
//    date today=day_clock::local_day();
//    cout <<today.year()<<endl;
//    cout <<today.month()<<endl;
//    cout <<today.day()<<endl;
//    cout <<today.week_number()<<endl;
//    cout <<today.day_of_week()<<endl;
//    cout <<today.day_of_year()<<endl;
//    cout <<today.end_of_month()<<endl;
//
//    days day1(10);
//    days day2(-5);
//    date_duration du1=day1+day2;
//
//    ptime t1= time_from_string("2000-01-12 10:32:02");
//
//    return 0;
//}



#include <boost/filesystem.hpp>
#include <iostream>

namespace fs = boost::filesystem;

int main() {
    // 指定要遍历的目录
    fs::path directory_path("/path/to/directory");

    // 检查目录是否存在
    if (!fs::exists(directory_path)) {
        std::cout << "目录不存在！" << std::endl;
        return 1;
    }

    // 遍历目录中的所有文件和子目录
    for (const auto& entry : fs::directory_iterator(directory_path)) {
        // 判断是否为目录
        if (fs::is_directory(entry)) {
            std::cout << "目录: " << entry.path() << std::endl;
        } else if (fs::is_regular_file(entry)) {
            // 获取文件大小
            std::cout << "文件: " << entry.path() << " (大小: " << fs::file_size(entry) << " bytes)" << std::endl;
        }
    }

    return 0;
}



