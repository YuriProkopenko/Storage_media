#pragma once

class Device
{
	char* company;
	char* model;
	char* name;
	char* capacity;
    static int quantity;
public:
	Device();
	Device(char* company, char* model, char* name, char* capacity);
	Device(const Device& obj);
	Device(Device&& obj);
	virtual ~Device();
	const char* getCompany()const;
	const char* getModel()const;
	const char* getName()const;
	const char* getCapacity()const;
	static int getQuantity();
	static void Quantity_minus();
	void setCompany(const char* company);
	void setModel(const char* model);
	void setName(const char* name);
	void setCapacity(const char* capacity);
	virtual void Print()const abstract;
	virtual void Save(FILE* file)const abstract;
	virtual void Load(FILE* file, Device* obj)const abstract;
	Device& operator=(const Device& obj);
	Device& operator=(Device&& obj);
};
