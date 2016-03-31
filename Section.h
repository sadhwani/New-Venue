#pragma once
#include "Seat_Row.h"
#include  "Seat.h"

class Section
{
public: 
	//WHAT IS THE MAXIMUM?
	const static int MAX_SEAT_ROWS = 1000;
private:
	string section_name;
	const Seat_Row* seat_rows[MAX_SEAT_Rows];
	int number_of_seat_rows;

public:
	Section(string section_name_);
	~Section();

	void Section::Add_Seat_Row(const Seat_Row* new_seat_row);
};

