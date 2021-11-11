#include <iostream>
#include <conio.h>
#include <cstring>
#include "payment.h"
#include <fstream>
using namespace std;

const char l_destination[5][20] = {"DELHI", "CHANDIGARH", "LUCKNOW", "BANGLORE", "CHENNAI"};                                                          // local Destination
const char i_destination[11][20] = {"LONDON", "BERLIN", "DUBAI", "RIYADH", "BEIJING", "PARIS", "CANBERRA", "TOKYO", "WASHINGTON", "CANADA", "DELHI"}; // International Destination

class passenger
{
private:
    const int bseats;
    const int eseats;

protected:
    string fullname, phone, mealtype, passport, Address;
    int bus, eco, datedep, payment;
    char origin[30];
    char destination[30];

public:
    // constructor
    passenger(string full_name, string phone_no, string add = "N/A", string pass_no = "N/A", int dd = 000000) : bseats(50), eseats(250)
    {
        datedep = dd;
        fullname = full_name;
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

class booking : public passenger
{
protected:
    int i, j, n, m, k, NoOfSeats, choice;

public:
    booking(string f, string num, string add, string pass, int dd) : passenger(f, add, num, pass, dd)
    {
        n = 0;
        m = 0;
    }

    bool ldest()
    {

        cout << endl
             << "These are the local destinations where we are flying: \n";
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 20; j++)
            {
                cout << l_destination[i][j];
            }
            cout << "\n";
        }
    again:
        cout << endl
             << "Enter your origin(using BLOCK letters): ";
        cin >> origin;
        cout << endl
             << "Enter your destination(using BLOCK letters): ";
        cin >> destination;
        if (strcmp(origin, destination) == 0)
        {
            cout << "Invalid Origin and Destination Enter again\n";
            goto again;
        }
        else
        {
            for (i = 0; i < 5; i++)
            {
                if (strcmp(l_destination[i], origin) == 0)
                    n++;
            }
            for (j = 0; j < 5; j++)
            {
                if (strcmp(l_destination[j], destination) == 0)
                    m++;
            }
            if (m == 1 && n == 1)
            {
                payment = lpayment(origin, destination);
                cout << endl
                     << "Price: " << payment << " Inr/seat" << endl;
                return true;
            }
            else
                return false;
        }
    }

    bool idest(string pass)
    {
        passport = pass;
        cout << endl
             << "These are the international destinations where we are flying: \n";
        for (i = 0; i < 11; i++)
        {
            for (j = 0; j < 20; j++)
            {
                cout << i_destination[i][j];
            }
            cout << "\n";
        }
    again:
        cout << endl
             << "Enter your origin(using BLOCK letters): ";
        cin >> origin;
        cout << endl
             << "Enter your destination(using BLOCK letters): ";
        cin >> destination;
        if (strcmp(origin, destination) == 0)
        {
            cout << "Invalid Origin and Destination Enter again\n";
            goto again;
        }
        else
        {
            for (i = 0; i < 11; i++)
            {
                if (strcmp(i_destination[i], origin) == 0)
                    n++;
            }
            for (j = 0; j < 11; j++)
            {
                if (strcmp(i_destination[j], destination) == 0)
                    m++;
            }
            if (m == 1 && n == 1)
            {
                payment = ipayment(origin, destination);
                cout << endl
                     << "Price: " << payment << " Inr/seat" << endl;
                return true;
            }
            else
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
            switch (k)
            {
            case 49:
            {
                cout << endl
                     << "Business Class";
                cout << endl
                     << "Enter the number of seats: ";
                cin >> NoOfSeats;
                payment = (payment * NoOfSeats) + 5000;
                if (NoOfSeats <= bus)
                {
                    cout << endl
                         << "Seats are available.\n\n";
                    bus = bus - NoOfSeats;
                }
                else
                {
                    cout << endl
                         << "Seats are not available.\n\n";
                    cout << "we have only " << bus << " seats available.\n"
                         << endl;
                    cout << "Do you wish to book remaining seats\nPress 1 for YES\nPress 2 for NO\n";
                    k = getch();
                    if (k == 49)
                    {
                        NoOfSeats = bus;
                        payment = (payment * NoOfSeats) + 5000;
                        cout << "Seats are booked\n\n";
                        bus = 0;
                    }
                    else
                    {
                        cout << endl
                             << "See you again.\n";
                        exit(0);
                    }
                }
                break;
            }

            case 50:
            {
                cout << endl
                     << "Economy Class";
                cout << endl
                     << "Enter the number of seats: ";
                cin >> NoOfSeats;
                payment = (payment * NoOfSeats);
                if (NoOfSeats <= eco)
                {
                    cout << endl
                         << "Seats are available.\n\n";
                    eco = eco - NoOfSeats;
                }
                else
                {
                    cout << endl
                         << "Seats are not available.\n\n";
                    cout << "we have only " << eco << " seats available.\n"
                         << endl;
                    cout << "Do you wish to book remaining seats\nPress 1 for YES\nPress 2 for NO\n";
                    k = getch();
                    if (k == 49)
                    {
                        NoOfSeats = eco;
                        payment = (payment * NoOfSeats);
                        cout << endl
                             << "Seats are booked\n\n";
                        eco = 0;
                    }
                    else
                    {
                        cout << endl
                             << "See you again.\n";
                        exit(0);
                    }
                }
                break;
            }

            default:
            {
                cout << "Error!\n";
                goto bus_eco;
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
        tkt = rand() % 1000;
        if (k == 49)
        {
            ofstream outfile;
            outfile.open("flight.txt");
            outfile << "|TICKET INFORMATION:" << endl
                    << endl
                    << "Name: " << fullname << endl
                    << "Phone: " << Address << endl
                    << "Address: " << phone << endl
                    << "Passport Number: " << passport << endl
                    << "Origin: " << origin
                    << endl
                    << "Destination: " << destination
                    << endl
                    << "Food: " << mealtype
                    << endl
                    << "Number of Seats: " << NoOfSeats
                    << endl
                    << "Class: Business"
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
        else if (k == 50)
        {
            ofstream outfile;
            outfile.open("flight.txt");
            outfile << "|TICKET INFORMATION:" << endl
                    << endl
                    << "Name: " << fullname << endl
                    << "Phone: " << Address << endl
                    << "Address: " << phone << endl
                    << "Passport Number: " << passport << endl
                    << "Origin: " << origin
                    << endl
                    << "Destination: " << destination
                    << endl
                    << "Food: " << mealtype
                    << endl
                    << "Number of Seats: " << NoOfSeats
                    << endl
                    << "Class: Economy"
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
    }

    bool display()
    {
        bool ans;
        system("cls");
        string temp;
        ifstream infile;
        infile.open("flight.txt");
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
            outfile.open("flight.txt", ios::app);
            outfile << endl
                    << "|STATUS CONFIRMED";
            outfile.close();
            return true;
        }
        else if (ch == 'N' || ch == 'n')
        {
            ofstream outfile;
            outfile.open("flight.txt", ios::app);
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
        ofile.open("flight.txt", ios::app);
        ofile << endl
              << endl
              << "Pick'n Drop: YES" << endl
              << endl
              << "Pickup Location: " << pick << endl
              << "Drop Off: " << origin << " Airport" << endl
              << "Fare: 300/-";
        ofile.close();
    }
};

class routes
{
public:
    bool print()
    {
        int i, j;
        char ch;
        cout << "\n\n\n\n\tFollowing are the international flights available" << endl;
        for (i = 0; i < 11; i++)
        {
            cout << endl;
            for (j = 0; j < 11; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    cout << "Flight from " << i_destination[i] << " to " << i_destination[j] << endl;
                }
            }
        }
        cout << "\n\n\n\n\tFollowing are the local flights available" << endl;
        for (i = 0; i < 5; i++)
        {
            cout << endl;
            for (j = 0; j < 5; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    cout << "Flight from " << l_destination[i] << " to " << l_destination[j] << endl;
                }
            }
        }
        cout << endl
             << "Do you want to book a flight(y/n) ";
        ch = getch();
        if (ch == 'Y' || ch == 'y')
        {
            cout << endl
                 << endl;
            return true;
        }
        else
            return false;
    }
};

int main()
{
    cout << "\n\t\t\t\t\tOOPS INNOVATIVE PROJECT\n\n\t\t\t\t\tFLIGHT MANAGEMENT SYSTEM\n"
         << endl;
    cout << "\t\t\t\t\t\tMADE BY\n\t\t\t\t\tSAURABH MANCHANDA : 2K20/SE/122\n\t\t\t\t\tSHASHWAT JAIN : 2K20/SE/126" << endl;
    cout << "\nPress any key to continue " << endl;
    getch();
    cout << endl
         << "\n\n\n\tWelcome to DTU Airlines" << endl;
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
    string full_name, add, pass_no, phone_no;
    int choice, datedep, date, month, year;
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
        passenger *ptr;
        cout << "Enter Your Full Name: ";
        cin.ignore();
        getline(cin, full_name);
        cout << "Enter Your Address(Using Commas only): ";
        getline(cin, add);
        cout << "Enter Your Phone Num(Without -): ";
        cin >> phone_no;
    date:
        cout << "Enter date of departure(DDMMYYYY): ";
        cin >> datedep;
        booking obj1(full_name, phone_no, add, pass_no, datedep);
        ptr = &obj1;
    back:
        cout << endl
             << "1.Local Destination\n2.International Destination\n3.Back\n4.Exit\n";
        choice = getch();

        if (choice == 49)
        {
            if (ptr->ldest() == false)
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
                         << "Would you like to avail our Pick'n Drop facility?(y/n)";
                    ch = getch();
                    if (ch == 'y' || ch == 'Y')
                        ptr->drive();
                    else if (ch == 'n' || ch == 'N')
                    {
                        ofstream ofile;
                        ofile.open("flight.txt", ios::app);
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
        }
        else if (choice == 50)
        {
            cout << endl
                 << "Enter Your Passport Num(Without \"-\"): ";
            cin >> pass_no;
            ans = ptr->idest(pass_no);
            if (ans == false)
            {
                cout << endl
                     << "We donot fly to this place\n";
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
                         << "Would you like to avail our Pick'n Drop facility?(y/n)";
                    ch = getch();
                    if (ch == 'y' || ch == 'Y')
                        ptr->drive();
                    else if (ch == 'n' || ch == 'N')
                    {
                        ofstream ofile;
                        ofile.open("flight.txt", ios::app);
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
        }
        else if (choice == 51)
        {
            system("cls");
            goto back2menu;
        }
        else
            exit(0);
        break;
    }

    case 50: // choice = 2
    {
        cout << ">>>>>>>>>>ROUTES<<<<<<<<<<<\n";
        routes obj;
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
        cout << "Enter Your Full Name: ";
        cin >> full_name;
        cin.ignore();
        cout << "Enter Your Phone Num(Without -): ";
        cin >> phone_no;
        system("cls");
        goto back2menu;
        break;
    }

    case 52: // choice = 4
    {
        cout << "\t\t>>>>>>>>>>ABOUT US<<<<<<<<<<<\n";
        system("cls");
        goto back2menu;
        break;
    }
    case 53:
    {
        cout << ">>>>>>>>>>MANAGE<<<<<<<<<<<\n";
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
