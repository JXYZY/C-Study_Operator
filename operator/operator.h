// operator.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
//using namespace std;
class TimeTest
{
public:
	TimeTest();
	TimeTest(int hour,int minutes);
	~TimeTest();
	int getHour() { return m_hour; }
	int getMinutes() { return m_minutes; }

	TimeTest operator+(const TimeTest&);

	

private:
	int m_hour;
	int m_minutes;
	
	friend TimeTest operator*(int cal, const TimeTest&);
	//friend std::ostream & operator<<(std::ostream &, const TimeTest& t);
	friend void operator<<(std::ostream &, const TimeTest& t);
};

// TODO: 在此处引用程序需要的其他标头。
