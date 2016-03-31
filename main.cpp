#include <iostream>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Section.h"

using namespace std;
#DEFINE MAX_SECTIONS 10

Section *Create_Section(string section_name);


void clear_input_buffer()
{
	while (cin.get() != '\n');

}


Address* Create_Address()
{
	string street_address, city, state;
	int zip_code;

	cout << "Street Address: ";
	getline(cin,street_address);

	cout << "City ";
	getline(cin, city);

	cout << "State ";
	getline(cin, state);

	cout << "Zip Code: ";
	cin >> zip_code;

	clear_input_buffer();
	


    Address* address = new Address(street_address,
        city,state,zip_code);
    return address;
}

// Create a Seat_Row with the specified name and 
// specified number of seats,
Seat_Row* Create_Seat_Row(const string seat_row_name,
                          int number_of_seats)
{
    Seat_Row* row = new Seat_Row(seat_row_name);
    for (int i = 1; i <= number_of_seats; ++i)
    {
        Seat* new_seat = new Seat(seat_row_name, i);
        row->Add_Seat(new_seat);
    }
    return row;
}


//Main function for the venue's input. Houses all of the other functions to create and add
//other objects that the venue has (address, seat rows, sections).
Venue* Create_Venue()
{
	string name;
	cout << "Please enter venue information" << endl;
	cout << "Venue Name: ";
	getline(cin, name);

    Address* adr = Create_Address();
    Venue* venue = new Venue(name, *adr);

	for (int i = 0; i < venue->MAX_SEAT_ROWS; i++)
	{
		string row_name;
		int num_seats;

		cout << "Seat Row Name: ";
		getline(cin, row_name);

		if (row_name == "")
			break;
			 
		cout << "Number of seats: ";
		cin >> num_seats;
		clear_input_buffer();
		
		Seat_Row* sr = Create_Seat_Row(row_name, num_seats);
		venue->Add_Seat_Row(sr);
	}

	cout << "Enter seating information:\n";
	cout << "Enter blank for Section name when finished\n\n";


	string section_name;
	for(int = 0; i < MAX_SECTIONS; i++)
	{
		cout << "Enter Section Name: ";
		getline(cin, section_name);
	
		if (section_name == "")
			break;

		Create_Section(section_name);
	}
	
    return venue;
}

void *Create_Section(string section_name)
{
	int NUM_ROWS = 10;
	string row_name;
	int first_seat, last_seat;
	
	for (int i = 0; i < NUM_ROWS; i++)
	{
		cout << "Enter row names and seat number ranges\n";
		cout << "Enter a blank line for row name when finished\n\n";

		cout << "Row name: ";
		getline(cin, row_name);
	
		if (row_name == "")
			break;
	
		cout << "First seat number: ";
		cin >> first_seat;
		clear_input_buffer();
		cout << "Last seat number: ";
		cin >> last_seat;
		clear_input_buffer();
		
		Section* sect = new Section(section_name, row_name, first_seat, last_seat);
		venue->Add_Section(sect);

	}
}

int main()
{

	string venue_name;
    cout << "This is New Venue program\n\n";

    Venue* venue = Create_Venue();
    
    cout << "The new Venue: " << endl;
    
	venue->Display();	//Displays venue


	

    cin.get();   // Hold the window open
    cin.get();
    return 0;
}


