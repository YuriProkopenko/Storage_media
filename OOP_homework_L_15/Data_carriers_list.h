#pragma once
#include "vector.h"
#include "DVD_disc.h"
#include "PortableHD.h"
#include "USBflash.h"

class Data_carriers_list
{
	Vector<Device*> array;
public:
	void Add_Device();
	void Del(int number);
	void Edit(int number);
	Device* Search(const char *word);
	void Print();
	void Load(int number);
	//void Load_HD();
	//void Load_USB();
	void Save();
};
