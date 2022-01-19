#include "Date.h"
#include "Time.h"

int main()
{	
	Date d;
	Date b(28, 12, 2022);
	cout << "Today: " << d;
	cout << "Another day: ";
	b.PrintDate();
	cout << "Difference in dates: " << d.operator-(b) << " day\n\n";

	Time t;
	cout << "Now:      ";
	t.PrintTime();
	cout << "\n";
	t.operator+(15);	
	cout << "+ 15 sec: " << t;
	cout << "\n\n";
}
