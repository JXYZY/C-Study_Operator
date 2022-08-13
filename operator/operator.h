// operator.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>

class Time
{
public:
	Time();
	Time(int hour,int minutes);
	~Time();
	int getHour() { return m_hour; }
	int getMinutes() { return m_minutes; }

	Time operator+(const Time&);

private:
	int m_hour;
	int m_minutes;

	friend Time operator*(int cal, const Time&);

};

// TODO: 在此处引用程序需要的其他标头。
