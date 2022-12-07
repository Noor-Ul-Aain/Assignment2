#pragma once
#include<iostream>
using namespace std;
class String
{
private:
	char* myString;

public:
	String();
	~String();
	String(const String&);
	String(const String&, int, int);
	String(const char*);
	String(const char*, int);
	String(int, char);
	int length(void);
	char at(int);
	String substr(int, int) const;
	friend ostream& operator<<(ostream&, String&);
};