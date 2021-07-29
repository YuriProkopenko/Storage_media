#pragma once
#include "Device.h"

class PortableHD : public Device
{
	char* HD_speed;
public:
	PortableHD();
	PortableHD(char* company, char* model, char* name, char* capacity, char* HD_speed);
	PortableHD(const PortableHD& obj);
	PortableHD(PortableHD&& obj);
	~PortableHD();
	const char* getHD_speed() const;
	void setHD_speed(const char* dvd_speed);
	void Print() const override;
	void Load(FILE* file, Device* obj) const override;
	void Save(FILE* file) const override;
	PortableHD& operator=(const PortableHD& obj);
	PortableHD& operator=(PortableHD&& obj);
	friend std::istream& operator>>(std::istream& is, PortableHD& obj);
	friend std::ostream& operator<<(std::ostream& os, const PortableHD& obj);
};
