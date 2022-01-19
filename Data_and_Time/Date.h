#include"Library.h"

class Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;

public:
	Date();
	Date(int day, int month, int year);
	//~Date();	

	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void SetDate();
	const unsigned short GetDay() const;
	const unsigned short GetMonth() const;
	const unsigned short GetYear() const;
	char* DayOfWeek() const;
	void PrintDate();
	int operator- (const Date& second);
	void operator+ (int days);
	Date& operator++(int day);
	Date& operator--(int day);
	Date& operator()(int day, int month, int year);	
	bool operator <(Date& second);
	bool operator >(Date& second);
	bool operator ==(Date& second);
	bool operator !=(Date& second);
};

//istream& operator>>(istream& is, Date& original);
ostream& operator<<(ostream& os, Date& original);

