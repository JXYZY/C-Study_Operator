// operator.cpp: 定义应用程序的入口点。
//

#include "operator.h"

using namespace std;

Time::Time()
{
	
}

Time::Time(int hour, int minutes)
	:m_hour(hour)
	,m_minutes(minutes)
{

}
Time::~Time()
{

}

Time Time::operator+(const Time& t)
{
	Time total;
	total.m_minutes =m_minutes + t.m_minutes;
	total.m_hour = m_hour + t.m_hour + total.m_minutes / 60;
	total.m_minutes %= 60;
	return total;
}

//友元函数
Time operator*(int cal, const Time& t)
{
	Time result;
	result.m_hour = cal * t.m_hour;
	result.m_minutes = cal * t.m_minutes;
	result.m_hour += result.m_minutes / 60;
	result.m_minutes %= 60;
	return result;
}

int main()
{
	Time t1(5, 25);
	Time t2(2,55);
	Time total = t1 + t2;
	Time total2 = 2 * t2;
	std::cout << "total hour:" << total.getHour() << " " << "total minutes:" << total.getMinutes() << std::endl;
	std::cout << "total2 hour:" << total2.getHour() << " " << "total2 minutes:" << total2.getMinutes() << std::endl;
	cout << "Hello CMake。" << endl;
	getchar();
	return 0;
}
