#pragma once
#include <iostream>

using namespace std;

class String
{
private:
	char *str;
	int length;
public:
	String();
	String(int size, char symbol);
	String(const char* str);
	String(const String &other);
	void Print()const;
	void Append(const char* str);
	void operator+=(const  char *str);
	void operator+=(const String& str);
	String operator+(const String& str)const;
	String operator*(const String& str)const;
	bool operator==(const String& str)const;
	bool operator!=(const String& str)const;
	bool operator>(const String& str)const;
	bool operator<(const String& str)const;
	~String();
};