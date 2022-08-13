// operator.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
//using namespace std;
class TimeTest
{
public:
	TimeTest();
	//测试explicit
	TimeTest(int hour);
	//explicit TimeTest(int hour);  //这种构造函数有一个形参，或者一个形参，其他形参默认值的情况，最好用explicit关闭隐示转换
	TimeTest(int hour,int minutes);
	~TimeTest();
	int getHour() { return m_hour; }
	int getMinutes() { return m_minutes; }
	TimeTest operator+(const TimeTest&);
	//转换函数
	operator int();
	//operator double();

	

private:
	int m_hour;
	int m_minutes;
	
	friend TimeTest operator*(int cal, const TimeTest&);
	//friend std::ostream & operator<<(std::ostream &, const TimeTest& t);
	friend void operator<<(std::ostream &, const TimeTest& t);
};

// TODO: 在此处引用程序需要的其他标头。
