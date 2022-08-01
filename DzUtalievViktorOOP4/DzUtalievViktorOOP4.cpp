//Задание.
//Разработать класс Reservoir(водоем).
//Класс должен обязательно иметь поле «название».
//Класс должен содержать :
//конструктор по умолчанию, конструктор с параметрами,
//при необходимости реализовать 
//деструктор и конструктор копирования.
//

// Уталиев Виктор Геннадьевич


#include "String.h"
#include "Menu.h"
#include "Reservoir.h"
#include <fstream>

int globalSize;
int n;

Reservoir* arrRes = new Reservoir[globalSize];

Reservoir* delArr(Reservoir* arr, int& size, int id)
{
	if (id > size || id < 1)
	{
		return 0;
	}
	for (int i = id - 1; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;

	return arr;
}

int main()
{
	system("cls");

	String title = "\n\n\t\t\tRESERVOIRS\n";
	String p1 = "ADD DATA ABOUT RESERVOIRS";
	String p2 = "OPTIONS";
	String p3 = "EXIT";

	Menu a(title,p1, p2, p3);

	cout << a.menu();

	int x = a.getNmenu();

	ofstream fout;

	switch (x)
	{
	case 1:
	{
		
		system("cls");
		cout << "Enter the number of reservoirs:\n";
		cin >> globalSize;
		
		
		loop(i, globalSize)
		{
			cout << "Enter the reservoir data # " << i + 1 << endl;

			char title1[128];
			cout << "Enter a title:\n";
			cin >> title1;
			char type[128];
			cout << "Enter a type:\n";
			cin >> type;

			double width;
			double length;
			double depth;
		
			cout << "Enter a width:\n";
			cin >> width;
			cout << "Enter a length:\n";
			cin >> length;
			cout << "Enter a depth:\n";
			cin >> depth;


			arrRes[i].setTitle(title1);
			arrRes[i].setType(type);
			arrRes[i].setWidth(width);
			arrRes[i].setLength(length);
			arrRes[i].setDepth(depth);
		}
		return main();
		break;
	}
	case 2:
	{
		system("cls");

		String title = "\n\n\t\t\tOPTIONS\n";
		String p1 = "SHOW ALL RESERVOIRS";
		String p2 = "ADD A RESRVOIR";
		String p3 = "REMOVE A RESERVOIR";

		Menu a(title, p1, p2, p3);

		cout << a.menu();

		int x = a.getNmenu();
		
		switch (x)
		{
			case 1:
			{
				system("cls");
				loop(i, globalSize)
				{
					cout << "Reservoir # " << i + 1 << endl<<endl;

					cout << "Title " << arrRes[i].getTitle() << endl;
					cout << "Type " << arrRes[i].getType() << endl;
					cout << endl;
					cout << "\t\tDimensions of the reservoir\n";
					cout << "Width " << arrRes[i].getWidth() << endl;
					cout << "Length " << arrRes[i].getLength() << endl;
					cout << "Depth " << arrRes[i].getDepth() << endl;
					cout << endl << endl;

				

					fout.open("File.txt");
					if (!fout.is_open())
					{
						cout << "ERROR!!!\n";
						exit(1);
					}
					fout.write((char*)&arrRes[i], sizeof(arrRes));
				}

				fout.close();
				system("pause");
				return main();
				break;
			}
			case 2:
			{
				system("cls");
				globalSize++;
				n = globalSize-1;
				cout << "Enter the reservoir data # " << n << endl;

				char title1[128];
				cout << "Enter a title:\n";
				cin >> title1;
				char type[128];
				cout << "Enter a type:\n";
				cin >> type;

				double width;
				double length;
				double depth;

				cout << "Enter a width:\n";
				cin >> width;
				cout << "Enter a length:\n";
				cin >> length;
				cout << "Enter a depth:\n";
				cin >> depth;

				arrRes[n].setTitle(title1);
				arrRes[n].setType(type);
				arrRes[n].setWidth(width);
				arrRes[n].setLength(length);
				arrRes[n].setDepth(depth);

				system("pause");
				return main();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Enter the reservoir number:\n";
				int id;
				cin >> id;

				delArr(arrRes, globalSize, id);

				system("pause");
				return main();
				break;
			}
		}
		break;
	}
	case 3:
	{
		break;
	}

	}

	delete[] arrRes;
	return 0;
}