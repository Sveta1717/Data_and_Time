// –азработать класс Date,  включающий следующее:
//Х	пол€ day, month, year;
//Х	константный метод char* DayOfWeek() const;
//Х	конструктор по умолчанию Date() (текуща€ дата);
//Х	конструктор с параметрами Date(int day, int month, int year);
//Х	необходимые сеттеры и геттеры дл€ полей;
//Х	метод, возвращающий разницу между двум€ датами в дн€х(перегруженный бинарный оператор Ђ - ї);
//Х	метод изменени€ даты на заданное количество дней(перегруженный бинарный оператор Ђ + ї);
//Х	метод вывода даты на экран void PrintDate();
//Х	перегруженные операции Ђ++ї, Ђ--ї, Ђ > ї, Ђ < ї, Ђ == ї, Ђ != ї.

#include "Date.h"


Date::Date()
{
	time_t t = time(0);
	tm* ltm = localtime(&t);

	day = ltm->tm_mday;
	month = 1 + ltm->tm_mon;
	year = 1900 + ltm->tm_year;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::SetDay(int day)
{
	if (this->day > 31)
	{
		throw "Oops! Incorrect day!\n"; //  не хочет
	}
	if ((month = 1 && day < 32) || (month = 3 && day < 32) || // показываем сколько дней в мес€цах
		(month = 4 && day < 31) || (month = 5 && day < 32) || (month = 6 && day < 31) ||
		(month = 7 && day < 32) || (month = 8 && day < 32) || (month = 9 && day < 31) ||
		(month = 10 && day < 32) || (month = 11 && day < 31) || (month = 12 && day < 32))
	{
		this->day = day;
	}
	if ((month = 2 && day < 29) && (year % 4 != 0 && year % 100 == 0 || year % 400 != 0)) // показываем февраль в обычный год
	{
		this->day = day;
	}
	if ((month = 2 && day < 30) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) // февраль в високосном году
	{
		this->day = day;
	}
}

void Date::SetMonth(int month)
{
	if (month < 0 || month > 12)
	{
		throw "Oops! Incorrect month!\n";
	}
	else
	{
		this->month = month;
	}
}

void Date::SetYear(int year)
{
	this->year = year;
}

void Date::SetDate()
{
	int a = (14 - this->month) / 12;
	int y = this->year + 4800 - a;
	int m = this->month + (12 * a) - 3;
	int data = this->day + ((this->month * 153 + 2) / 5) +
		this->year * 365 + (this->year / 4) - (this->year / 100) +
		(this->year / 400) - 32045;
}

const unsigned short Date::GetDay() const
{
	return day;
}

const unsigned short Date::GetMonth() const
{
	return month;
}

const unsigned short Date::GetYear() const
{
	return year;
}

char* Date::DayOfWeek() const
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int weekday = (day + (31 * m) / 12 + y + y / 4 - y / 100 + y / 400) % 7;
	char* week_day = new char[] { '1', '2', '3', '4', '5', '6', '7' };

	if (weekday == 1)
	{
		weekday = 1;
	}
	return &week_day[weekday];
}


void Date::PrintDate()
{
	cout << ' ' << this->day << '.' << this->month << '.' << this->year << "\n";
	cout << " day of week: " << *DayOfWeek() << ' ' << "\n\n";
}

Date& Date::operator()(int day, int month, int year)
{
	this->SetYear(year);
	this->SetMonth(month);
	this->SetDay(day);
	return *this;
}

int Date::operator- (const Date& second)
{
	if (year == second.GetYear() && month == second.GetMonth()
		&& day == second.GetDay())
	{
		return 0;
	}
	else
	{
		int d1 = (1461 * (GetYear() + 4800 + (GetMonth() - 14) / 12)) / 4 +
			(367 * (GetMonth() - 2 - 12 * ((GetMonth() - 14) / 12))) / 12 -
			3 * ((GetYear() + 4900 + (GetMonth() - 14) / 12) / 100) / 4 + GetDay() - 32075;

		int d2 = (1461 * (second.GetYear() + 4800 + (second.GetMonth() - 14) / 12)) / 4 +
			(367 * (second.GetMonth() - 2 - 12 * ((second.GetMonth() - 14) / 12))) / 12 -
			3 * ((second.GetYear() + 4900 + (second.GetMonth() - 14) / 12) / 100) / 4 + second.GetDay() - 32075;

		int diff = d1 - d2;
		if (diff > 0)
		{
			return diff;
		}
		else
		{
			return diff * (-1);
		}
	}
}

void Date::operator+ (int days)
{

	if (days > 0)
	{
		this->day += days;
	}
}

Date& Date::operator++(int day)
{
	//Date day = *this;
	day++;
	return *this;
}

Date& Date::operator--(int day)
{
	//Date day = *this;
	day--;
	return *this;
}

bool Date::operator <(Date& second)
{
	if (this->year > second.year)
	{
		return false;
	}
	else if (this->year == second.year && this->month > second.month)
	{
		return false;
	}
	else if (this->year == second.year && this->month == second.month && this->day > second.day)
	{
		return false;
	}
	else return true;
}

bool Date::operator >(Date& second)
{
	if (this->year < second.year)
	{
		return false;
	}
	else if (this->year == second.year && this->month < second.month)
	{
		return false;
	}
	else if (this->year == second.year && this->month == second.month && this->day < second.day)
	{
		return false;
	}
	else return true;
}

bool Date::operator ==(Date& second)
{

	return this->day == second.day && this->month == second.month && this->year == second.year ? true : false;
}

bool Date::operator !=(Date& second)
{
	return this->day == second.day && this->month == second.month && this->year == second.year ? false : true;

}

istream& operator>>(istream& is, Date& original)
{
	int day;
	int month;
	int year;
	is >> day >> month >> year;
	original.SetMonth(month);
	original.SetYear(year);
	original.SetDay(day);
	return is;
}
ostream& operator<<(ostream& os, Date& original)
{
	original.PrintDate();
	return os;
}
