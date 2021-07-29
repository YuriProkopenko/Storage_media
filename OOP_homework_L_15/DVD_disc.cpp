#include <iostream>
#include "DVD_disc.h"
using namespace std;

DVD_disc::DVD_disc() : Device()
{
	dvd_speed = new char[6] {"EMPTY"};
};
DVD_disc::DVD_disc(char* company, char* model, char* name, char* capacity, char* dvd_speed) : Device(company, model, name, capacity)
{
	this->dvd_speed = new char [strlen(dvd_speed) + 1];
	for (int i = 0; i < strlen(dvd_speed) + 1; i++)
		this->dvd_speed[i] = dvd_speed[i];
};
DVD_disc::DVD_disc(const DVD_disc& obj) :Device((Device&)obj)
{
	this->dvd_speed = new char[strlen(obj.dvd_speed) + 1];
	for (int i = 0; i < strlen(obj.dvd_speed) + 1; i++)
		this->dvd_speed[i] = obj.dvd_speed[i];
};
DVD_disc::DVD_disc(DVD_disc&& obj) : Device((Device&&)obj) 
{
	this->dvd_speed = obj.dvd_speed;
	obj.dvd_speed = nullptr;
};
DVD_disc::~DVD_disc()
{
	delete[] dvd_speed;
	dvd_speed = nullptr;
};
const char* DVD_disc::getDVD_speed() const
{
	return dvd_speed;
};
void DVD_disc::setDVD_speed(const char* dvd_speed)
{
	delete[] this->dvd_speed;
	this->dvd_speed = new char[strlen(dvd_speed) + 1];
	for (int i = 0; i < strlen(dvd_speed) + 1; i++)
		this->dvd_speed[i] = dvd_speed[i];
};
void DVD_disc::Print() const
{
	Device::Print();
	cout << "DVD speed : " << dvd_speed << endl;
};
void DVD_disc::Load(FILE* file, Device* obj) const
{
	Device::Load(file, obj);
	int size_dvd_speed;
	fread(&size_dvd_speed, sizeof(int), 1, file);
	char* l_dvd_speed = new char[size_dvd_speed];
	fread(l_dvd_speed, sizeof(char), size_dvd_speed, file);
	((DVD_disc*)obj)->setDVD_speed(l_dvd_speed);
};
void DVD_disc::Save(FILE* file) const
{
	Device::Save(file);
	int size_dvd_speed = strlen(dvd_speed) + 1;
	fwrite(&size_dvd_speed, sizeof(int), 1, file);
	fwrite(dvd_speed, sizeof(char), size_dvd_speed, file);
};
DVD_disc& DVD_disc::operator=(const DVD_disc& obj)
{
	if (this == &obj)
		return *this;
	Device::operator=((Device&)obj);
	this->dvd_speed = new char[strlen(obj.dvd_speed) + 1];
	for (int i = 0; i < strlen(obj.dvd_speed) + 1; i++)
		this->dvd_speed[i] = obj.dvd_speed[i];
	return *this;
};
DVD_disc& DVD_disc::operator=(DVD_disc&& obj)
{
	if (this == &obj)
		return *this;
	Device::operator=((Device&&)obj);
	this->dvd_speed = obj.dvd_speed;
	obj.dvd_speed = nullptr;
	return *this;
};
std::istream& operator>>(std::istream& is, DVD_disc& obj)
{
	is >> obj;
	char* word = new char[256];
	cout << "Input a dvd speed : ";
	is >> word;
	obj.dvd_speed = word;
	delete[] word;
	word = nullptr;
	return is;
};
std::ostream& operator<<(std::ostream& os, const DVD_disc& obj)
{
	obj.Print();
	return os;
};