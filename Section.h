#pragma once
#include "Seat_Row.h"
#include  "Seat.h"
class Section
{
public: 
	//WHAT IS THE MAXIMUM?
	const static int MAX_SEATS = 1000;
private:
	string section_name;
	const Seat* seats[MAX_SEATS];
	int number_of_seats;

public:
	Section(string section_name_);
	~Section();

	void Section::Add_Seat(const Seat* new_seat);
};

