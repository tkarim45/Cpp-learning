#define _CRTDBG_MAP_ALLOC
#include "date.h"

date::date()
{
	time_t now = time(0);
	tm* ltm = new tm();
	localtime_s(ltm,&now);
	Date = ltm->tm_mday;
	Month = 1 + ltm->tm_mon;
	Year = 1900 + ltm->tm_year;
}
date::date(int Date, int Month, int Year)
{
	this->Date = Date;
	this->Month = Month;
	this->Year = Year;
}
void date::set_date(int Date)
{
	this->Date = Date;
}
int date::get_date()
{
	return Date;
}
void date::set_month(int Month)
{
	this->Month = Month;
}
int date::get_month()
{
	return Month;
}
void date::set_year(int Year)
{
	this->Year = Year;
}
int date::get_year()
{
	return Year;
}
ostream& operator<<(ostream& out, const date& d)
{
	out << d.Date << "\\" << d.Month << "\\" << d.Year;
	return out;
}