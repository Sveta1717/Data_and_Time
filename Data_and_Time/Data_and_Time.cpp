#include "Date.h"
#include "Time.h"

int main()
{
	Date d;
	Date b(28, 12, 2022);
	d.PrintDate();
	b.PrintDate();
	cout << "Difference in dates: " << d.operator-(b) << " day\n\n";

	Time t;
	t.PrintTime();
	cout << "\n";
	t.operator+(15);
	t.PrintTime();	
	cout << "\n";
}
