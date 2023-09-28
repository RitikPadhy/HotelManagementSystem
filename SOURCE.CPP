/*
	
	Title			: Hotel Management System
	Language		: C++
	Author			: Ritik Padhy, Eliezer Lopes, Ashwin Kumar, Ashish Konaje
	Date Created	: 01-09-2023
	Last Modified	: 12-09-2023

*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <dos.h>

using namespace std;

void intro() {
    cout << "\n\n\t            ";
    cout << "     C++ Project On Hotel Management System";
    cout << "\n\n\t\t\t\t     MADE BY";
    cout << "\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\tDaljeet Singh Chhabra\t\t\t      ||";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\t\t  \t\t\t\t      ||";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void head() {
    clrscr();
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "\n\t\t\t\t*************";
    cout << "\n\t\t\t\t* MAIN MENU *";
    cout << "\n\t\t\t\t*************";
    cout << "\n\n\n\t\t\t1. Book A Room";
    cout << "\n\t\t\t2. Customer Record";
    cout << "\n\t\t\t3. Rooms Allotted";
    cout << "\n\t\t\t4. Edit Record";
    cout << "\n\t\t\t5. Exit";
    cout << "\n\n\t\t\tEnter Your Choice: ";
}

class Guest {
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    int days;
    float fare;

public:
    Guest() {} // Default constructor

    // Parameterized constructor
    Guest(int roomNo, const char* guestName, const char* guestAddress, const char* guestPhone, int numDays) {
        room_no = roomNo;
        strncpy(name, guestName, sizeof(name));
        strncpy(address, guestAddress, sizeof(address));
        strncpy(phone, guestPhone, sizeof(phone));
        days = numDays;
        fare = days * 900.0; // Default fare per day
    }

    // Copy constructor
    Guest(const Guest& otherGuest) {
        room_no = otherGuest.room_no;
        strncpy(name, otherGuest.name, sizeof(name));
        strncpy(address, otherGuest.address, sizeof(address));
        strncpy(phone, otherGuest.phone, sizeof(phone));
        days = otherGuest.days;
        fare = otherGuest.fare;
    }

    // Friend function to access private members for reporting
    friend void generateReport(const Guest& guest);

    // Function overloading for billing
    void generateBill() {
        cout << "Generating a general bill for " << name << " in room " << room_no << endl;
    }

    void generateBill(const char* preference) {
        cout << "Generating a special bill for " << name << " with preference: " << preference << " in room " << room_no << endl;
    }

    // Destructor
    ~Guest() {
        cout << "Guest " << name << " in room " << room_no << " has checked out. Destructor called." << endl;
    }

    int getRoomNumber() const {
        return room_no;
    }
};

// Function to generate a report for a guest
void generateReport(const Guest& guest) {
    cout << "Generating a report for " << guest.name << " in room " << guest.getRoomNumber() << endl;
}

int main() {
    textbackground(RED);
    textcolor(0);
    clrscr();
    cout << "\n\n\n";
    intro();
    delay(2000);
    clrscr();
    head();

    char id[5], pass[7];
    cout << "\n\n\t\t\t\tusername => ";
    cin >> id;
    cout << "\n\t\t\t\tpassword => ";
    cin >> pass;
    cout << "\n\n\t";
    delay(2000);

    if (strcmp(id, "admin") == 0 && strcmp(pass, "******") == 0)
        cout << "\n\n\t\t\t  !!!Login Successful!!!";
    else {
        cout << "\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
        getch();
        exit(-1);
    }

    clrscr();
    Guest guest1(101, "Alice", "123 Main St", "123-456-7890", 3);
    Guest guest2(102, "Bob", "456 Elm St", "987-654-3210", 5);

    Guest guest3 = guest1; // Copy constructor

    while (1) {
        int choice;
        head();
        cin >> choice;

        switch (choice) {
        case 1: {
            int roomNo;
            const char* name;
            const char* address;
            const char* phone;
            int numDays;
            cout << "\n Enter Customer Details";
            cout << "\n ----------------------";
            cout << "\n\n Room no: ";
            cin >> roomNo;
            cout << " Name: ";
            cin >> name;
            cout << " Address: ";
            cin >> address;
            cout << " Phone No: ";
            cin >> phone;
            cout << " No of Days to Checkout: ";
            cin >> numDays;

            Guest newGuest(roomNo, name, address, phone, numDays);
            newGuest.generateBill();

            break;
        }
        case 2:
            guest1.generateBill("VIP");
            guest2.generateBill("Economy");
            break;
        case 3:
            generateReport(guest1);
            generateReport(guest2);
            break;
        case 4:
            cout << "Edit Record not implemented in this simplified example.";
            break;
        case 5:
            exit(0);
        default:
            cout << "\n\n\t\t\tWrong choice.....!!!";
            cout << "\n\t\t\tPress any key to continue....!!";
            getch();
        }
    }

    return 0;
}

