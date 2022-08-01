#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

class Menu
{
	String title;
	String p1;
	String p2;
	String p3;

	int Set[3] = { 7,7,7 };

	int nMenu;

	void color(int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	void gotoxy(int x, int y)
	{
		COORD c;
		c.X = x;
		c.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	}
public:
	Menu() {}

	Menu(String vTitle, String vP1, String vP2, String vP3) : title{ vTitle }, p1 { vP1 }, p2{ vP2 }, p3{ vP3 } {}

	int menu()
	{
		char key;
		int counter = 2;


		cout << title;

		loop(i, INFINITY)
		{
			gotoxy(10, 5);
			color(Set[0]);
			cout << p1;

			gotoxy(10, 6);
			color(Set[1]);
			cout << p2;

			gotoxy(10, 7);
			color(Set[2]);
			cout << p3;

			key = _getch();

			if (key == 72 && (counter >= 2 && counter <= 3))
			{
				counter--;
			}
			if (key == 80 && (counter >= 1 && counter <= 2))
			{
				counter++;
			}
			if (key == '\r')
			{
				if (counter == 1)
				{
					nMenu = 1;
					return nMenu;
				}
				if (counter == 2)
				{
					nMenu = 2;
					return nMenu;

				}
				if (counter == 3)
				{
					nMenu = 3;
					return nMenu;
				}
			}
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			if (counter == 1)
			{
				Set[0] = 12;
			}
			if (counter == 2)
			{
				Set[1] = 12;
			}
			if (counter == 3)
			{
				Set[2] = 12;
			}
		}

	}// Интерактивное меню


	int getNmenu() const
	{
		return nMenu;
	}
};

