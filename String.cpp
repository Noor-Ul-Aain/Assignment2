#include "String.h"

String::String()
{
	myString = nullptr;
	myString = new char[1];
	myString[0] = '\0';
}

String::~String()
{
	delete[]myString;
	myString = nullptr;
}

String::String(const String& obj)
{
	int length = 0;
	while (obj.myString[length] != '\0')
	{
		length++;
	}
	length++;
	if (myString != nullptr)
	{
		delete[] myString;
		myString = nullptr;
	}
	myString = new char[length];
	for (int i = 0; i < length; i++)
	{
		myString[i] = obj.myString[i];
	}
}

String::String(const String& obj, int startingPoint, int length)
{
	if (myString != nullptr)
	{
		delete[]myString;
		myString = nullptr;
	}
	myString = new char[length + 1] {'\0'};
	for (int i = startingPoint, j = 0; i < startingPoint + length; i++, j++)
	{
		myString[j] = obj.myString[i];
	}
}

String::String(const char* temp)
{
	int length = 0;
	while (temp[length] != '\0')
	{
		length++;
	}
	length++;
	if (myString != nullptr)
	{
		delete[] myString;
		myString = nullptr;
	}
	myString = new char[length];
	for (int i = 0; i < length; i++)
	{
		myString[i] = temp[i];
	}
}

String::String(const char* temp, int n)
{
	if (myString != nullptr)
	{
		delete[] myString;
		myString = nullptr;
	}
	myString = new char[n + 1] {'\0'};
	for (int i = 0; i < n; i++)
	{
		myString[i] = temp[i];
	}
}

String::String(int n, char temp)
{
	if (myString != nullptr)
	{
		delete[] myString;
		myString = nullptr;
	}
	myString = new char[n + 1] {'\0'};
	for (int i = 0; i < n; i++)
	{
		myString[i] = temp;
	}
}

int String::length(void)
{
	int len = 0;
	while (myString[len] != '\0')
	{
		len++;
	}
	return len;
}

char String::at(int index)
{
	return myString[index];
}

String String::substr(int startingPoint, int length) const
{
	String temp;
	if (temp.myString != nullptr)
	{
		delete[] temp.myString;
		temp.myString = nullptr;
	}
	temp.myString = new char[length + 1] {'\0'};
	for (int i = startingPoint, j = 0; i < startingPoint + length; i++, j++)
	{
		temp.myString[j] = myString[i];
	}
	return temp;
}

ostream& operator<<(ostream& objOut, String& obj)
{
	objOut << obj.myString;
	return objOut;
}