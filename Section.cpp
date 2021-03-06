#include "Section.h"
#include <cassert>
#include <iostream>
using namespace std;


Section::Section(string section_name_, string row_name_, int first_seat_, int last_seat_):
	section_name(section_name_), row_name(row_name_), first_seat(first_seat_), last_seat(last_seat_), number_of_seat_rows(0)
{}


Section::~Section()
{
}

void Section::Add_Seat_Row(const Seat_Row* new_seat_row)
{

	assert(number_of_seat_rows < MAX_SEAT);
	seat_rows[number_of_seat_rows++] = new_seat_row; //Save a seat row in the array of sections

}

void Section::Display() const{
	
	cout << "Row " << row_name << " Seats " << first_seat << " - " << last_seat << endl;
	cout << endl;
	
}
