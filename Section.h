#pragma once
#include "Seat_Row.h"
#include  "Seat.h"

class Section
{
public: 
	//WHAT IS THE MAXIMUM?
	const static int MAX_SEAT_ROWS = 1000;
    const static int MAX_SEAT = 10;

private:
	string section_name;
	string row_name;
	const Seat_Row* seat_rows[MAX_SEAT_ROWS];
	int first_seat;
	int last_seat;
    int number_of_seat_rows;

public:
	Section(string section_name_, string row_name_, int first_seat_, int last_seat_);
	~Section();

	void Add_Seat_Row(const Seat_Row* new_seat_row);
	string getName() const {return section_name;};
	void Display() const;
};

