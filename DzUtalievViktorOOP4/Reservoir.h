#pragma once
#include "String.h"
#include <string>

class Reservoir
{
	int size;
	int size2;

	char *title;
	char *type;

	double width;
	double length;
	double depth;

	double volume;
	double square;
public:
	Reservoir() { width = length = depth =  volume = square = 0; }

	Reservoir(double vWidth, double vLength, double vDepth) :
		width{ vWidth }, length{ vLength }, depth{ vDepth } {}
	 
	Reservoir(const Reservoir& other)
	{
		this->size = other.size;
		this->size2 = other.size2;

		if (other.title == nullptr)
		{
			cout << "ERROR!!!\n";
			exit(1);
		}

		this->size = strlen(other.title) + 1;
		this->title = new char[size];
		loop(i, size)
		{
			this->title[i] = other.title[i];
		}
		this->title[size] = '\0';

		this->size2 = strlen(other.type) + 1;

		if (other.type == nullptr)
		{
			cout << "ERROR!!!\n";
			exit(1);
		}

		this->type = new char[size2];
		loop(i, size2)
		{
			this->type[i] = other.type[i];
		}
		this->type[size] = '\0';

		this->width = other.width;
		this->length = other.length;
		this->depth = other.depth;

		this->volume = other.volume;
		this->square = other.square;
	}



	
///////////////////////////////////////////////////////////////////////////////////////////// Конструкторы
	

	void setTitle(const char *vTitle)
	{
		this->size = strlen(vTitle) + 1;
		this->title = new char[size];
		loop(i, size)
		{
			this->title[i] = vTitle[i];
		}	
		this->title[size] = '\0';
	}

	void setType(char *vType)
	{

		this->size2= strlen(vType) + 1;
		this->type = new char[size2];
		loop(i, size2)
		{
			this->type[i] = vType[i];
		}
		this->type[size] = '\0';
	}

	void setWidth(int vWidth)
	{
		width = vWidth;
	}


	void setLength(int vLength)
	{
		length = vLength;
	}

	void setDepth(int vDepth)
	{
		depth = vDepth;
	}

	void setWidth(char* vWidth)
	{
		title = vWidth;
	}

/////////////////////////////////////////////////// Сетеры

	char *getTitle()
	{
		return title;
	}

	char* getType()
	{
		return type;
	}

	int getWidth() const
	{
		return width;
	}

	int getLength()const
	{
		return length;
	}

	int getDepth()const
	{
		return depth;
	}

	int getVolume() const
	{
		return volume;
	}

	int getSquare() const
	{
		return square;
	}
////////////////////////////////////////////////////////////////////////////////////Геттеры

	void definitionVolume()
	{
		volume = width * length * depth;
	}

	void definitionSquare()
	{
		square = width * length;
	}

	bool definitionType(const Reservoir& other)
	{
		loop(i, size + size2)
		{
			this->type[i] == other.type[i];
			if (this->type[i] != other.type[i])
			{
				return false;
			}
		}
	}

	bool definitionSquareBool(const Reservoir& other)
	{
		if (this->square == other.square)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
/////////////////////////////////////////////////////////////////////////////Методы

	~Reservoir()
	{
		delete[] type;
		delete[] title;	
	}

};

