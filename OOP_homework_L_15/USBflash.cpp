#include <iostream>
#include "USBflash.h"
using namespace std;

USBflash::USBflash() : Device()
{
	usb_speed = new char[6]{ "EMPTY" };
};
USBflash::USBflash(char* company, char* model, char* name, char* capacity, char* usb_speed) : Device(company, model, name, capacity)
{
	this->usb_speed = new char[strlen(usb_speed) + 1];
	for (int i = 0; i < strlen(usb_speed) + 1; i++)
		this->usb_speed[i] = usb_speed[i];
};
USBflash::USBflash(const USBflash& obj) :Device((Device&)obj)
{
	this->usb_speed = new char[strlen(obj.usb_speed) + 1];
	for (int i = 0; i < strlen(obj.usb_speed) + 1; i++)
		this->usb_speed[i] = obj.usb_speed[i];
};
USBflash::USBflash(USBflash&& obj) : Device((Device&&)obj)
{
	this->usb_speed = obj.usb_speed;
	obj.usb_speed = nullptr;
};
USBflash::~USBflash()
{
	delete[] usb_speed;
	usb_speed = nullptr;
};
const char* USBflash::getUSB_speed() const
{
	return usb_speed;
};
void USBflash::setUSB_speed(const char* usb_speed)
{
	delete[] this->usb_speed;
	this->usb_speed = new char[strlen(usb_speed) + 1];
	for (int i = 0; i < strlen(usb_speed) + 1; i++)
		this->usb_speed[i] = usb_speed[i];
};
void USBflash::Print() const
{
	Device::Print();
	cout << "USB flash speed : " << usb_speed << endl;
};
void USBflash::Load(FILE* file, Device* obj) const
{
	Device::Load(file, obj);
	int size_usb_speed;
	fread(&size_usb_speed, sizeof(int), 1, file);
	char* l_usb_speed = new char[size_usb_speed];
	fread(l_usb_speed, sizeof(char), size_usb_speed, file);
	((USBflash*)obj)->setUSB_speed(l_usb_speed);
};
void USBflash::Save(FILE* file) const
{
	Device::Save(file);
	int size_usb_speed = strlen(usb_speed) + 1;
	fwrite(&size_usb_speed, sizeof(int), 1, file);
	fwrite(usb_speed, sizeof(char), size_usb_speed, file);
};
USBflash& USBflash::operator=(const USBflash& obj)
{
	if (this == &obj)
		return *this;
	Device::operator=((Device&)obj);
	this->usb_speed = new char[strlen(obj.usb_speed) + 1];
	for (int i = 0; i < strlen(obj.usb_speed) + 1; i++)
		this->usb_speed[i] = obj.usb_speed[i];
	return *this;
};
USBflash& USBflash::operator=(USBflash&& obj)
{
	if (this == &obj)
		return *this;
	Device::operator=((Device&&)obj);
	this->usb_speed = obj.usb_speed;
	obj.usb_speed = nullptr;
	return *this;
};
std::istream& operator>>(std::istream& is, USBflash& obj)
{
	is >> obj;
	char* word = new char[256];
	cout << "Input the usb speed : ";
	is >> word;
	obj.usb_speed = word;
	delete[] word;
	word = nullptr;
	return is;
};
std::ostream& operator<<(std::ostream& os, const USBflash& obj)
{
	obj.Print();
	return os;
};