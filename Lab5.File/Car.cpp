#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Car.h"

using namespace std;

Car::Car(char* model, char* color, char* mk, int yrel, char* yinsp, char* val)
{
	this->SetCar(model, color, mk, yrel, yinsp, val);
}

Car::~Car(){}

void Car::SetModel(char* s)
{
	strcpy(this->model, s);
}

void Car::SetColor(char* s)
{
	strcpy(this->color, s);
}

void Car::SetSirealNumber(char* s)
{
	strcpy(this->mk, s);
}

void Car::SetRelease(int s)
{
	this->yrel = s;
}

void Car::SetInspection(char* s)
{
	strcpy(this->yinsp, s);
}

void Car::SetValue(char* s)
{
	strcpy(this->val, s);
}

char* Car::GetModel()
{
	return this->model;
}

char* Car::GetColor()
{
	return this->color;
}

char* Car::GetSirealNumber()
{
	return this->mk;
}

int Car::GetRelease()
{
	return this->yrel;
}

char* Car::GetInspection()
{
	return this->yinsp;
}

char* Car::GetValue()
{
	return this->val;
}


void Car::SetCar(char* s1, char* s2, char* s3, int s4, char* s5, char* s6)
{
	this->SetModel(s1);
	this->SetColor(s2);
	this->SetSirealNumber(s3);
	this->SetRelease(s4);
	this->SetInspection(s5);
	this->SetValue(s6);
}

void Car::InitCar()
{
	char model[N] = "", color[N] = "", mk[N] = "", yinsp[N] = "", val[N] = "";
	int yrel;
	cout << "\nEnter the model:";
	cin.ignore();
	cin.get(model, N, '\n');
	cout << "Enter the color:";
	cin.ignore();
	cin.get(color, N, '\n');
	cout << "Enter the serial number:";
	cin.ignore();
	cin.get(mk, N, '\n');
	cout << "Enter the year of release:";
	cin.ignore();
	cin >> yrel;
	cout << "Enter the year of inspection:";
	cin.ignore();
	cin.get(yinsp, N, '\n');
	cout << "Enter the value in $:";
	cin.ignore();
	cin.get(val, N, '\n');
	this->SetCar(model, color, mk, yrel, yinsp, val);
}


void Car::DisplayCar()
{
	cout << endl << this->model << ", " << this->color << " color, sireal number " << this->mk << endl <<
		"The year of release " << this->yrel << ", of inspection " << this->yinsp << ". The value " << this->val << "$." << endl;
}


