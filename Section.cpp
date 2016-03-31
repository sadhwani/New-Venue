#include "Section.h"
#include <cassert>



Section::Section(string section_name_, string row_name_, first_seat_, last_seat_):
	section_name(section_name_), string row_name_(row_name), first_seat_(first_seat), last_seat_(last_seat), number_of_seat_rows(0)
{}


Section::~Section()
{
}

void Section::Add_Seat_Row(const Seat_Row* new_seat_row)
{

	assert(number_of_seat_rows < MAX_SEATS);
	seat_rows[number_of_seat_rows++] = new_seat_row; //Save a seat row in the array of sections

}

/*
For display(), run through section array, and use the seat row display method to print out each row in a section
cout << "Section " << section_name << endl;
for loop to display all seat_rows in section
*/
void Section::Display() const{
	
	cout << "Section " << section_name << endl;
	
}
