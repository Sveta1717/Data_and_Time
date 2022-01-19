#include "Library.h"

class Time
{
	unsigned short seconds;
	unsigned short minutes;
	unsigned short hours;

public:
	Time();	
	Time(int hours, int minutes, int seconds);	
	void SetHours(unsigned short hours);	
	void SetMinutes(unsigned short minutes);	
	void SetSeconds(unsigned short seconds);
	void PrintTime();	
	int GetSeconds();	
	int GetMinutes();	
	int GetHours();	
	Time& operator+(int seconds);	
	Time& operator++();	
	Time& operator++(int a);	
	Time& operator--();	
	Time& operator()(int hours, int minutes, int seconds);
	bool operator>(Time& second);	
	bool operator<(Time& second);	
	bool operator==(Time& second);	
	bool operator!=(Time& second);		
};

//istream& operator>>(istream& is, Time& original);
ostream& operator<<(ostream& os, Time& original);