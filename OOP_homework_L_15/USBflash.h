#pragma once
#include "Device.h"

class USBflash : public Device
{
	char* usb_speed;
public:
	USBflash();
	USBflash(char* company, char* model, char* name, char* capacity, char* usb_speed);
	USBflash(const USBflash& obj);
	USBflash(USBflash&& obj);
	~USBflash();
	const char* getUSB_speed() const;
	void setUSB_speed(const char* usb_speed);
	void Print() const override;
	void Load(FILE* file, Device* obj) const override;
	void Save(FILE* file) const override;
	USBflash& operator=(const USBflash& obj);
	USBflash& operator=(USBflash&& obj);
	friend std::istream& operator>>(std::istream& is, USBflash& obj);
	friend std::ostream& operator<<(std::ostream& os, const USBflash& obj);
};