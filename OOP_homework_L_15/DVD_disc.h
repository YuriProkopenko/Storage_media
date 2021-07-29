#pragma once
#include "Device.h"

class DVD_disc : public Device
{
	char* dvd_speed;
public:
	DVD_disc();
	DVD_disc(char* company, char* model, char* name, char* capacity, char* dvd_speed);
	DVD_disc(const DVD_disc& obj);
	DVD_disc(DVD_disc&& obj);
	~DVD_disc();
	const char* getDVD_speed() const;
	void setDVD_speed(const char* dvd_speed);
	void Print() const override;
	void Load(FILE* file, Device* obj) const override;
	void Save(FILE* file) const override;
	DVD_disc& operator=(const DVD_disc& obj);
	DVD_disc& operator=(DVD_disc&& obj);
	friend std::istream& operator>>(std::istream& is, DVD_disc& obj);
	friend std::ostream& operator<<(std::ostream& os, const DVD_disc& obj);
};
