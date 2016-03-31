#include "Section.h"
#include <cassert>



Section::Section(string section_name_):
	section_name(section_name_), number_of_seats(0)
{}


Section::~Section()
{
}

void Section::Add_Seat(const Seat* new_seat)
{

	assert(number_of_seats < MAX_SEATS);
	seats[number_of_seats++] = new_seat;

}

