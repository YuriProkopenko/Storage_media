#include <iostream>
#include "PortableHD.h"
using namespace std;

PortableHD::PortableHD() : Device()
{
	HD_speed = new char[6]{ "EMPTY" };
};
PortableHD::PortableHD(char* company, char* model, char* name, char* capacity, char* HD_speed) : Device(company, model, name, capacity)
{
	this->HD_speed = new char[strlen(HD_speed) + 1];
	for (int i = 0; i < strlen(HD_speed) + 1; i++)
		this->HD_speed[i] = HD_speed[i];
};
PortableHD::PortableHD(const PortableHD& obj) :Device((Device&)obj)
{
	this->HD_speed = new char[strlen(obj.HD_speed) + 1];
	for (int i = 0; i < strlen(obj.HD_speed) + 1; i++)
		this->HD_speed[i] = obj.HD_speed[i];
};
PortableHD::PortableHD(PortableHD&& obj) : Device((Device&&)obj)
{
	this->HD_speed = obj.HD_speed;
	obj.HD_speed = nullptr;
};
PortableHD::~PortableHD()
{
	delete[] HD_speed;
	HD_speed = nullptr;
};
const char* PortableHD::getHD_speed() const
{
	return HD_speed;
};
void PortableHD::setHD_speed(const char* HD_speed)
{
	delete[] this->HD_speed;
	this->HD_speed = new char[strlen(HD_speed) + 1];
	for (int i = 0; i < strlen(HD_speed) + 1; i++)
		this->HD_speed[i] = HD_speed[i];
};
void PortableHD::Print() const
{
	Device::Print();
	cout << "Portable HD speed : " << HD_speed << endl;
};
void PortableHD::Load(FILE* file, Device* obj) const
{
	Device::Load(file, obj);
	int size_HD_speed;
	fread(&size_HD_speed, sizeof(int), 1, file);
	char* l_HD_speed = new char[size_HD_speed];
	fread(l_HD_speed, sizeof(char), size_HD_speed, file);
	((PortableHD*)obj)->setHD_speed(l_HD_speed);
};
void PortableHD::Save(FILE* file) const
{
	Device::Save(file);
	int size_HD_speed = strlen(HD_speed) + 1;
	fwrite(&size_HD_speed, sizeof(int), 1, file);
	fwrite(HD_speed, sizeof(char), size_HD_speed, file);
};
PortableHD& PortableHD::operator=(const PortableHD& obj)
{
	if (this == &obj)
		return *this;
	Device::operator=((Device&)obj);
	this->HD_speed = new char[strlen(obj.HD_speed) + 1];
	for (int i = 0; i < strlen(obj.HD_speed) + 1; i++)
		this->HD_speed[i] = obj.HD_speed[i];
	return *this;
};
PortableHD& PortableHD::operator=(PortableHD&& obj)
{
	if (this == &obj)
		return *this;
	Device::operator=((Device&&)obj);
	this->HD_speed = obj.HD_speed;
	obj.HD_speed = nullptr;
	return *this;
};
std::istream& operator>>(std::istream& is, PortableHD& obj)
{
	is >> obj;
	char* word = new char[256];
	cout << "Input a Portable HD speed : ";
	is >> word;
	obj.HD_speed = word;
	delete[] word;
	word = nullptr;
	return is;
};
std::ostream& operator<<(std::ostream& os, const PortableHD& obj)
{
	obj.Print();
	return os;
};