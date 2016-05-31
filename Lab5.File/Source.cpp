#include <iostream>
#include <io.h>
#include <fstream>
#include <cstring>
#include "Car.h"

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void SortingFile(char*);

const int l = 30;

int main()
{
	char fileName[l] = "";
	cout << "Enter the name of file: ";
	cin.getline(fileName, l, '\n');
	InitFile(fileName);
	SortingFile(fileName);
	DisplayFile(fileName);
	system("pause");
	return 0;
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	int bufSize = sizeof(Car);
	Car car;
	char Ok = 'y';
	while (Ok == 'y')
	{
		car.InitCar();
		streamOut.write((char*)&car, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> Ok;
	}
	streamOut.close();
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	int bufSize = sizeof(Car);
	Car* car = new Car;
	while (streamIn.read((char*)car, bufSize))
	{
		car->DisplayCar();
	}
	streamIn.close();
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		flag = false;
		Car car1, car2;
		int bufSize = sizeof(Car);
		streamInOut.read((char*)&car1, bufSize);
		while (streamInOut.read((char*)&car2, bufSize))
		{
			if (car2.GetRelease() < car2.GetRelease())
			{
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&car2, bufSize);
				streamInOut.write((char*)&car1, bufSize);
				flag = true;
			}
			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&car2, bufSize);
		}
		streamInOut.close();
	}
}
