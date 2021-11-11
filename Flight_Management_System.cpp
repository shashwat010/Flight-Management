#include <conio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <ctime>
#include <windows.h>
#include "payment.h"
using namespace std;

const vector<string> l_destination = {"LUCKNOW", "DELHI", "CHANDIGARH", "BANGLORE", "CHENNAI"};															   // local Destination
const vector<string> i_destination = {"LONDON", "BERLIN", "DUBAI", "RIYADH", "BEIJING", "PARIS", "CANBERRA", "TOKYO", "WASHINGTON", "DELHI", "ISLAMABAD"}; // International Destination

class Passenger
{
private:
	const int bseats = 10, eseats = 2;

protected:
	string full_name, phone, mealtype, passport, Address, origin, destination, type, datedep;
	int bus, eco, payment;

public:
	int bussiness_pay;
	Passenger(string fullname, string phone_no, string add = "N/A", string pass_no = "N/A", string dd = 000000)
	{
		datedep = dd;
		full_name = fullname;
		Address = add;
		phone = phone_no;
		passport = pass_no;
		bus = bseats;
		eco = eseats;
	}

	virtual bool ldest() = 0;
	virtual bool idest(string pass) = 0;
	virtual void seats() = 0;
	virtual void Meals() = 0;
	virtual void Registration() = 0;
	virtual bool display() = 0;
	virtual void drive() = 0;
};

string datecheck();
class Booking : public Passenger
{
protected:
	int i, j, n, m, k, NoOfSeats, choice;

public:
	Booking(string f, string num, string add, string pass, string dd) : Passenger(f, num, add, pass, dd)
	{
		n = 0;
		m = 0;
	}
	// cout<<"Flight from "<<i_destination[i]<<" to "<<i_destination[j]<<endl;
	static void show(vector<string> location)
	{
		for (int i = 0; i < location.size(); i++)
		{
			cout << "\n\nFlight from " << location[i] << " to:\n";
			for (int j = 0; j < location.size(); j++)
			{
				if (i != j)
					cout << location[j] << '\n';
			}
			Sleep(2000);
		}
	}

	bool ldest()
	{

		cout << endl
			 << "These are the local destinations where we are flying: \n";
		show(l_destination);
	again:
		cout << endl
			 << "Enter your origin(using BLOCK letters): ";
		cin >> origin;
		cout << endl
			 << "Enter your destination(using BLOCK letters): ";
		cin >> destination;
		if (origin == destination)
		{
			cout << "Invalid Origin and Destination Enter again\n";
			goto again;
		}
		else
		{
			if (find(l_destination.begin(), l_destination.end(), origin) != l_destination.end())
				n++;
			if (find(l_destination.begin(), l_destination.end(), destination) != l_destination.end())
				m++;
			if (m == 1 && n == 1)
			{
				payment = lpayment(origin, destination);
				return true;
			}
			return false;
		}
	}

	bool idest(string pass)
	{
		passport = pass;
		cout << endl
			 << "These are the international destinations where we are flying: \n";
		show(i_destination);
	again:
		cout << endl
			 << "Enter your origin(using BLOCK letters): ";
		cin >> origin;
		cout << endl
			 << "Enter your destination(using BLOCK letters): ";
		cin >> destination;
		if (origin == destination)
		{
			cout << "Invalid Origin and Destination Enter again\n";
			goto again;
		}
		else
		{
			if (find(i_destination.begin(), i_destination.end(), origin) != i_destination.end())
				n++;
			if (find(i_destination.begin(), i_destination.end(), destination) != i_destination.end())
				m++;
			if (m == 1 && n == 1)
			{
				payment = ipayment(origin, destination);
				return true;
			}
			return false;
		}
	}

	void seats()
	{
	bus_eco:
		if (bus > 0 && eco > 0)
		{
			cout << endl
				 << "1.Business Class\n2.Economy Class\n";
			k = getch();
			if (k != 49 && k != 50)
			{
				cout << "Error!!!\n";
				goto bus_eco;
			}
			int seatsReam;
			if (k == 49)
			{
				type = "Business";
				payment += bussiness_pay;
				seatsReam = bus;
			}
			else
			{
				type = "Economy";
				seatsReam = eco;
			}
			cout << endl
				 << type << " Class";
			cout << endl
				 << "Price: " << payment << " INR/seat" << endl;
			cout << endl
				 << "Enter the number of seats: ";
			cin >> NoOfSeats;
			payment = (payment * NoOfSeats);
		book:
			if (NoOfSeats <= seatsReam)
			{
				cout << endl
					 << "Seats are booked.\n\n";
				if (type == "Business")
					bus -= NoOfSeats;
				else
					eco -= NoOfSeats;
			}
			else
			{
				cout << endl
					 << "Seats are not available.\n\n";
				cout << "We have only " << seatsReam << " seats available.\n"
					 << endl;
				cout << "Do you wish to book " << seatsReam << " seats.\nPress 1 for YES\nPress 2 for NO\n";
				k = getch();
				if (k == 49)
				{
					NoOfSeats = seatsReam;
					goto book;
				}
				else
				{
					cout << endl
						 << "See you again.\n";
					exit(0);
				}
			}
		}
		else
		{
			cout << endl
				 << "Sorry no seats available\nHave a nice day!";
			exit(0);
		}
	}

	void Meals()
	{
	meal:
		int n;
		cout << endl
			 << "Available meal types:\n1.Vegetarian\n2.Non-Vegetarian\n";
		n = getch();
		if (n == 49)
			mealtype = "Vegetarian";
		else if (n == 50)
			mealtype = "Non Vegetarian";
		else
		{
			cout << "ERROR!!!" << endl;
			goto meal;
		}
	}

	void Registration()
	{
		int tkt;
		tkt = 50 + rand() % (bus + eco);
		type = (k == 49) ? "Business" : "Economy";
		ofstream outfile;
		outfile.open(full_name + ".txt");
		outfile << "|TICKET INFORMATION:" << endl
				<< endl
				<< "Name: " << full_name << endl
				<< "Phone: " << phone << endl
				<< "Address: " << Address << endl
				<< "Passport Number: " << passport << endl
				<< "Origin: " << origin
				<< endl
				<< "Destination: " << destination
				<< endl
				<< "Food: " << mealtype
				<< endl
				<< "Number of Seats: " << NoOfSeats
				<< endl
				<< "Class: " << type
				<< endl
				<< "Date of departure: " << datedep
				<< endl
				<< "Time: 4.00 PM"
				<< endl
				<< "Ticket: HF" << tkt
				<< endl
				<< "Bill(in Indian rupees): " << payment << "/-" << endl;
		outfile.close();
	}

	bool display()
	{
		bool ans;
		system("cls");
		string temp;
		ifstream infile;
		infile.open(full_name + ".txt");
		while (!infile.eof())
		{
			getline(infile, temp);
			cout << temp << endl;
		}
		ans = confirm();
		return ans;
	}

	bool confirm()
	{
		char ch;
	confirm:
		cout << endl
			 << endl
			 << "Do you wish to confirm your ticket?(y/n): ";
		ch = getch();
		if (ch == 'Y' || ch == 'y')
		{
			cout << endl
				 << endl
				 << "|STATUS CONFIRMED";
			ofstream outfile;
			outfile.open(full_name + ".txt", ios::app);
			outfile << endl
					<< "|STATUS CONFIRMED";
			outfile.close();
			return true;
		}
		else if (ch == 'N' || ch == 'n')
		{
			ofstream outfile;
			outfile.open(full_name + ".txt", ios::app);
			outfile << endl
					<< "|BOOKING CANCELLED";
			cout << endl
				 << endl
				 << "|BOOKING CANCELLED"
				 << endl
				 << "Going back to main page";
			outfile.close();
			return false;
		}
		else
		{
			cout << endl
				 << "ERROR!!!";
			goto confirm;
		}
	}

	inline void drive()
	{
		string pick;
		cout << endl
			 << "Please enter your pickup point: ";
		cin.ignore();
		getline(cin, pick);
		cout << endl
			 << endl
			 << "Pickup Location: " << pick;
		cout << endl
			 << "Drop Off: " << origin << " Airport"
			 << endl
			 << "Fare: 300/-";
		cout << endl
			 << endl
			 << "You will be contacted by our driver shortly\nHave a nice day!";
		fstream ofile;
		ofile.open(full_name + ".txt", ios::app);
		ofile << endl
			  << endl
			  << "Pick'n Drop: YES" << endl
			  << endl
			  << "Pickup Location: " << pick
			  << endl
			  << "Drop Off: " << origin << " Airport"
			  << endl
			  << "Fare: 300/-";
		ofile.close();
	}
};

class Manage
{
private:
	string temp, y, c2;
	int option;

public:
	int change(string full_name)
	{
		int i = 0;

		ifstream file(full_name + ".txt");
		if (file.is_open())
		{
			cout << endl
				 << "Enter your Ticket Number or Press 0 to exit\nTicket Number: ";
			cin >> temp;
			if (temp == "0")
				return 1;
			string v("Ticket: " + temp);

			while (!file.eof())
			{
				getline(file, y);
				if (y == v)
				{
					file.seekg(0, ios::beg);
					while (!file.eof())
					{
						getline(file, temp);
						cout << temp << endl;
					}
					cout << endl
						 << endl
						 << "1.Change date\n2.Cancel the flight\n3.Go Back\n";
					option = getch();
					switch (option)
					{
					case 49:
					{
						file.seekg(0, ios::beg);
						ofstream ofile("temp.txt");
						c2 = datecheck();
						string c1("Date of departure: " + c2);
						while (!file.eof())
						{
							getline(file, y);
							if (i == 11)
							{
								i++;
								ofile << c1 << endl;
							}
							else
							{
								i++;
								ofile << y << endl;
							}
						}
						file.close();
						ofile.close();
						ofstream outfile;
						outfile.open(full_name + ".txt");
						ifstream readfile("temp.txt");
						while (!readfile.eof())
						{
							getline(readfile, y);
							outfile << y << endl;
						}
						outfile.close();
						readfile.close();
						remove("temp.txt");
						cout << endl
							 << "Date Changed!\n\n";
						break;
					}

					case 50:
					{
						file.close();
						ofstream ofli;
						ofli.open(full_name + ".txt", ios::trunc);
						ofli.close();
						system("cls");
						cout << endl
							 << "Booking cancelled!\n\n";
						return 1;
						break;
					}
					case 51:
						system("cls");
						return 1;
					}
				}
			}
		}
		else if (!file.is_open())
		{
			cout << endl
				 << endl
				 << "Unable to find any record" << endl;
			cout << endl
				 << "Going back to main page...\n\n";
			file.close();
			return 1;
		}
		return 0;
	}
};

class About
{
public:
	void Aboutus()
	{
		cout << "The height of skies was first touched by our airline in 1969. Since then,\nHigh Fly is the world's leading airline with 4 biggest airplanes.\nWe are at the customers high service in cuisine, comfort and care.\nSo make a plan and fly high with High Fly." << endl
			 << endl;
		cout << "Press any key to continue...";
		getch();
	}
};

class Complain
{
private:
	string full_name, p_num;
	int choice;
	string sentence;
	string types;
	char ch;

public:
	Complain(string fullname, string num)
	{
		full_name = fullname;
		p_num = num;
	}

	void type()
	{
	back:
		cout << endl
			 << endl
			 << "Enter the type of Complain you want to register:\n1.Airport Handling\n2.Baggage Delivery\n3.Booking and ticketing\n4.Other\n";
		choice = getch();
		cin.ignore();
		cout << "Enter your Complain:\n";
		if (choice == 49)
		{
			cout << "Airport Handling: ";
			types = "Aiprort Handling: ";
		}
		else if (choice == 50)
		{
			cout << "Baggage Delivery: ";
			types = "Baggage Delivery: ";
		}
		else if (choice == 51)
		{
			cout << "Booking and Ticketing: ";
			types = "Booking and Ticketing: ";
		}
		else if (choice == 52)
		{
			cout << "Other: ";
			types = "Other: ";
		}
		getline(cin, sentence);
		cout << endl
			 << "Do you want to edit your Complain(y/n): ";
		ch = getch();
		if (ch == 'Y' || ch == 'y')
			goto back;
		else
		{
			cout << endl
				 << "Complain noted!\n";
			ofstream outfile;
			outfile.open("complain.txt");
			outfile << "Name: " << full_name << endl
					<< "Phone: " << p_num << endl
					<< "Complain:\n"
					<< types << sentence;
			outfile.close();
		}
	}
};

class Routes
{
public:
	bool print()
	{
		int i, j;
		char ch;
		cout << "\n\n\n\n\tFollowing are the international flights available" << endl;
		Booking::show(i_destination);
		for (i = 0; i < 11; i++)
			cout << "\n\n\n\n\tFollowing are the local flights available" << endl;
		Booking::show(l_destination);
		cout << endl
			 << "Do you want to book a flight(y/n) ";
		ch = getch();
		if (ch == 'Y' || ch == 'y')
		{
			cout << endl
				 << endl;
			return true;
		}
		return false;
	}
};

string name()
{
	string full_name;
	cout << "Enter Your Full Name: ";
	cin.ignore();
	getline(cin, full_name);
	return full_name;
}

string phone()
{
	string phone_no;
phone1:
	cout << "Enter Your Phone Num(With Country Code +): ";
	cin >> phone_no;
	if (phone_no.size() < 10)
		goto phone1;
	for (int i = 0; i < phone_no.size(); i++)
		if (!(phone_no[i] >= '0' && phone_no[i] <= '9'))
			goto phone1;
	return phone_no;
}

int main()
{
	cout << "\n\t\t\t\t\tOOPS INNOVATIVE PROJECT\n\n\t\t\t\t\tFLIGHT MANAGEMENT SYSTEM\n"
		 << endl;
	cout << "\t\t\t\t\t\tMADE BY\n\t\t\t\t\tSAURABH MANCHANDA : 2K20/SE/122\n\t\t\t\t\tSHASHWAT JAIN : 2K20/SE/126" << endl;
	cout << endl
		 << "\n\n\n\t\t\t\t\tWelcome to DTU Airlines" << endl;
	cout << "\nPress any key to continue " << endl;
	getch();
	char Username[15];
	char Password[15];
	char Epwd;
	int true1 = 1;
	int try1 = 0;
	int i = 0;
	do
	{
		system("cls");
		cout << "\n\n\n\n\n\n";
		int a;
		cout << "\t\t\t\t    ----------------------------------------\n";
		cout << "\t\t\t\t    |       FLIGHT MANAGEMENT SYSTEM       |\n";
		cout << "\t\t\t\t    ----------------------------------------\n";
		cout << "\n\n";
		cout << "\t\t\t\t\t";
		cout << "Username : ";
		cin >> Username;
		cout << "\t\t\t\t\t";
		cout << "\n";
		cout << "\t\t\t\t\t";
		cout << "Password : ";
		for (i = 0;;)
		{
			Epwd = getch();
			if ((Epwd >= 'a' && Epwd <= 'z') || (Epwd >= 'A' && Epwd <= 'Z') || (Epwd >= '0' && Epwd <= '9'))
			{
				Password[i] = Epwd;
				++i;
				cout << "*";
			}
			if (Epwd == '\b' && i >= 1)
			{
				cout << "\b \b";
				--i;
			}
			if (Epwd == '\r')
			{
				Password[i] = '\0';
				break;
			}
		}

		if (strcmp(Username, "admin") == 0 && strcmp(Password, "pass") == 0)
		{
			cout << "\n\n";
			cout << "\t\t\t\t";
			cout << "You are accessed to the system!\n\n";
			cout << "\t\t\t\t";
			system("pause");
			system("cls");
			true1 = 0;
			try1 = 4;
		}
		else
		{
			system("cls");
			try1 = try1 + 1;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			cout << "No. of attempts remain: " << 3 - try1;
			cout << "\n\n";
			cout << "\t\t\t\t";
			system("pause");

			if (try1 >= 3)
			{
				cout << "\t\t\t\t\t\t";
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "No permission to enter the system!\n\n";
				cout << "\t\t\t\t";
				system("pause");
				exit(0);
			}
		}
	} while (try1 < 3);
	string full_name, add, pass_no, phone_no, datedep;
	int choice;
	bool ans;
	char ch;
back2menu:
	cout << ">>>>>>>>>>MENU<<<<<<<<<<<" << endl;
	cout << endl
		 << "Press 1 for Booking" << endl
		 << "Press 2 for Routes" << endl
		 << "Press 3 for Complaint" << endl
		 << "Press 4 for About" << endl
		 << "Press 5 for Manage" << endl
		 << "Press 0 for Exit\n";
	ch = getch();
	system("cls");
	switch (ch)
	{
	case 49:
	{
	my:
		cout << ">>>>>>>>>>BOOKING<<<<<<<<<<<" << endl;
		Passenger *ptr;
		full_name = name();
		cout << "Enter Your Address(Using Commas only): ";
		getline(cin, add);
		phone_no = phone();
		datedep = datecheck();
		Booking obj1(full_name, phone_no, add, pass_no, datedep);
		ptr = &obj1;
	back:
		cout << endl
			 << "1.Local Destination\n2.International Destination\n3.Back\n4.Exit\n";
		choice = getch();
		bool b;
		if (choice == 49)
		{
			obj1.bussiness_pay = 1000;
			b = ptr->ldest();
		}
		else if (choice == 50)
		{
			obj1.bussiness_pay = 5000;
			cout << endl
				 << "Enter Your Passport Num(Without \"-\"): ";
			cin >> pass_no;
			b = ptr->idest(pass_no);
		}
		else if (choice == 51)
		{
			system("cls");
			goto back2menu;
		}
		else
			exit(0);
		if (!b)
		{
			cout << endl
				 << "We donot fly to this place\nPlease Choose again\n";
			goto back;
		}
		else
		{
			cout << endl
				 << "Yes we do fly\n";
			ptr->seats();
			ptr->Meals();
			ptr->Registration();
			system("cls");
			ans = ptr->display();
			if (ans == false)
			{
				system("cls");
				goto back2menu;
			}
			else if (ans == true)
			{
				cout << endl
					 << "Thanks for Flying With Us" << endl
					 << endl
					 << "Would you like to avail our Pick'n Drop facility?(y/n):";
				cin.ignore();
				ch = getch();
				if (ch == 'y' || ch == 'Y')
					ptr->drive();
				else if (ch == 'n' || ch == 'N')
				{
					ofstream ofile;
					ofile.open(full_name + ".txt", ios::app);
					ofile << endl
						  << endl
						  << "Pick'n Drop: NO";
					ofile.close();
				}
				getch();
				system("cls");
				goto back2menu;
			}
		}
		break;
	}

	case 50: // choice = 2
	{
		cout << ">>>>>>>>>>ROUTES<<<<<<<<<<<\n";
		Routes obj;
		ans = obj.print();
		if (ans == true)
			goto my;
		else if (ans == false)
		{
			cout << endl;
			system("cls");
			goto back2menu;
		}
		break;
	}

	case 51: // choice = 3
	{
		cout << ">>>>>>>>>>COMPLAINT<<<<<<<<<<<\n";
		full_name = name();
		phone_no = phone();
		Complain comp(full_name, phone_no);
		comp.type();
		system("cls");
		goto back2menu;
		break;
	}

	case 52: // choice = 4
	{
		cout << "\t\t>>>>>>>>>>ABOUT US<<<<<<<<<<<\n";
		About abt;
		abt.Aboutus();
		system("cls");
		goto back2menu;
		break;
	}
	case 53:
	{
		cout << ">>>>>>>>>>MANAGE<<<<<<<<<<<\n";
		Manage man;
		cout << full_name;
		man.change(full_name);
		goto back2menu;
	}

	case 48: // choice = 0
	{
		exit(0);
	}

	default:
		cout << endl
			 << endl
			 << "ERROR!!!";
		goto back2menu;
	}
	return 0;
}

string datecheck()
{
	string datedep;
date:
	if (datedep != "")
		cout << "Wrong Date entered.Please enter correct date.\n";
	cout << "Enter date of departure(DDMMYYYY): ";
	cin >> datedep;
	time_t tim = time(0);
	tm *gottime = localtime(&tim);
	int year = datedep[7] - '0' + (datedep[6] - '0') * 10 + (datedep[5] - '0') * 100 + (datedep[4] - '0') * 1000, month = datedep[3] - '0' + (datedep[2] - '0') * 10, day = datedep[1] - '0' + (datedep[0] - '0') * 10;
	if ((1900 + gottime->tm_year) > year)
	{
		cout << year << " " << 1900 + gottime->tm_year;
		goto date;
	}
	if ((1900 + gottime->tm_year) < year)
		return datedep;
	if ((1 + gottime->tm_mon) > month)
		goto date;
	if ((1 + gottime->tm_mon) < month)
		return datedep;
	if (gottime->tm_mday <= day)
		return datedep;
	goto date;
}
