#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstring>
#define loop(i,n) for(int i=0;i<n;i++)

using namespace std;



class String
{
private:
	char* str;
	int sizeLen;
	static const int defaultSize = 80;
	static int k;

public:



	String()
	{
		sizeLen = defaultSize;
		k++;
	}

	String(const char* str)
	{
		sizeLen = strlen(str);
		this->str = new char[sizeLen + 1];
		loop(i, sizeLen)
		{
			this->str[i] = str[i];
		}
		this->str[sizeLen] = '\0';
		k++;
	}

	String(const String& obj)
	{
		if (this->str != nullptr)
		{
			//delete[] str;
		}
		this->sizeLen = strlen(obj.str);
		this->str = new char[sizeLen + 1];
		loop(i, sizeLen)
		{
			this->str[i] = obj.str[i];
		}
		this->str[sizeLen] = '\0';
		k++;
	}

	String(String&& other)
	{
		this->sizeLen = other.sizeLen;
		this->str = other.str;

		other.str = nullptr;
	}

	~String()
	{
		delete[] this->str;
	}

	static int getNumString()
	{
		return k;
	}

	String& operator =(const String& obj)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		sizeLen = strlen(obj.str);
		this->str = new char[sizeLen + 1];
		loop(i, sizeLen)
		{
			this->str[i] = obj.str[i];
		}
		this->str[sizeLen] = '\0';

		return *this;
	}

	String operator +(const String& obj)
	{
		String newStr;

		int thisLen = strlen(this->str);

		int otherLen = strlen(obj.str);

		newStr.sizeLen = strlen(this->str) + strlen(obj.str);

		newStr.str = new char[thisLen + otherLen + 1];
		int i = 0;

		for (; i < thisLen; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLen; i++, j++)
		{
			newStr.str[i] = obj.str[j];
		}
		newStr.str[thisLen + otherLen] = '\0';

		return newStr;
	}

	int sizeLength()
	{
		return sizeLen;
	}

	bool operator ==(const String& other)
	{
		if (this->sizeLen != other.sizeLen)
		{
			return false;
		}
		else
		{
			loop(i, sizeLen)
			{
				if (this->str[i] != other.str[i])
				{
					return false;
				}

			}
			return true;
		}
	}
	bool operator !=(const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator[](int index)
	{
		return this->str[index];
	}

	friend ostream& operator<<(ostream& os, const String& strin)
	{
		return os << strin.str;
	}

	friend istream& operator >> (istream& in, String& strin)
	{
		char temp[defaultSize];
		in.get(temp, defaultSize);
		if (in)
		{
			strin = temp;
		}
		while (in && in.get() != '\n')
		{
			continue;
		}

		return in;
	}


};

