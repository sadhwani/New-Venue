#include <string.h>
#include <iostream>
#include <cassert>
#include "Venue.h"
#include "Seat_Row.h"
#include “section.h”
using namespace std;

Venue::Venue(const string& name_,
    const Address& address_) :
    name(name_), address(&address_), number_of_seat_rows(0)
{}

void Venue::Add_Seat_Row(const Seat_Row* seat_row)
{
    assert(number_of_seat_rows < MAX_SEAT_ROWS - 1);
    seat_rows[number_of_seat_rows++] = seat_row;
}

void Venue::Add_Section(const Section* section)
{
    assert(number_of_sections < MAX_SECTIONS - 1);
    sections[number_of_sections++] = section;
}

void Venue::Display() const
{
    cout << name << endl;
    address->Display();
    for (int i = 0; i < number_of_seat_rows; ++i)
    {
        const Seat_Row* row = seat_rows[i];
        row->Display();
    }
    
    cout << endl;
    cout << endl;
    cout << "Seating Sections:" << endl;
    for (int i = 0; i < number_of_sections; ++i)
    {
        const Section* section = sections[i];
        section->Display();
    }
}

// Return number of seats
int Venue::Capacity() const
{
    int count = 0;
    for (int i = 0; i < number_of_seat_rows; ++i)
    {
        count += seat_rows[i]->Number_of_Seats();
    }
    return count;
}


