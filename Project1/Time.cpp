#include "Time.h"

bool Time::check(int count)
{
	return (count >= 0);
}

void Time::CheckTime()
{
	while (this->second >= 60)
	{
		this->minits++;
		this->second -= 60;
	}
	while (this->minits >= 60)
	{
		this->hours++;
		this->minits -= 60;
	}
}

void Time::CheckTime_positiv(int &_hours, int &_minits, int &_second)
{
	while (_second >= 60)
	{
		_minits++;
		_second -= 60;
	}
	while (_minits >= 60)
	{
		_hours++;
		_minits -= 60;
	}
}

void Time::CheckTime_negativ(int &_hours, int &_minits, int &_second)
{
	while (_second < 0)
	{
		_minits--;
		_second += 60;
	}
	while (_minits < 0)
	{
		_hours--;
		_minits += 60;
	}
}

Time::Time() : hours(0), minits(0), second(0) { }

Time::Time(int count) : Time()
{
	if (check(count))
	{
		hours = count;
		minits = count;
		second = count;
		CheckTime();
	}
}

Time::Time(int hours, int minits, int second) : Time()
{
	if (check(hours) && check(minits) && check(second))
	{
		this->hours = hours;
		this->minits = minits;
		this->second = second;
		CheckTime();
	}
}

void Time::ShowTime()const
{
	cout << hours << ":" << minits << ":" << second << endl;
}

void Time::Add_1_Second()
{
	second++;
	CheckTime();
}

void Time::Add_n_Second(int n)
{
	second += n;
	CheckTime();
}

Time Time::operator+(const Time& other)
{
	int _hours = this->hours + other.hours;
	int _minits = this->minits + other.minits;
	int _second = this->second + other.second;
	CheckTime_positiv(_hours, _minits, _second);
	return Time(_hours, _minits, _second);
}
Time Time::operator-(const Time& other)
{
	int _hours = this->hours - other.hours;
	int _minits = this->minits - other.minits;
	int _second = this->second - other.second;
	CheckTime_negativ(_hours, _minits, _second);
	return Time(_hours, _minits, _second);
}
Time Time::operator*(const Time& other)
{
	int _hours = this->hours * other.hours;
	int _minits = this->minits * other.minits;
	int _second = this->second * other.second;
	CheckTime_positiv(_hours, _minits, _second);
	return Time(_hours, _minits, _second);
}

//bool Time::operator>(const Time& other) const
//{
//	int time = ((this->hours * 3600) + (this->minits * 60) + this->second);
//	int time2 = ((other.hours * 3600) + (other.minits * 60) + other.second);
//	return time > time2;
//}
//bool Time::operator<(const Time& other) const
//{
//	//return (this->hours + this->minits + this->second) < (other.hours + other.minits + other.second);
//	int time = ((this->hours * 3600) + (this->minits * 60) + this->second);
//	int time2 = ((other.hours * 3600) + (other.minits * 60) + other.second);
//	return time < time2;
//}
//bool Time::operator>=(const Time& other) const
//{
//	//return (this->hours + this->minits + this->second) >= (other.hours + other.minits + other.second);
//	int time = ((this->hours * 3600) + (this->minits * 60) + this->second);
//	int time2 = ((other.hours * 3600) + (other.minits * 60) + other.second);
//	return time >= time2;
//}
//bool Time::operator<=(const Time& other) const
//{
//	//return (this->hours + this->minits + this->second) <= (other.hours + other.minits + other.second);
//	int time = ((this->hours * 3600) + (this->minits * 60) + this->second);
//	int time2 = ((other.hours * 3600) + (other.minits * 60) + other.second);
//	return time <= time2;
//}
//bool Time::operator==(const Time& other) const
//{
//	//return (this->hours + this->minits + this->second) == (other.hours + other.minits + other.second);
//	int time = ((this->hours * 3600) + (this->minits * 60) + this->second);
//	int time2 = ((other.hours * 3600) + (other.minits * 60) + other.second);
//	return time == time2;
//}
//bool Time::operator!=(const Time& other) const
//{
//	//return (this->hours + this->minits + this->second) != (other.hours + other.minits + other.second);
//	int time = ((this->hours * 3600) + (this->minits * 60) + this->second);
//	int time2 = ((other.hours * 3600) + (other.minits * 60) + other.second);
//	return time != time2;
//}

bool Time :: operator>(const Time& other)const
{
	return ((this->hours * 3600 + this->minits * 60 + this->second) > (other.hours * 3600 + other.minits * 60 + other.second));
}
bool Time :: operator<(const Time& other)const
{
	return (other > * this);
}
bool Time :: operator>=(const Time& other)const
{
	return !(other > * this) || (!(other > * this) && !(*this > other));
}
bool Time :: operator<=(const Time& other)const
{
	return (other > * this) || (!(other > * this) && !(*this > other));
}
bool Time :: operator==(const Time& other)const
{
	return (!(other > * this) && !(*this > other));
}
bool Time :: operator!=(const Time& other)const
{
	return ((other > * this) || (*this > other));
}

Time::~Time()
{

}
