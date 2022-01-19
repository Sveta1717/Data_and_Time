// –азработать класс Time, включающий следующее :
//Х	пол€ seconds, minutes, hours;
//Х	константный метод char* TimeOfDay() const;
//Х	конструктор по умолчанию Time() (текущее врем€);
//Х	конструктор с параметрами Time(int day, int month, int year);
//Х	необходимые сеттеры и геттеры дл€ полей;
//Х	метод изменени€ времени на заданное количество секунд(перегруженный бинарный оператор Ђ + ї);
//Х	метод вывода времени на экран void PrintTime();
//Х	перегруженные операции Ђ++ї, Ђ--ї, Ђ > ї, Ђ < ї, Ђ == ї, Ђ != ї.

#include"Time.h"


Time::Time()
	{
		time_t t = time(0);
		tm* ltm = localtime(&t);

		seconds = 1 + ltm->tm_sec;
		minutes = ltm->tm_min;
		hours = ltm->tm_hour;		
	}
Time::Time(int hours, int minutes, int seconds)
	{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	}
	
	void Time::SetHours(unsigned short hours)
	{
		if (hours > 23)
			this->hours = 0;
		else this->hours = hours;
	}

	void Time::SetMinutes(unsigned short minutes)
	{
		if (minutes > 59)
			this->minutes = 0;
		else this->minutes = minutes;
	}

	void Time::SetSeconds(unsigned short seconds)
	{
		if (seconds > 59)
			this->seconds = 0;
		else this->seconds = seconds;
	}

	void Time::PrintTime()
	{
		cout << hours << ':';
		if (minutes < 10)
			cout << 0;
		cout << minutes << ':';
		if (seconds < 10)
			cout << 0;
		cout << seconds;
	}

	int Time::GetSeconds()
	{
		return this->seconds;
	}

	int Time::GetMinutes()
	{
		return this->minutes;
	}

	int Time::GetHours()
	{
		return this->hours;
	}

	Time& Time::operator()(int hours, int minutes, int seconds)
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
		return *this;
	}

	Time& Time::operator+(int seconds)
	{
		SetSeconds(this->seconds + seconds % 60);
		SetMinutes(this->minutes + (seconds / 60) % 60);
		SetHours(this->hours + (seconds / 3600));
		return *this;
	}

	Time& Time::operator++()
	{
		SetSeconds(this->seconds + 1);
		return *this;
	}

	Time& Time::operator++(int a)
	{
		Time temp = *this;
		SetSeconds(this->seconds + 1);
		return temp;
	}

	Time& Time::operator--()
	{
		if (this->seconds == 0)
		{
			if (this->minutes == 0)
			{
				if (this->hours == 0)
				{
					this->hours = 24;
				}
				this->hours--;
				this->minutes = 60;
			}
			this->minutes--;
			seconds = 60;
		}
		seconds--;
		return *this;
	}

	bool Time::operator>(Time& second)
	{
		if (this->hours > second.GetHours()) return true;
		else if (this->hours == second.GetHours() && this->minutes > second.GetMinutes()) return true;
		else if (this->hours == second.GetHours() && this->minutes == second.GetMinutes() && this->seconds > second.GetSeconds()) return true;
		return false;
	}

	bool Time::operator<(Time& second)
	{
		if (this->hours < second.GetHours()) return true;
		else if (this->hours == second.GetHours() && this->minutes < second.GetMinutes()) return true;
		else if (this->hours == second.GetHours() && this->minutes == second.GetMinutes() && this->seconds < second.GetSeconds()) return true;
		return false;
	}

	bool Time::operator==(Time& second)
	{
		if (this->hours == second.GetHours() && this->minutes == second.GetMinutes() && this->seconds == second.GetSeconds()) return true;
		return false;
	}

	bool Time::operator!=(Time& second)
	{
		return *this == second ? false : true;
	}

	istream& operator>>(istream& is, Time& original)
	{
		int hours;
		int minutes;
		int seconds;
		is >> hours >> minutes >> seconds;
		original.SetHours(hours);
		original.SetMinutes(minutes);
		original.SetSeconds(seconds);
		return is;
	}
	ostream& operator<<(ostream& os, Time& original)
	{
		original.PrintTime();
		return os;
	}
