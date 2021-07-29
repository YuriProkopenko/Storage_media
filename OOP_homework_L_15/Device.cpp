#include <iostream>
#include "Device.h"
using namespace std;

int Device::quantity = 0;

Device::Device()
{
	company = new char[6] { "EMPTY" };
	model = new char[6] { "EMPTY" };
	name = new char[6] { "EMPTY" };
	capacity = new char[6] { "EMPTY" };
	quantity++;
};
Device::Device(char* company, char* model, char* name, char* capacity)
{
	this->company = new char[sizeof(company) + 1];
	for (int i = 0; i < sizeof(company) + 1; i++)
		this->company[i] = company[i];
	this->model = new char[sizeof(model) + 1];
	for (int i = 0; i < sizeof(model) + 1; i++)
		this->model[i] = model[i];
	this->name = new char[sizeof(name) + 1];
	for (int i = 0; i < sizeof(name) + 1; i++)
		this->name[i] = name[i];
	this->capacity = new char[sizeof(capacity) + 1];
	quantity++;
};
Device::Device(const Device& obj)
{
	this->company = new char[sizeof(obj.company) + 1];
	for (int i = 0; i < sizeof(obj.company) + 1; i++)
		this->company[i] = obj.company[i];
	this->model = new char[sizeof(obj.model) + 1];
	for (int i = 0; i < sizeof(obj.model) + 1; i++)
		this->model[i] = obj.model[i];
	this->name = new char[sizeof(obj.name) + 1];
	for (int i = 0; i < sizeof(obj.name) + 1; i++)
		this->name[i] = obj.name[i];
	this->capacity = new char[sizeof(obj.capacity) + 1];
};
Device::Device(Device&& obj)
{
	company = obj.company;
	obj.company = nullptr;
	model = obj.model;
	obj.model = nullptr;
	name = obj.name;
	obj.name = nullptr;
	capacity = obj.capacity;
	obj.capacity = nullptr;
};
Device::~Device()
{
	delete[] company;
	company = nullptr;
	delete[] model;
	model = nullptr;
	delete[] name;
	name = nullptr;
	delete[] capacity;
	capacity = nullptr;
	quantity--;
};
const char* Device::getCompany()const
{
	return company;
};
const char* Device::getModel()const
{
	return model;
};
const char* Device::getName()const
{
	return name;
};
const char* Device::getCapacity()const
{
	return capacity;
};
int Device::getQuantity()
{
	return quantity;
};
void Device::setCompany(const char* company)
{
	delete[] this->company;
	this->company = new char[strlen(company) + 1];
	for (int i = 0; i < strlen(company) + 1; i++)
		this->company[i] = company[i];
};
void Device::setModel(const char* model)
{
	delete[] this->model;
	this->model = new char[strlen(model) + 1];
	for (int i = 0; i < strlen(model) + 1; i++)
		this->model[i] = model[i];
};
void Device::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name) + 1; i++)
		this->name[i] = name[i];
};
void Device::setCapacity(const char* capacity)
{
	delete[] this->capacity;
	this->capacity = new char[strlen(capacity) + 1];
	for (int i = 0; i < strlen(capacity) + 1; i++)
		this->capacity[i] = capacity[i];
};
void Device::Quantity_minus()
{
	quantity--;
}

void Device::Print()const
{
	cout << "Company : " << company << '\t' << "Model : " << model << '\t' << "Name : " 
		<< name << '\t' << "Capacity : " << capacity << '\t';
};
void Device::Save(FILE* file)const
{
	int size_com = strlen(company) + 1;
	fwrite(&size_com, sizeof(int), 1, file);
	fwrite(company, sizeof(char), size_com, file);
	int size_mod = strlen(model) + 1;
	fwrite(&size_mod, sizeof(int), 1, file);
	fwrite(model, sizeof(char), size_mod, file);
	int size_n = strlen(name) + 1;
	fwrite(&size_n, sizeof(int), 1, file);
	fwrite(name, sizeof(char), size_n, file);
	int size_cap = strlen(capacity) + 1;
	fwrite(&size_cap, sizeof(int), 1, file);
	fwrite(capacity, sizeof(char), size_cap, file);
};
void Device::Load(FILE* file, Device* obj)const
{
	int size_com;
	fread(&size_com, sizeof(int), 1, file);
	char* l_com = new char[size_com];
	fread(l_com, sizeof(char), size_com, file);
	obj->company = l_com;
	l_com = nullptr;
	int size_mod;
	fread(&size_mod, sizeof(int), 1, file);
	char* l_mod = new char[size_mod];
	fread(l_mod, sizeof(char), size_mod, file);
	obj->model = l_mod;
	l_mod = nullptr;
	int size_name;
	fread(&size_name, sizeof(int), 1, file);
	char* l_name = new char[size_name];
	fread(l_name, sizeof(char), size_name, file);
	obj->name = l_name;
	l_name = nullptr;
	int size_cap;
	fread(&size_cap, sizeof(int), 1, file);
	char* l_cap = new char[size_cap];
	fread(l_cap, sizeof(char), size_cap, file);
	obj->capacity = l_cap;
	l_cap = nullptr;
};
Device& Device::operator=(const Device& obj)
{
	if (this == &obj)
		return *this;
	this->company = new char[strlen(obj.company) + 1];
	for (int i = 0; i < strlen(obj.company) + 1; i++)
		this->company[i] = obj.company[i];
	this->model = new char[strlen(obj.model) + 1];
	for (int i = 0; i < strlen(obj.model) + 1; i++)
		this->model[i] = obj.model[i];
	this->name = new char[strlen(obj.name) + 1];
	for (int i = 0; i < strlen(obj.name) + 1; i++)
		this->name[i] = obj.name[i];
	this->capacity = new char[strlen(obj.capacity) + 1];
	return *this;
};
Device& Device::operator=(Device&& obj)
{
	if (this == &obj)
		return *this;
	company = obj.company;
	obj.company = nullptr;
	model = obj.model;
	obj.model = nullptr;
	name = obj.name;
	obj.name = nullptr;
	capacity = obj.capacity;
	obj.capacity = nullptr;
	return *this;
};