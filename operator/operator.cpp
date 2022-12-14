// operator.cpp: 定义应用程序的入口点。
//

#include "operator.h"

TimeTest::TimeTest()
{
	std::cout << "test explicit" << std::endl;
}
//测试explicit
TimeTest::TimeTest(int hour)
{
	m_hour = hour;
	m_minutes = 20;
}

TimeTest::TimeTest(const TimeTest&)
{
	std::cout << "调用拷贝构造" << std::endl;
}

TimeTest TimeTest::operator=(const TimeTest& t)
{
	TimeTest ts = NULL;
	std::cout << "调用赋值构造" << std::endl;
	return ts;
}

TimeTest::TimeTest(int hour, int minutes)
	:m_hour(hour)
	,m_minutes(minutes)
{

}
TimeTest::~TimeTest()
{

}

TimeTest TimeTest::operator+(const TimeTest& t)
{
	TimeTest total;
	total.m_minutes =m_minutes + t.m_minutes;
	total.m_hour = m_hour + t.m_hour + total.m_minutes / 60;
	total.m_minutes %= 60;
	return total;
}


//友元函数外部重载*
TimeTest operator*(int cal, const TimeTest& t)
{
	TimeTest result;
	result.m_hour = cal * t.m_hour;
	result.m_minutes = cal * t.m_minutes;
	result.m_hour += result.m_minutes / 60;
	result.m_minutes %= 60;
	return result;
}

#if 0
//外部重载<< 返回ostream对象 可以连续使用<<
std::ostream & operator<<(std::ostream & os, const TimeTest& t)
{
	os << t.m_hour << "hour " << t.m_minutes << "minutes";
	return os;
	
}
#endif

#if 1
// 无返回，只能使用一次cout<<TimeTest
void operator<<(std::ostream & os, const TimeTest& t)
{
	os << t.m_hour << "hour " << t.m_minutes << "minutes";
}
#endif
#if 1
//转换函数
TimeTest::operator int()
{
	return m_hour;
}
#endif


int main()
{
	TimeTest t1(5, 25);
	TimeTest t2(2,55);
	TimeTest total = t1 + t2;
	TimeTest total2 = 2 * t2;
	std::cout << "total hour:" << total.getHour() << " " << "total minutes:" << total.getMinutes() << std::endl;
	std::cout << "total2 hour:" << total2.getHour() << " " << "total2 minutes:" << total2.getMinutes() << std::endl;
	std::cout << "Hello CMake。" << std::endl;
	std::cout << t1;
	//测试explicit
	TimeTest t3;
	//先隐式调用一个参数的构造，构造临时对象，再调用赋值构造
	t3 = 5;
	int test = 5;
	//下面两种都调用带有一个参数的构造函数
	TimeTest t4 = test;
	TimeTest t7(test);
	TimeTest total3 = t3 + t4;
	std::cout << "total3 hour:" << total3.getHour() << " " << "total3 minutes:" << total3.getMinutes() << std::endl;
	
	//测试转换函数，转换函数只能在类内部去声明
	int hour = t1;
	std::cout << "t1 hour:" << hour << std::endl;
	getchar();
	return 0;
}
