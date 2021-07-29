#include <iostream>
#include <conio.h>
#include <string.h>
#include "Data_carriers_list.h"
using namespace std;

void Data_carriers_list::Add_Device()
{
	char* word = new char[100];
	Device* obj = nullptr;
	int choice = 0;
	while (choice != 4) {
		system("cls");
		cout << "What type of device would you like to add : " << endl;
		cout << "1.DVD disc" << endl;
		cout << "2.Portable HD" << endl;
		cout << "3.USB flah" << endl;
		cout << "4.Exit";
		choice = _getch() - 48;
		switch (choice) {
		case 1:
			obj = new DVD_disc;
			system("cls");
			cout << "input company : ";
			cin >> word;
			obj->setCompany(word);
			cout << "input model : ";
			cin >> word;
			obj->setModel(word);
			obj->setName("dvd-disc");
			cout << "input capacity : ";
			cin >> word;
			obj->setCapacity(word);
			cout << "input dvd speed : ";
			cin >> word;
			((DVD_disc*)obj)->setDVD_speed(word); 
			array.Add(obj);
			obj = nullptr;
			break;
		case 2:
			obj = new PortableHD;
			system("cls");
			cout << "input company : ";
			cin >> word;
			obj->setCompany(word);
			cout << "input model : ";
			cin >> word;
			obj->setModel(word);
			obj->setName("portableHD");
			cout << "input capacity : ";
			cin >> word;
			obj->setCapacity(word);
			cout << "input HD speed : ";
			cin >> word;
			((PortableHD*)obj)->setHD_speed(word);
			array.Add(obj);
			obj = nullptr;
			break;
		case 3:
			obj = new USBflash;
			system("cls");
			cout << "input company : ";
			cin >> word;
			obj->setCompany(word);
			cout << "input model : ";
			cin >> word;
			obj->setModel(word);
			obj->setName("usbflash");
			cout << "input capacity : ";
			cin >> word;
			obj->setCapacity(word);
			cout << "input usb speed : ";
			cin >> word;
			((USBflash*)obj)->setUSB_speed(word);
			array.Add(obj);
			obj = nullptr;
			break;
		case 4:
			break;
		default:
			system("cls");
			cout << "Wrong command !";
			system("pause >> NUL");
			break;
		}
	}
	delete[] word;
	word = nullptr;
}
void Data_carriers_list::Del(int number)
{
	array[number - 1]->Quantity_minus();
	array.Remove(number - 1);
}
void Data_carriers_list::Edit(int number)
{
	int choice = 0;
	char* word = new char[100];
	while (choice != 7)
	{
	system("cls");
	cout << "What do you want to edit : " << endl;
	cout << "1.All" << endl;
	cout << "2.company" << endl;
	cout << "3.model" << endl;
	cout << "4.name" << endl;
	cout << "5.capacity" << endl;
	cout << "6.speed" << endl;
	cout << "7.exit";
	choice = _getch() - 48;
		switch (choice)
		{
		case 1:
			system("cls");
			if (typeid(*array[number - 1]) == typeid(DVD_disc)) {
				cout << "Input a company : ";
				cin >> word;
				array[number - 1]->setCompany(word);
				cout << "Input a model : ";
				cin >> word;
				array[number - 1]->setModel(word);
				cout << "Input a name : ";
				cin >> word;
				array[number - 1]->setName(word);
				cout << "Input a capacity : ";
				cin >> word;
				array[number - 1]->setCapacity(word);
				cout << "Input DVD speed : ";
				cin >> word;
				((DVD_disc*)array[number - 1])->setDVD_speed(word);
			}
			if (typeid(*array[number - 1]) == typeid(PortableHD)) {
				cout << "Input a company : ";
				cin >> word;
				array[number - 1]->setCompany(word);
				cout << "Input a model : ";
				cin >> word;
				array[number - 1]->setModel(word);
				cout << "Input a name : ";
				cin >> word;
				array[number - 1]->setName(word);
				cout << "Input a capacity : ";
				cin >> word;
				array[number - 1]->setCapacity(word);
				cout << "Input HD speed : ";
				cin >> word;
				((PortableHD*)array[number - 1])->setHD_speed(word);
			}
			if (typeid(*array[number - 1]) == typeid(USBflash)) {
				cout << "Input a company : ";
				cin >> word;
				array[number - 1]->setCompany(word);
				cout << "Input a model : ";
				cin >> word;
				array[number - 1]->setModel(word);
				cout << "Input a name : ";
				cin >> word;
				array[number - 1]->setName(word);
				cout << "Input a capacity : ";
				cin >> word;
				array[number - 1]->setCapacity(word);
				cout << "Input USB speed : ";
				cin >> word;
				((USBflash*)array[number - 1])->setUSB_speed(word);
			}
			break;
		case 2:
			system("cls");
			cout << "Input a company : ";
			cin >> word;
			array[number - 1]->setCompany(word);
			break;
		case 3:
			system("cls");
			cout << "Input a model : ";
			cin >> word;
			array[number - 1]->setModel(word);
			break;
		case 4:
			system("cls");
			cout << "Input a name : ";
			cin >> word;
			array[number - 1]->setName(word);
			break;
		case 5:
			system("cls");
			cout << "Input a capacity : ";
			cin >> word;
			array[number - 1]->setCapacity(word);
			break;
		case 6:	
			system("cls");
			if (typeid(*array[number - 1]) == typeid(DVD_disc)) {
				cout << "Input DVD speed : ";
				cin >> word;
				((DVD_disc*)array[number])->setDVD_speed(word);
			}
			if (typeid(*array[number - 1]) == typeid(PortableHD)) {
				cout << "Input HD speed : ";
				cin >> word;
				((PortableHD*)array[number])->setHD_speed(word);
			}
			if (typeid(*array[number - 1]) == typeid(USBflash)) {
				cout << "Input USB speed : ";
				cin >> word;
				((USBflash*)array[number])->setUSB_speed(word);
			}
			break;
		}
	}
}
Device* Data_carriers_list::Search(const char *word)
{
	for (int i = 0; i < array.GetSize(); i++)
		if (strcmp(word, array[i]->getModel()) == 0) {
			return array[i];
		}
	return 0;
}
void Data_carriers_list::Print()
{
	int list_number = 0;
	int DVD_count = 0;
	int HD_count = 0;
	int USB_count = 0;
	int total = 0;
	if (array.GetSize() != 0)
		total = array[0]->getQuantity();
	for (int i = 0; i < array.GetSize(); i++) {
		cout << ++list_number << ". ";
		array[i]->Print();
		if (typeid(*array[i]) == typeid(DVD_disc))
			DVD_count++;
		else if (typeid(*array[i]) == typeid(PortableHD))
			HD_count++;
		else if (typeid(*array[i]) == typeid(USBflash))
			USB_count++;
	}
	cout << "DVD-disc : " << DVD_count << " Portable HD : " << HD_count << " USB flash : " << USB_count << " Total : " << total;
}
void Data_carriers_list::Load(int number)
{
	int array_size = array.GetSize();
	if (array_size != 0)
		for (int i = 0; i < array_size; i++)
			array[0]->Quantity_minus();
	this->array.Clear();
	char filename[_MAX_PATH];
	FILE* file = nullptr;
	system("cls");
	cout << "Enter file path : ";
	cin >> filename;
	fopen_s(&file, filename, "rb");
	if (file == nullptr)
	{
		perror(NULL);
		cout << "Wrong path!";
		system("pause>>NUL");
		return;
	}
	int size_dev = 0;
	fread(&size_dev, sizeof(int), 1, file);
	bool check = true;
	Device* obj = nullptr;
	switch (number) {
	case 1:
		for (int i = 0; i < size_dev; i++)
		{
			obj = new DVD_disc;
			check = false;
			obj->Load(file, obj);
			if (strcmp(obj->getName(), "dvd-disc") == 0) {
				array.Add(obj);
				obj = nullptr;
			}
			else {
				delete obj;
				obj = nullptr;
			}
		}
		fclose(file);
		fopen_s(&file, filename, "rb");
		fread(&size_dev, sizeof(int), 1, file);
		for (int i = 0; i < size_dev; i++)
		{
			obj = new PortableHD;
			check = false;
			obj->Load(file, obj);
			if (strcmp(obj->getName(), "portableHD") == 0) {
				array.Add(obj);
				obj = nullptr;
			}
			else {
				delete obj;
				obj = nullptr;
			}
		}
		fclose(file);
		fopen_s(&file, filename, "rb");
		fread(&size_dev, sizeof(int), 1, file);
		for (int i = 0; i < size_dev; i++)
		{
			obj = new USBflash;
			check = false;
			obj->Load(file, obj);
			if (strcmp(obj->getName(), "usbflash") == 0) {
				array.Add(obj);
				obj = nullptr;
			}
			else {
				delete obj;
				obj = nullptr;
			}
		}
		break;
	case 2:
		for (int i = 0; i < size_dev; i++)
		{
			obj = new DVD_disc;
			check = false;
			obj->Load(file, obj);
			if (strcmp(obj->getName(), "dvd-disc") == 0) {
				array.Add(obj);
				obj = nullptr;
			}
			else {
				delete obj;
				obj = nullptr;
			}
		}
		break;
	case 3:
		for (int i = 0; i < size_dev; i++)
		{
			obj = new PortableHD;
			check = false;
			obj->Load(file, obj);
			if (strcmp(obj->getName(), "portableHD") == 0) {
				array.Add(obj);
				obj = nullptr;
			}
			else {
				delete obj;
				obj = nullptr;
			}
		}
		break;
	case 4:
		for (int i = 0; i < size_dev; i++)
		{
			obj = new USBflash;
			check = false;
			obj->Load(file, obj);
			if (strcmp(obj->getName(), "usbflash") == 0) {
				array.Add(obj);
				obj = nullptr;
			}
			else {
				delete obj;
				obj = nullptr;
			}
		}
		break;
	}
	fclose(file);
}
void Data_carriers_list::Save()
{
	char filename[_MAX_PATH];
	FILE* file = nullptr;
	cout << "Enter the file to save the list : ";
	cin >> filename;
	fopen_s(&file, filename, "wb");
	if (file == nullptr)
	{
		perror(NULL);
		cout << "Wrong path!";
		system("pause>>NUL");
		return;
	}
	int size_dev = array.GetSize();
	fwrite(&size_dev, sizeof(int), 1, file);
	for (int i = 0; i < array.GetSize(); i++)
	{
		array[i]->Save(file);
	}
	fclose(file);
}