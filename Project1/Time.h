#pragma once
#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minits;
	int second;
	void CheckTime();
	void CheckTime_positiv(int &_hours, int &_minits, int &_second);
	void CheckTime_negativ(int &_hours, int &_minits, int &_second);
	bool check(int count);
public:
	Time();
	Time(int count);
	Time(int hours, int minits, int second);
	void ShowTime()const;
	void Add_1_Second();
	void Add_n_Second(int n);
	Time operator+(const Time& other);
	Time operator-(const Time& other);
	Time operator*(const Time& other);
	bool operator>(const Time& other) const;
	bool operator<(const Time& other) const;
	bool operator>=(const Time& other) const;
	bool operator<=(const Time& other) const;
	bool operator==(const Time& other) const;
	bool operator!=(const Time& other) const;
	~Time();
};

