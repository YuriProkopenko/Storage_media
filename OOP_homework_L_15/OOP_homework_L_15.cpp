#include <iostream>
#include <conio.h>
#include "Data_carriers_list.h"
#include "DVD_disc.h"
#include "vector.h"
using namespace std;

int main()
{
	Data_carriers_list list;
	int choice = 0;
	int number;
	char* word = new char[100];
	while (choice != 8) {
		system("cls");
		cout << "Menu : " << endl;
		cout << "1.Add device" << endl;
		cout << "2.Delete device" << endl;
		cout << "3.Edit device" << endl;
		cout << "4.Search" << endl;
		cout << "5.Print the list" << endl;
		cout << "6.Save" << endl;
		cout << "7.Load" << endl;
		cout << "8.Exit";
		choice = _getch() - 48;
		switch (choice) {
		case 1:
			list.Add_Device();
			break;
		case 2:
			system("cls");
			cout << "Select the number of device to delete" << endl;
			cin >> number;
			list.Del(number);
			cout << "Done!";
			system("pause>>NUL");
			break;
		case 3:
			system("cls");
			cout << "Select the number of device to edit" << endl;
			cin >> number;
			list.Edit(number);
			break;
		case 4:
			system("cls");
			cout << "Input the model of device to search : ";
			cin >> word;
			cout << endl;
			if (list.Search(word) != 0)
				list.Search(word)->Print();
			else
				cout << "Device not found!";
			system("pause>>NUL");
			break;
		case 5:
			system("cls");
			list.Print();
			system("pause>>NUL");
			break;
		case 6:
			system("cls");
			list.Save();
			break;
		case 7:
			while (choice != 5) {
				system("cls");
				cout << "Which list do you want to download ?" << endl;
				cout << "1.All devices" << endl;
				cout << "2.DVD discs" << endl;
				cout << "3.Portable HD" << endl;
				cout << "4.USB flashes" << endl;
				cout << "5.Cancel";
				choice = _getch() - 48;
				if (choice == 5)
					break;
				else if (choice > 5 || choice < 1) {
					cout << "Wrong command !";
					break;
				}
				list.Load(choice);			
			}
			break;
		}
	}
	return 0;
}